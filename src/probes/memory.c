#include "../../include/probes/memory.h"

int fetch_mem_usage(struct probe *data) {
	data->type		   = U_LONG;
	data->value.u_long = sysconf(_SC_AVPHYS_PAGES) * sysconf(_SC_PAGESIZE);
	return 1;
}

int fetch_mem_total(struct probe *data) {
	data->type		   = U_LONG;
	data->value.u_long = sysconf(_SC_PHYS_PAGES) * sysconf(_SC_PAGESIZE);
	return 1;
}
