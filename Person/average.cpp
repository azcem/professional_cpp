#include <span>
#include <vector>
#include <ranges>
#include <iostream>

double avg(std::span<double> values) {
	double sum = 0;
	int size = 0;
	for (auto it = values.cbegin(); it != values.cend(); ++it) {
		size++;
		sum += *it;
	}
	return sum / size;
}

int main() {
	double arr[] = {2,2,3};
	std::vector vec {6.0, 2.0, 3.0};
	std::cout << avg(arr) << std::endl;
	std::cout << avg(vec) << std::endl;
	std::cout << avg(vec | std::views::take(2)) << std::endl;
}
