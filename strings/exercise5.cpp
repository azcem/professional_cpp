#include <algorithm>
#include <iostream>
#include <vector>

int main() {
	std::string in;
	std::vector<std::string> words;
	while(1) {
		std::cin >> in;
		if (in == "*") break;
		words.push_back(in);
	}
	//find longest word
	int max_size = 0;
	for (auto word : words) {
		if (word.length() > max_size) max_size = word.length();
	}
	for (int i = 0; i < words.size(); i += 5) {
		std::print(std::cout, "|");
		for (auto it = words.begin() + i; it != std::min(words.end(), words.begin() + i + 5); it++) {
			std::print(std::cout, "{:^{}}|", *it, max_size);
		}
		std::println(std::cout, "");
	}

}
