#include "iostream"
#include <client/client.h>
#include <client/client_exception.h>
#include <utils/utils.h>


int main() {
    std::string login;
    print("Write your login plz : ");
    std::cin >> login;
    try {
        client client(login);
        while (true) {
            std::string message;
            std::cin >> message;
            if (feof(stdin)) {
                break;
            }
            client.make_new_post(message);
        }
        client.close_c();
    } catch (client_exception &e) {
        printError(e.what());
    }


}
