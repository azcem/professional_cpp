#include <cstdio>
#include <iostream>
#include <string>
#include <string_view>

std::string replace_needle(std::string_view haystack, std::string_view needle, std::string_view replacement){
	std::string result {haystack} ;
	while (1) {
		int ind = result.find(needle);
		if (ind == std::string::npos) break;
		result.replace(ind, replacement.length(), replacement);
	}
	return result;
}

int main() {
	std::string haystack, needle, replacement;
	std::getline(std::cin, haystack);
	std::getline(std::cin, needle);
	std::getline(std::cin, replacement);
	std::cout << replace_needle(haystack, needle, replacement);
}
