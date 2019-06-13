//
// Created by Михаил Терентьев on 2019-06-13.
//

#ifndef OS_NET_DESCRIPTOR_PASSING_SERVER_H
#define OS_NET_DESCRIPTOR_PASSING_SERVER_H


class server {

public:
    server();

    [[noreturn]]  void run();

private:
    void process(int fd);

private:
    wrapper socket_fd;
    static const int BF_SZ = 2048;
    static const int LIMIT = 13;
};


#endif //OS_NET_DESCRIPTOR_PASSING_SERVER_H
