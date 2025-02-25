#include <cstdio>
#include <iostream>

#include "include/probes/memory.h"
#include "include/probes/probes.h"

int main() {
	char			*buff = {0};
	unsigned long	 size;
	ProbeMemoryFree	 test;
	ProbeMemoryTotal test2;

	size = test2.convert_to_bin(&buff);

	std::cout << size << "\n" << buff << std::endl;

	for (unsigned long i = size; i > 0; i--) {
		printf("%02x", (unsigned char)buff[i]);
	}

	printf("\n");

	return 0;
}
