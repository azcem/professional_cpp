#include <algorithm>
#include <vector>
#include <iostream>

int main() {
	std::vector vec{1,2,3,4,5,6,7,8,9,10};
	std::erase_if(vec, [] (const int element) { return element % 2 == 1; });
	std::for_each(vec.cbegin(), vec.cend(), [] (const auto& element) { std::cout << element << " ";});
}
