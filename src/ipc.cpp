#include "ipc.h"
#include "registry.h"
#include <cstring>

namespace ipc {

void initialize() {
    initializeRegistry();
}

void finalize() {
    finalizeRegistry();
}

bool registerService(const char* name, int id) {
    std::lock_guard<std::mutex> lock(registry->mtx);
    if (registry->serviceCount < 10) {
        std::strcpy(registry->services[registry->serviceCount].name, name);
        registry->services[registry->serviceCount].id = id;
        registry->serviceCount++;
        return true;
    }
    return false;
}

int lookupService(const char* name) {
    std::lock_guard<std::mutex> lock(registry->mtx);
    for (int i = 0; i < registry->serviceCount; ++i) {
        if (std::strcmp(registry->services[i].name, name) == 0) {
            return registry->services[i].id;
        }
    }
    return -1;
}

}
