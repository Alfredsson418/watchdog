#pragma once

#include <unistd.h>

#include "probe.h"

int fetch_mem_usage(struct probe *data);

int fetch_mem_total(struct probe *data);
