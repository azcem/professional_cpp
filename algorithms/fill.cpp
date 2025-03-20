#include <ranges>
#include <vector>
#include <algorithm>
#include <iostream>

int main() {
	std::cout << "input a number\n";
	int num;
	std::cin >> num;
	std::vector<int> nums_ranges(10), nums_std(10);
	std::ranges::fill(nums_ranges, num);
	std::for_each(nums_ranges.begin(), nums_ranges.end(), [] (const auto num) {std::cout << num << ' ';});
	std::cout << std::endl;
	std::fill(nums_std.begin(), nums_std.end(), num);
	std::for_each(nums_std.begin(), nums_std.end(), [] (const auto num) {std::cout << num << ' ';});
	std::cout << std::endl;

}
