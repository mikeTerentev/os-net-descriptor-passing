//
// Created by Михаил Терентьев on 2019-06-13.
//

#include <unistd.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include <iostream>
#include <utils/utils.h>
#include <client/client.h>
#include <client/client_exception.h>

#include "client.h"
#include "client_exception.h"

static const char *SCKT_NM = "/tmp/socket";

client::client(std::string login): login(const_cast<char *>(login.data())) {
    struct sockaddr_un addr{};
    socket_fd = socket(AF_UNIX, SOCK_STREAM, 0);
    if (socket_fd.isBroken()) {
        throw client_exception("Unable to create socket");
    }

    memset(&addr, 0, sizeof(struct sockaddr_un));
    addr.sun_family = AF_UNIX;
    strncpy(addr.sun_path, SCKT_NM, sizeof(addr.sun_path) - 1);
    if (connect(socket_fd.getDescriptor(), (struct sockaddr *) &addr, sizeof(struct sockaddr_un)) == -1) {
        throw client_exception("Unable to connect to socket");
    }
    dup2(gen_fd(socket_fd.getDescriptor()), 1);


}
client::~client(){
    close_c();
}

int client::gen_fd(int sckt) {
    char data[BF_SZ];
    struct iovec io{};
    io.iov_base = &data;
    io.iov_len = sizeof(data);

    char buffer[CMSG_SPACE(sizeof(int))];
    memset(buffer, '\0', sizeof(buffer));
    struct msghdr msghdr{};
    msghdr.msg_iov = &io;
    msghdr.msg_iovlen = 1;
    msghdr.msg_control = buffer;
    msghdr.msg_controllen = sizeof(buffer);

    if (recvmsg(sckt, &msghdr, 0) < 0) {
        throw client_exception("Unable to receive message");
    }
    struct cmsghdr *cmsghd = CMSG_FIRSTHDR(&msghdr);

    int *fd = (int *) CMSG_DATA(cmsghd);
    return *fd;
}

void client::make_new_post(std::string message) {
        printf("[%s]:::> %s\n", login,  const_cast<char *>(message.data()));
}

void client::close_c(){
    if (close(socket_fd.isBroken())) {
        throw client_exception("Closing sock_fd error");
    }
}
