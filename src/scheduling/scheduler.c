#include "../../include/scheduling/scheduler.h"

int start_scheduling() {
	const struct schema_entry *entry = client_schema;
	/*
	for (entry = client_schema; entry->run != 0; entry++) {
		struct probe data;
		entry->run(&data);
		struct probe_handler_arg in;
		in.id	= 0;
		in.data = &data;
		probe_data_handler(0, &in);
	}
	*/
	for (int i = 0; entry->run != 0; i++) {
		struct probe data;
		entry->run(&data);
		struct probe_handler_arg in;
		in.id	= i; // This may not be a good idea
		in.data = &data;
		probe_data_handler(0, &in);

		entry++;
	}
	return 0;
}
