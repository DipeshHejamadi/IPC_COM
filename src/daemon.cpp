#include "daemon.h"
#include "service_registry.h"
#include <boost/interprocess/ipc/message_queue.hpp>
#include <iostream>

namespace ipc {

void daemonProcess() {
    using namespace boost::interprocess;

    managed_shared_memory segment(open_or_create, "SharedMemory", 65536);
    ServiceRegistry registry(segment);

    message_queue::remove("offer_service_queue");
    message_queue::remove("find_service_queue");

    message_queue offerQueue(open_or_create, "offer_service_queue", 10, sizeof(char[100]));
    message_queue findQueue(open_or_create, "find_service_queue", 10, sizeof(char[100]));

    while (true) {
        char offerBuffer[100];
        size_t received_size;
        unsigned int priority;

        if (offerQueue.try_receive(&offerBuffer, sizeof(offerBuffer), received_size, priority)) {
            std::string serviceName(offerBuffer, received_size);
            registry.registerService(serviceName);
            std::cout << "Service registered: " << serviceName << std::endl;
        }

        char findBuffer[100];
        if (findQueue.try_receive(&findBuffer, sizeof(findBuffer), received_size, priority)) {
            std::string serviceName(findBuffer, received_size);
            bool available = registry.isServiceAvailable(serviceName);
            std::cout << "Service " << (available ? "found" : "not found") << ": " << serviceName << std::endl;
        }
    }
}

} // namespace ipc

int main() {
    ipc::daemonProcess();
    return 0;
}
