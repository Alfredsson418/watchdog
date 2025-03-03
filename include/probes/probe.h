#pragma once

#include <cjson/cJSON.h>
#include <stdio.h>
#include <string.h>

cJSON *json_format();

struct probe {

	enum { STR, U_LONG } type;

	union {
		union {
			unsigned int size;
			char		*value;
		} string;
		unsigned long u_long;
	} value;
};

struct probe_handler_arg {
	unsigned short id;
	struct probe  *data;
};

int probe_data_handler(int sock, struct probe_handler_arg *data);
