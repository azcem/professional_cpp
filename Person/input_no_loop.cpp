#include <iostream>
#include <iterator>
#include <string>
#include <vector>
#include <ranges>

int main() {
	std::vector<int> vec;

	std::ranges::copy(std::ranges::istream_view<int> { std::cin } 
			| std::views::take_while([] (const int val) { return val != -1; }),
			std::back_inserter(vec));

	std::ranges::copy(vec, std::ostream_iterator<int> {std::cout, " "});
}
