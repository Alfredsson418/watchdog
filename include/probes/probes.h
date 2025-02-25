#pragma once

#include <string>

#include <cstring> // memcpy
#include <variant>

// Used as an interface for different types of probe types
class Probe {
  protected:
	unsigned int probe_id;

	// Different datatypes for probes
	enum type_tag { U_INT_TYPE, LONG_TYPE, STR_TYPE } tag;

	std::variant<unsigned int, long, std::string> value;

  public:
	Probe();
	virtual ~Probe();

	// Returns the length of buff
	virtual unsigned long convert_to_bin(char **buff);

	// Returns 1 if successful
	virtual int load_bin(const char *buff);

	// Returns the probe id
	virtual unsigned int get_id();
};
