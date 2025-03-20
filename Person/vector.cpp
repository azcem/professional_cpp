#include "Person.cpp"
#include <ranges>
#include <numeric>
#include <vector>
#include <iostream>

int main() {
	std::vector<std::pair<HR::Person, int>> vec;
	vec.push_back({ {"Assem", "Ahmed"}, 27});
	vec.push_back({ {"Ahmed", "Ahmed"}, 10});
	vec.push_back({ {"Ahmed", "Reda"}, 75});
	vec.push_back({ {"Reda", "Mostafa"}, 45});
	vec.push_back({ {"Assem", "Ahmed"}, 27});
	vec.push_back({ {"Ahmed", "Ahmed"}, 10});
	vec.push_back({ {"Ahmed", "Reda"}, 75});
	vec.push_back({ {"Reda", "Mostafa"}, 45});

	auto ages {
		vec
		| std::views::transform([] (const auto& pair) { return pair.second; })
		| std::views::filter([] (const auto& age) { return age >= 12 && age <= 65; })
		| std::views::common
	};

	for (auto age : ages) std::cout << age << std::endl;

	auto ages_sum {
		std::accumulate(std::begin(ages), std::end(ages), 0)
	};
	std::cout << ages_sum;

	auto persons { vec
		| std::views::transform([] (const auto& pair) { return pair.first; })
		| std::views::take(4)
		| std::views::transform(&HR::Person::get_last_name)
	};

	for (auto person : persons) std::cout << person ;
}
