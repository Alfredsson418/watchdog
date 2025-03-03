#include "../../include/probes/probe.h"

int probe_data_handler(int sock, struct probe_handler_arg *arg) {
	cJSON *id			= cJSON_CreateNumber(arg->id);
	cJSON *number_value = 0;
	cJSON *string_value = 0;

	cJSON *monitor = cJSON_CreateObject();

	cJSON_AddItemToObject(monitor, "probe_id", id);

	cJSON *data_array = cJSON_CreateArray();

	cJSON_AddItemToObject(monitor, "data", data_array);

	cJSON *data_object = cJSON_CreateObject();

	cJSON_AddItemToArray(data_array, data_object);

	switch (arg->data->type) {
	case U_LONG:
		number_value = cJSON_CreateNumber(arg->data->value.u_long);

		cJSON_AddItemToObject(data_object, "value", number_value);

		break;
	case STR:
		number_value = cJSON_CreateNumber(arg->data->value.string.size);
		string_value = cJSON_CreateString(arg->data->value.string.value);

		cJSON_AddItemToObject(data_object, "size", number_value);
		cJSON_AddItemToObject(data_object, "value", string_value);

		break;
	default:
		fprintf(stderr, "Unsupported data type\n");
	}

	char *string = cJSON_Print(monitor);

	printf("%s\n", string);

end:
	cJSON_Delete(monitor);
	return 0;
}
