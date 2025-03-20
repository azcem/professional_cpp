#include <iterator>
#include <vector>
#include <set>
#include <algorithm>
#include <iostream>
#include <ranges>

int main() {
	std::vector<int> vec(20);
	auto nextNumber { [counter = 0] () mutable { return ++counter; } };
	std::generate(vec.begin(), vec.end(), nextNumber);
	std::set<int> evens;
	std::set<int, std::greater<>> odds;
	/*std::ranges::partition_copy(vec, evens.begin(), odds.begin(), [] (const int e) { return e % 2 == 0; } );*/
	std::partition_copy(vec.begin(), vec.end(), std::inserter(evens, evens.begin()), std::inserter(odds, odds.begin()), [] (const int e) { 
		return e % 2 == 0; 
	});
	for (auto e : evens) std::cout << e <<" ";
	std::cout << std::endl;
	for (auto e : odds) std::cout << e <<" ";
	std::cout << std::endl;
}
