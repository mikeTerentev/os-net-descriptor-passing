//
// Created by Михаил Терентьев on 2019-06-13.
//

#ifndef OS_NET_DESCRIPTOR_PASSING_CLIENT_H
#define OS_NET_DESCRIPTOR_PASSING_CLIENT_H

#include "utils/wrapper.h"

class client {
public:
    client(std::string login);
    ~client();
    void close_c();
    void make_new_post(std::string message);

private:
    static const int BF_SZ = 2048;

    char* login;
    wrapper socket_fd;
    int gen_fd(int sckt);
};


#endif //OS_NET_DESCRIPTOR_PASSING_CLIENT_H
