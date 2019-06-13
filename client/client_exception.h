//
// Created by Михаил Терентьев on 2019-06-08.
//

#ifndef OS_NET_DESCRIPTOR_PASSING_CLIENT_EXCEPTION_H
#define OS_NET_DESCRIPTOR_PASSING_CLIENT_EXCEPTION_H
#include <stdexcept>
#include <cstring>
#include <errno.h>

struct client_exception : std::runtime_error {
    explicit client_exception(std::string const &message) : runtime_error(
            "Client exception: " + message + '\n' + strerror(errno)) {};
};
#endif //OS_NET_DESCRIPTOR_PASSING_CLIENT_EXCEPTION_H