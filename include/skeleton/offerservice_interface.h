#pragma once
#include <string>
#include <boost/interprocess/ipc/message_queue.hpp>
#include <iostream>

namespace ipc {

inline void sendOfferServiceRequest(const std::string& serviceName) {
    using namespace boost::interprocess;

    message_queue mq(open_or_create, "offer_service_queue", 10, sizeof(char[100]));
    mq.send(serviceName.c_str(), serviceName.size(), 0);
    std::cout << "Offer service request sent for: " << serviceName << std::endl;
}

} // namespace ipc
