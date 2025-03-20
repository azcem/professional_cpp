#include <iostream>
#include <ranges>
#include <string>
#include <vector>

int main() {
	std::vector<int> vec;
	for (auto value: std::ranges::istream_view<int> {std::cin}
		| std::views::take_while([] (const int val) { return val != -1; })) {
		vec.push_back(value);
	}

	for (int val : vec) {
		std::cout << val << "\n";
	}
}
