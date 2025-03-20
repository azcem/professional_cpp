#include <iostream>
#include <ranges>
#include <string>

int main() {
	auto sequence  {
		std::views::iota(10,101)
		| std::views::transform([] (const auto& e) { return e * e; })
		| std::views::filter([] (const auto& e) { return e % 5 != 0; })
		| std::views::transform([] (const auto& e) { return std::to_string(e); })
	};

	for (auto element : sequence) std::cout << element << " ";
	std::cout << std::endl;
}
