#pragma once

#include <unistd.h>

#include "probes.h"

class ProbeMemoryFree : public Probe {

  public:
	ProbeMemoryFree();
};

class ProbeMemoryTotal : public Probe {

  public:
	ProbeMemoryTotal();
};
