#include "../../include/probes/memory.h"
#include <iostream>

ProbeMemoryFree::ProbeMemoryFree() {
	this->probe_id = 1;
	this->tag	   = LONG_TYPE;
	this->value	   = sysconf(_SC_AVPHYS_PAGES) * sysconf(_SC_PAGESIZE);
	std::cout << std::get<long>(this->value);
	std::cout << std::endl;
}

ProbeMemoryTotal::ProbeMemoryTotal() {
	this->probe_id = 2;
	this->tag	   = LONG_TYPE;
	this->value	   = sysconf(_SC_PHYS_PAGES) * sysconf(_SC_PAGESIZE);
	std::cout << std::get<long>(this->value);
	std::cout << std::endl;
}
