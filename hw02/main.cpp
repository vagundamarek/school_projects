#include "config.hpp"
#include <cassert>

int main() {
	// Example of usage
	Config config;
	auto status = config.read("input.txt");
    config.serialize("output.txt");
	assert(status == Status::Success);

	return 0;
}
