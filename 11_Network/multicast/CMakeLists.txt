cmake_minimum_required (VERSION 2.8.7)
project (linux_network)

add_executable(multicast_server multicast_server.c)

add_executable(multicast_client multicast_client.c)

