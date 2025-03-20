
#include <algorithm>
#include <iostream>
#include <ranges>
#include <functional>

int main() {
	auto power = [] (this auto& self, int base, int exp) -> double {
		if (exp == 0) return 1;
		if (exp == 1) return base;
		if (exp > 0) return base * self(base, exp-1);
		return 1 / self(base, -exp);
	};

	auto nums = std::views::iota(-10, 11)
		  | std::views::transform(std::bind(power, std::placeholders::_1, 2));
	std::for_each(nums.begin(), nums.end(), [] (const int num) { std::cout << num << " ";});

}
