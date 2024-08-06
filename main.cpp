#include "ipc.h"
#include <iostream>

int main() {
    ipc::initialize();

    if (ipc::registerService("ExampleService", 1)) {
        std::cout << "Service registered successfully." << std::endl;
    }

    int serviceId = ipc::lookupService("ExampleService");
    if (serviceId != -1) {
        std::cout << "Service found with ID: " << serviceId << std::endl;
    } else {
        std::cout << "Service not found." << std::endl;
    }

    ipc::finalize();
    return 0;
}
