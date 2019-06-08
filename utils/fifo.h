//
// Created by Михаил Терентьев on 2019-06-08.
//

#ifndef OS_NET_DESCRIPTOR_PASSING_FIFO_H
#define OS_NET_DESCRIPTOR_PASSING_FIFO_H

#include <iostream>
#include <fcntl.h>
#include <sys/stat.h>
#include "wrapper.h"
#include "utils.h"

struct fifo {
    fifo(std::string const &prefixPath);

    ~fifo();

    bool gen_rw_fd();

    std::string get_rw_p();

    bool read(std::vector<char> &buffer, size_t BUFFER_SIZE);

    bool write(std::vector<char> buffer);

    bool isItrpt(std::vector<char> buffer);


private:
    std::string prefix;
    std::string pin;
    std::string pout;
    bool isValid;
    wrapper w_fd;
    wrapper r_fd;
};

#endif //OS_NET_DESCRIPTOR_PASSING_FIFO_H
