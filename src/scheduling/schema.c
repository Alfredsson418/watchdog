#include "../../include/scheduling/schema.h"

const struct schema_entry client_schema[] = {
	{"Memory Usage", fetch_mem_usage, 0, 0, 0, 0},
	{"Memory Total", fetch_mem_total, 0, 0, 0, 0},
	{0}
};
