#include <iterator>
#include <vector>
#include <iostream>
#include <print>

int main() {
	std::vector values {2, 5};
	values.insert(std::begin(values) + 1, {3,4});
	//print
	for (auto element : values) std::cout << element << " ";

	std::vector ints {0,1};
	values.insert(std::begin(values), std::begin(ints), std::end(ints));
	//print
	for (auto element : values) std::cout << element << " ";
	
	std::vector<int> reversed;
	for (auto it = values.crbegin(); it != values.crend(); ++it) reversed.push_back(*it);
	//print
	for (auto element : reversed) std::cout << element << " ";

}
