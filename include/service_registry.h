#pragma once
#include <string>
#include <vector>
#include <boost/interprocess/managed_shared_memory.hpp>

namespace ipc {

class ServiceRegistry {
public:
    ServiceRegistry(boost::interprocess::managed_shared_memory& segment);
    void registerService(const std::string& serviceName);
    bool isServiceAvailable(const std::string& serviceName) const;

private:
    std::vector<std::string>* serviceList;
};

} // namespace ipc
