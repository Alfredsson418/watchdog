#pragma once

#include <cjson/cJSON.h>

#include "../probes/memory.h"

struct schema_entry {
	// Function describing name, used in logs
	const char *name;

	// The function to run
	int (*run)(struct probe *);

	/*
	   TIME
		Used to describe when to run
	*/
	unsigned short day;
	unsigned short hour;
	unsigned short min;
	unsigned short sec;
};

extern const struct schema_entry client_schema[];
