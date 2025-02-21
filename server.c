#include <arpa/inet.h>
#include <asm-generic/socket.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#include "include/probes/memory.h"

#define MAX_PACKET_RECV 4096

int main() {
    int sd = socket(AF_INET, SOCK_DGRAM, 0);

    struct sockaddr_in serv_addr;
    struct sockaddr_in client_addr;
    socklen_t          client_size = 0;
    inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr);
    serv_addr.sin_port   = htons(8124);
    serv_addr.sin_family = AF_INET;

    int res = bind(sd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));

    while (1) {
        char buffer[MAX_PACKET_RECV];
        if (recvfrom(sd, buffer, MAX_PACKET_RECV, 0,
                     (struct sockaddr *)&client_addr, &client_size) <= 0) {
            break;
        }
        struct memory_t memory;
        memcpy(&memory, buffer, sizeof(memory));
        printf("Total Memory: %li KB\n", memory.total);
        printf("Used Memory: %li KB\n", memory.used);
    }

    close(sd);

    return 0;
}
