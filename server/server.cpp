//
// Created by Михаил Терентьев on 2019-06-13.
//
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <sys/stat.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include <iostream>
#include <utils/utils.h>
#include "server.h"
#include "server_exception.h"

static const char *SCKT_NM = "/tmp/socket";

server::server() {

    struct sockaddr_un sockaddr{};

    socket_fd = socket(AF_UNIX, SOCK_STREAM, 0);
    if (socket_fd.isBroken()) {
        throw server_exception("Unable to create socket");

    }
    if (unlink(SCKT_NM) == -1 && errno != ENOENT) {
        throw server_exception("Unable to unlink socket");
    }

    memset(&sockaddr, 0, sizeof(struct sockaddr_un));
    sockaddr.sun_family = AF_UNIX;
    strncpy(sockaddr.sun_path, SCKT_NM, sizeof(sockaddr.sun_path) - 1);
    if (bind(socket_fd.getDescriptor(), (struct sockaddr *) &sockaddr, sizeof(struct sockaddr_un)) == -1) {
        throw server_exception("Unable to bind to socket");
    }
    if (listen(socket_fd.getDescriptor(), LIMIT) == -1) {
        throw server_exception("Unable to listen on socket");
    }

}

[[noreturn]] void server::run() {
    println(":::>VK NEWS FEED<:::");
    int client_fd;
    while ((client_fd = accept(socket_fd.getDescriptor(), nullptr, nullptr)) != -1) {
        process(client_fd);
    }
    throw server_exception("Accepting connection error");
}


void server::process(int socket) {
    char buffer[CMSG_SPACE(sizeof(int))];
    char dup[BF_SZ];
    memset(buffer, '\0', sizeof(buffer));
    struct iovec io = {.iov_base = &dup, .iov_len = sizeof(dup)};
    struct msghdr message{};
    message.msg_iovlen = 1;
    message.msg_iov = &io;
    message.msg_controllen = sizeof(buffer);
    message.msg_control = buffer;

    struct cmsghdr *cmsghd;
    cmsghd = CMSG_FIRSTHDR(&message);
    cmsghd->cmsg_len = CMSG_LEN(sizeof(int));
    cmsghd->cmsg_level = SOL_SOCKET;
    cmsghd->cmsg_type = SCM_RIGHTS;

    int *fd = (int *) CMSG_DATA(cmsghd);
    *fd = 1;

    if (sendmsg(socket, &message, 0) == -1) {
        printError("Error in sending message");
        exit(EXIT_FAILURE);
    }
}