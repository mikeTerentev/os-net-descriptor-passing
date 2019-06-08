//
// Created by Михаил Терентьев on 2019-06-08.
//

#include <utils/fifo.h>
#include "server.h"
#include "server/server_exception.h"

server::server(std::string const &path) : path(path), socket_fd(socket(AF_UNIX, SOCK_STREAM, 0)) {
    if (socket_fd.isBroken()) {
        throw server_exception("Unable to create socket");
    }
    sockaddr_un address{};
    fillAddress(address, path);
    if (bind(socket_fd.getDescriptor(), reinterpret_cast<sockaddr *>(&address), sizeof(sockaddr_un)) == -1) {
        throw server_exception("Unable to bind socket");
    }
    if (listen(socket_fd.getDescriptor(), CONNS) == -1) {
        throw server_exception("Unable to listen on socket");
    }
}

[[noreturn]] void server::run() {
    std::uniform_int_distribution<uint64_t> uid;
    std::random_device random_device;
    while (true) {
        sockaddr_un client{};
        socklen_t client_sz;
        wrapper client_fd(accept(socket_fd.getDescriptor(),reinterpret_cast<sockaddr *>(&client),&client_sz));
        if (client_fd.getDescriptor() == -1) {
            throw server_exception("Unable to connection");
        }

        fifo fifo("/tmp/fifo_" + std::to_string(uid(random_device)));
        auto response = fifo.get_rw_p();
        send_f_response(response,client_fd);
        if (!fifo.gen_rw_fd()) {
            throw server_exception("Unable to create pipe");
        }

        while (true) {
            std::vector<char> buffer(BUFFER_SIZE);
            if (!fifo.read(buffer, BUFFER_SIZE)) {
                throw server_exception("Recieving data error");
            }
            if (fifo.isItrpt(buffer)) {
                break;
            }
            if (!fifo.write(buffer)) {
                throw server_exception("Sending data error");
            }
        }
    }
}

server::~server() { unlink(path.c_str()); }

void server::fillAddress(sockaddr_un &address, const std::string &path) {
    memset(&address, 0, sizeof(sockaddr_un));
    address.sun_family = AF_UNIX;
    strcpy(address.sun_path, path.c_str());
}

void server::send_f_response(std::string& response,wrapper& client_fd) {
    size_t processed_sz = 0;
    while (processed_sz < response.size()) {
        ssize_t send_sz = send(client_fd.getDescriptor(),
                               response.data() + processed_sz,
                               response.size() - processed_sz,
                               0);
        if (send_sz == -1) {
            throw server_exception("Unable to send response");
        }
        processed_sz += static_cast<size_t>(send_sz);
    }
}
