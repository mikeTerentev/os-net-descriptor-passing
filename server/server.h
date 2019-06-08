//
// Created by Михаил Терентьев on 2019-06-08.
//

#ifndef MY_SERVER
#define MY_SERVER

#include <future>
#include <random>
#include <stdexcept>
#include <unordered_set>

#include <cstring>
#include <fcntl.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/un.h>

#include "utils/utils.h"


struct server {
    server(std::string const &path);

    [[noreturn]] void run();

    ~server();

    static constexpr size_t BUFFER_SIZE = 2048;

private:
    const std::string path;
    wrapper socket_fd;

    static constexpr size_t CONNS = 5;

    void fillAddress(sockaddr_un &address, const std::string &path);

    void send_f_response(std::string& response,wrapper& client_fd);
};

#endif
