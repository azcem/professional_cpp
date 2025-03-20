#include <iostream>
#include <ranges>
#include <algorithm>
#include <vector>

int main() {
	std::vector<int> nums;
	int num;
	while (std::cin >> num) nums.push_back(num);

	//constrained
	std::cout << "constrained:\n";
	do {
		std::for_each(nums.begin(), nums.end(), [] (const auto num) { std::cout << num << ' '; });
		std::cout << std::endl;
	} while (std::ranges::next_permutation(nums).found);
	
	//unconstrained
	std::cout << "unconstrained:\n";
	do {
		std::for_each(nums.begin(), nums.end(), [] (const auto num) { std::cout << num << ' '; });
		std::cout << std::endl;
	} while (std::next_permutation(nums.begin(), nums.end()));
}
