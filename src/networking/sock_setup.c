#include "../../include/networking/sock_setup.h"
#include <netinet/in.h>

int server_sock_setup() {
	int						sd = socket(INET_FAMILY, SOCK_DGRAM, IPPROTO_UDP);
	struct sockaddr_storage server_addr;

	if (INET_FAMILY == AF_INET) {
		struct sockaddr_in *temp = (struct sockaddr_in *)&server_addr;

		inet_pton(AF_INET, INADDR_ANY, &temp->sin_addr);
		temp->sin_port	 = htons(SERVER_PORT);
		temp->sin_family = INET_FAMILY;
	} else if (INET_FAMILY == AF_INET6) {
		struct sockaddr_in6 *temp = (struct sockaddr_in6 *)&server_addr;

		inet_pton(AF_INET6, "::", &temp->sin6_addr);
		temp->sin6_port	  = htons(SERVER_PORT);
		temp->sin6_family = INET_FAMILY;
	}
	if (bind(sd, (struct sockaddr *)&server_addr,
			 INET_FAMILY == AF_INET ? sizeof(struct sockaddr_in)
									: sizeof(struct sockaddr_in6)) < 0) {
		perror("Bind failed");
		return 0;
	}

	return sd;
}

int client_sock_setup() {
	int sock = socket(INET_FAMILY, SOCK_DGRAM, IPPROTO_UDP);

	return sock;
}
