#pragma once

#include <stdlib.h>
#include <unistd.h>

struct memory_t {
	unsigned long total;
	unsigned long used;
};

struct memory_t *get_mem();

long get_memsize();

long get_mem_used();
