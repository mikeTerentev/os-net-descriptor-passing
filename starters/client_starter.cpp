#include "client/client.h"
#include <client/client_exception.h>
int main(int argc, char *argv[]) {
    if (argc != 2) {
        printError("Invalid args : socket_filepath expected");
        return -1;
    }
    try {
        client client(argv[1]);
        println("echo-client started..");
        std::string text;
        while (true) {
            print("echo: ");
            std::getline(std::cin, text);
            if (text == ":q") {
                break;
            }
            println("---> " + client.process_request(text));
        }
    } catch (client_exception &e) {
        printError(e.what());
        return -1;
    }
    return 0;
}
