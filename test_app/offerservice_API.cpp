#include <iostream>
#include "offerservice_interface.h"

int main() {
    try {
        offerservice(); // Call the API to register a service
        std::cout << "Service registered successfully." << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Failed to register service: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}
