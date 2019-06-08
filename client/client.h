#ifndef MY_CLIENT
#define MY_CLIENT

#include <stdexcept>
#include <string>
#include <vector>

#include <arpa/inet.h>
#include <cstring>
#include <fcntl.h>
#include <sys/socket.h>
#include <sys/un.h>

#include "utils/utils.h"

struct client {
    client(std::string const &path);
    ~client();
    std::string process_request(std::string data);

private:
    wrapper r_fd;
    wrapper w_fd;

    static constexpr size_t BUFFER_SIZE = 2048;

    void make_rw_fd(wrapper &socket_fd);

    void fillArddess(sockaddr_un& address, const std::string &path);
};

#endif // MY_CLIENT
