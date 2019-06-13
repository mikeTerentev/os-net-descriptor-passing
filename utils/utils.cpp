//
// Created by Михаил Терентьев on 2019-06-08.
//
#include <utils/utils.h>

void printError(const std::string &message) {
    std::cerr << message << std::endl;
}

void println(const std::string &message) {
    std::cout << message << std::endl;
}

void print(const std::string &message) {
    std::cout << message;
    std::cout.flush();
}
