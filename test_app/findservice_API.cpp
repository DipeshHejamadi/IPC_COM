#include <iostream>
#include "findservice_interface.h"

int main() {
    try {
        bool service_found = findservice(); // Call the API to find the service
        if (service_found) {
            std::cout << "Service found." << std::endl;
        } else {
            std::cout << "Service not found." << std::endl;
        }
    } catch (const std::exception& e) {
        std::cerr << "Failed to find service: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}
