#include <cstddef>
#include <iostream>
#include <memory>

using namespace std;

int main() {
	const size_t numberOfElements { 10 };
	auto values { make_unique<int[]>(10) };

	// Set values to their index value
	for (int index { 0 }; index < numberOfElements; ++index) {
		values[index] = index;
	}

	// Set last value to 99
	values[9] = 99;

	// Print all values
	for (int index { 0 }; index < numberOfElements; ++index) {
		print(cout, "{} ", values[index]);
	}
}
