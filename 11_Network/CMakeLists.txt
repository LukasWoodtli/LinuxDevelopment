cmake_minimum_required (VERSION 2.8.7)
project (linux_network)

add_executable(client1 client1.c)

add_executable(server1 server1.c)

add_executable(addr addr.c)

add_executable(hostent hostent.c)

add_executable(servent servent.c)

add_executable(servent2 servent2.c)
add_test(servent2 servent2)

add_subdirectory(parallel_server)

add_subdirectory(select)

add_executable(thserver thserver.c)

add_subdirectory(udp)

add_subdirectory(unix_domain_sockets)

add_subdirectory(multicast)

add_executable(non_block non_block.c)
