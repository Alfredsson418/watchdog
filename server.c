#include "include/probes/memory.h"
#include "include/probes/probes.h"

#include <stdio.h>

int main() {

	printf("%li\n", sysconf(_SC_PAGE_SIZE) * sysconf(_SC_AVPHYS_PAGES));
}
