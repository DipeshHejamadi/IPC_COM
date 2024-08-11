#include <iostream>
#include "../include/skeleton/offerservice_interface.h"

using namespace ipc;
int main() {
    try {
        std::string serviceName = "IPC";
        sendOfferServiceRequest(serviceName); // Call the API to register a service
        std::cout << "Service registered successfully." << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Failed to register service: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}
