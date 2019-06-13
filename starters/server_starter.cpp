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
#include <server/server.h>
#include <server/server_exception.h>


int main() {
   server server;
   try{
       server.run();
   } catch (server_exception& e){
       printError(e.what());
   }
}
