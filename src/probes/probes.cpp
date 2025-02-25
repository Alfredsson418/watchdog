#include "../../include/probes/probes.h"

// Add these constructor/destructor definitions
Probe::Probe() {
	// Initialize any base class members if needed
}

Probe::~Probe() {
	// Cleanup if needed
}

unsigned int Probe::get_id() { return this->probe_id; }

unsigned long Probe::convert_to_bin(char **buff) {

	unsigned long size;

	switch (this->tag) {
	case U_INT_TYPE:
		size  = sizeof(unsigned int);
		*buff = (char *)calloc(size, 1);
		if (buff == NULL) {
			return -1;
		}
		std::memcpy(*buff, std::get_if<unsigned int>(&this->value),
					sizeof(unsigned int));
		break;
	case STR_TYPE: {

		std::string	 *string_type = std::get_if<std::string>(&this->value);
		const char	 *str		  = string_type->c_str();
		unsigned long str_len	  = string_type->length();
		size					  = sizeof(str_len) + str_len;
		*buff					  = (char *)calloc(size, 1);
		if (*buff == NULL) {
			return -1;
		}
		std::memcpy(buff, (void *)&str_len, sizeof(str_len));
		std::strncpy(*buff + str_len, str, str_len);
		break;
	}
	case LONG_TYPE:
		size  = sizeof(long);
		*buff = (char *)calloc(sizeof(long), 1);
		if (*buff == NULL) {
			return -1;
		}
		std::memcpy(*buff, std::get_if<long>(&this->value), sizeof(long));
		break;
	default:
		return -1;
	}

	return size;
}

int Probe::load_bin(const char *buff) {
	if (!buff || *buff == '\0') {
		return -1;
	}

	switch (this->tag) {
	case U_INT_TYPE:
		this->value = (unsigned int)std::strtoul(buff, NULL, 10);
		break;
	case STR_TYPE: {

		break;
	}
	default:
		return -1;
	}

	return 1;
}
