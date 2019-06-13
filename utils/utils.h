#ifndef UTILS
#define UTILS

#include <string>
#include <utility>
#include <vector>
#include <utils/wrapper.h>
#include <cstring>
#include <fcntl.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <iostream>

void printError(const std::string &message);

void println(const std::string &message);

void print(const std::string &message);

#endif // UTILS