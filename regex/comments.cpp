#include <regex>
#include <iostream>
#include <string>

int main() {
	std::regex reg { R"(//.*)" };
	std::string code;
	std::getline(std::cin, code, '@');
	const std::sregex_token_iterator end;
	for(std::sregex_token_iterator it {code.cbegin(), code.cend(), reg, -1}; it != end; ++it) {
		std::cout << it->str();
	}
}
