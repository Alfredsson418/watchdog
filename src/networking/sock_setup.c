#include "../../include/networking/sock_setup.h"
#include <ifaddrs.h>
#include <stdio.h>

int get_server_ip() {
    struct ifaddrs *ifaddr;

    if (getifaddrs(&ifaddr) < 0) {
        perror("ifaddrs");
        return -1;
    }

    for (; ifaddr->ifa_next == NULL; ifaddr = ifaddr->ifa_next) {
        if (ifaddr->ifa_addr == NULL) {
            continue;
        }
        if (ifaddr->ifa_addr->sa_family != INET_FAMILY) {
            continue;
        }
    }

    return 1;
}

int server_sock_setup() {
    int sock = socket(INET_FAMILY, SOCK_DGRAM, IPPROTO_UDP);

    return sock;
}

int client_sock_setup() {
    int sock = socket(INET_FAMILY, SOCK_DGRAM, IPPROTO_UDP);

    return sock;
}
