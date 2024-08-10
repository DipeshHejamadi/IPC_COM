#include "service_registry.h"

namespace ipc {

ServiceRegistry::ServiceRegistry(boost::interprocess::managed_shared_memory& segment) {
    serviceList = segment.find_or_construct<std::vector<std::string>>("ServiceList")();
}

void ServiceRegistry::registerService(const std::string& serviceName) {
    serviceList->push_back(serviceName);
}

bool ServiceRegistry::isServiceAvailable(const std::string& serviceName) const {
    return std::find(serviceList->begin(), serviceList->end(), serviceName) != serviceList->end();
}

} // namespace ipc
