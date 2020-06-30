#include "config.h"
#include <assert.h>
#include <stdio.h>

int main() {
	// Example of usage
	struct config cfg;
	configInit(&cfg);

	printf("Parsing input file: %s\n", "input.txt");
	int status = configRead(&cfg, "input.txt");

	assert(status == 0);

	printf("Success\n");
	configClean(&cfg);

	return 0;
}
