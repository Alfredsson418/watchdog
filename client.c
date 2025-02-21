#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#include "include/probes/memory.h"

#define MAX_PACKET_SEND 4096

int main() {
    char             buffer[MAX_PACKET_SEND] = {0};
    struct memory_t *memory                  = get_mem();

    int sd = socket(AF_INET, SOCK_DGRAM, 0);

    memcpy(buffer, memory, sizeof(*memory));

    struct sockaddr_in serv_addr;
    inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr);
    serv_addr.sin_port   = htons(8124);
    serv_addr.sin_family = AF_INET;

    printf("Total Memory: %li KB\n", memory->total);
    printf("Used Memory: %li KB\n", memory->used);

    sendto(sd, buffer, MAX_PACKET_SEND, 0, (struct sockaddr *)&serv_addr,
           sizeof(serv_addr));

    free(memory);
    return 0;
}
