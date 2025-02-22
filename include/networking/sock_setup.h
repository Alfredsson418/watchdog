#pragma once

#include <ifaddrs.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdio.h>

#include "../settings.h"

int server_sock_setup();

int client_sock_setup();
