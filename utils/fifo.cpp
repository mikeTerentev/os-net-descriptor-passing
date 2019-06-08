//
// Created by Михаил Терентьев on 2019-06-08.
//

#include "fifo.h"
#include "data_builder.h"

fifo::fifo(std::string const &prefixPath)
        : prefix(prefixPath), pin(prefixPath + "read_fd"), pout(prefixPath + "write_fd") {
    isValid = !((mkfifo(pin.c_str(), S_IRUSR | S_IWUSR | S_IWGRP) == -1)
                ||
                (mkfifo(pout.c_str(), S_IRUSR | S_IWUSR | S_IWGRP) == -1));
}

fifo::~fifo() {
    unlink(pin.c_str());
    unlink(pout.c_str());
}

bool fifo::gen_rw_fd() {
    if (!isValid) {
        return false;
    }
    w_fd = open(pin.c_str(), O_WRONLY);
    r_fd = open(pout.c_str(), O_RDONLY);
    return !(w_fd.isBroken() || r_fd.isBroken());
}

std::string fifo::get_rw_p() { return pin + "@@" + pout + "\r\n"; }


bool fifo::read(std::vector<char> &buffer, size_t const BUFFER_SIZE) {
    data_builder builder;
    auto pr_data = builder.process(r_fd.getDescriptor(), BUFFER_SIZE);
    if (pr_data.first == -1) {
        return false;
    }
    buffer.resize(pr_data.second.size());
    std::copy(pr_data.second.begin(), pr_data.second.end(), buffer.begin());
    return true;
}

bool fifo::write(std::vector<char> buffer) {
    buffer.push_back('\r');
    buffer.push_back('\n');
    size_t processed_sz = 0;
    while (processed_sz < buffer.size()) {
        ssize_t pr_sz =
                ::write(w_fd.getDescriptor(),
                        buffer.data() + processed_sz,
                        buffer.size() - processed_sz);
        if (pr_sz == -1) {
            return false;
        }
        processed_sz += static_cast<size_t>(pr_sz);
    }
    return true;
}

bool fifo::isItrpt(std::vector<char> buffer) {
    buffer.push_back('\0');
    return strcmp(buffer.data(), ":q") == 0 || buffer.size() == 1;
}