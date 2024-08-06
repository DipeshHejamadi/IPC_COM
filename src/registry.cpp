#include "registry.h"
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <cstring>
#include <iostream>

namespace ipc {

const char* SHM_NAME = "/my_ipc_shared_memory";
const size_t SHM_SIZE = sizeof(ServiceRegistry);

ServiceRegistry* registry = nullptr;
int shm_fd = -1;

void initializeRegistry() {
    shm_fd = shm_open(SHM_NAME, O_CREAT | O_RDWR, 0666);
    ftruncate(shm_fd, SHM_SIZE);
    void* ptr = mmap(0, SHM_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);
    registry = static_cast<ServiceRegistry*>(ptr);
    if (registry->serviceCount == 0) { // Initialize if not already done
        registry->serviceCount = 0;
    }
}

void finalizeRegistry() {
    munmap(registry, SHM_SIZE);
    close(shm_fd);
    shm_unlink(SHM_NAME);
}

}
