#pragma once

#include <arpa/inet.h>
#include <ifaddrs.h>
#include <netinet/in.h>
#include <stdio.h>
#include <sys/socket.h>

#include "../settings.h"

int server_sock_setup();

int client_sock_setup();
