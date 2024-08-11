#include <iostream>
#include "../include/proxy/findservice_interface.h"

using namespace ipc;
int main() {
    try {
        std::string serviceName = "IPC";
        sendFindServiceRequest(serviceName);
        // bool service_found = sendFindServiceRequest(serviceName); // Call the API to find the service
        // if (service_found) {
        //     std::cout << "Service found." << std::endl;
        // } else {
        //     std::cout << "Service not found." << std::endl;
        // }
    } catch (const std::exception& e) {
        std::cerr << "Failed to find service: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}
