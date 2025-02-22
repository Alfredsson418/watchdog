#pragma once
#include "../probes/probes.h"

struct app_layer_t {
	unsigned int	 id;
	enum probe_types type;
	unsigned int	 data_size;
	void			*data; // Size of len
};
