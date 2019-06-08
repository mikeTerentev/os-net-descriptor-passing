#include <iostream>
#include <server/server_exception.h>
#include <utils/utils.h>
#include <server/server.h>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printError("Invalid args : socket_filepath expected");
        return -1;
    }
    try {
        server server(argv[1]);
        server.run();
    } catch (server_exception& e) {
        printError(e.what());
        return -1;
    }
}
