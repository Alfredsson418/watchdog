#include "../../include/probes/memory.h"

struct memory_t *get_mem() {
    struct memory_t *memory = calloc(sizeof(struct memory_t), 1);
    memory->total           = get_memsize();
    memory->used            = get_mem_used();
    return memory;
}

// man sysconf
long get_memsize() { return sysconf(_SC_PHYS_PAGES) * sysconf(_SC_PAGESIZE); }

long get_mem_used() {
    return sysconf(_SC_AVPHYS_PAGES) * sysconf(_SC_PAGESIZE);
}
