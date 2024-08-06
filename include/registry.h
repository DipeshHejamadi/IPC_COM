#ifndef REGISTRY_H
#define REGISTRY_H

#include <mutex>

namespace ipc {

struct ServiceInfo {
    char name[256];
    int id;
    // Other fields...
};

struct ServiceRegistry {
    std::mutex mtx;
    ServiceInfo services[10];
    int serviceCount;
};

extern ServiceRegistry* registry;

void initializeRegistry();
void finalizeRegistry();

}

#endif // REGISTRY_H
