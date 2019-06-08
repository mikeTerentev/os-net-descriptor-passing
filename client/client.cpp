#include <errno.h>
#include <utils/data_builder.h>
#include "client.h"
#include "client/client_exception.h"

client::client(std::string const &path) {
    wrapper socket_fd(socket(AF_UNIX, SOCK_STREAM, 0));
    if (socket_fd.isBroken()) {
        throw client_exception("Unable to create socket");
    }
    sockaddr_un address{};
    fillArddess(address, path);
    socklen_t address_sz = sizeof(sockaddr_in);
    if (connect(socket_fd.getDescriptor(), reinterpret_cast<sockaddr *>(&address), address_sz) == -1) {
        throw client_exception("Unable to connect to server");
    }
    make_rw_fd(socket_fd);
}

std::string client::process_request(std::string data) {
    data_builder builder;
    data += "\r\n";
    size_t processed_sz = 0;
    while (processed_sz < data.size()) {
        ssize_t cur_sz = write(w_fd.getDescriptor(),
                               data.data() + processed_sz,
                               data.size() - processed_sz);
        if (cur_sz == -1) {
            throw client_exception("Writing request error");
        }
        processed_sz += static_cast<size_t>(cur_sz);
    }
    auto recv_data = builder.process(r_fd.getDescriptor(), BUFFER_SIZE);
    if (recv_data.first == -1) {
        throw client_exception("Reading response error");
    }
    return recv_data.second;
}

void client::make_rw_fd(wrapper &socket_fd) {
    data_builder builder;
    auto processed_data = builder.process(socket_fd.getDescriptor(), BUFFER_SIZE);
    if (processed_data.first == -1) {
        throw client_exception("Connection error");
    }
    std::size_t marker = processed_data.second.find("@@");
    r_fd = open(processed_data.second.substr(0, marker).c_str(), O_RDONLY);
    w_fd = open(processed_data.second.substr(marker + 2).c_str(), O_WRONLY);
    if (r_fd.isBroken() || w_fd.isBroken()) {
        throw client_exception("Descriptors are broken");
    }
}

void client::fillArddess(sockaddr_un &address, const std::string &path) {
    memset(&address, 0, sizeof(sockaddr_in));
    address.sun_family = AF_UNIX;
    strcpy(address.sun_path, path.c_str());
}

client::~client() { process_request(":q"); }
