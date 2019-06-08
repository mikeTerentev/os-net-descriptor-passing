cmake_minimum_required(VERSION 3.12)

project(os-net-descriptor-passing)

include_directories(${PROJECT_SOURCE_DIR})
set(CMAKE_CXX_STANDARD 14)



add_executable(client starters/client_starter.cpp)
add_executable(server  starters/server_starter.cpp)

add_library(server-lib STATIC
        server/server.h
        server/server.cpp
        server/server_exception.h)


add_library(client-lib STATIC
        client/client.h
        client/client.cpp
        client/client_exception.h)


add_library(common STATIC
        utils/data_builder.cpp
        utils/data_builder.h
        utils/fifo.cpp
        utils/fifo.h
        utils/utils.h
        utils/utils.cpp
        utils/wrapper.cpp
        utils/wrapper.h
        )

set_target_properties(common PROPERTIES LINKER_LANGUAGE CXX)
set_target_properties(server-lib PROPERTIES LINKER_LANGUAGE CXX)
set_target_properties(client-lib PROPERTIES LINKER_LANGUAGE CXX)


target_link_libraries(server server-lib common)
target_link_libraries(client client-lib common)
