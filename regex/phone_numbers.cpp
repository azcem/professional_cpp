#include <regex>
#include <iostream>
#include <string>

int main() {
	std::regex r { R"((\d{3})\-(\d{3})\-(\d{4}))" };
	std::string phone_number;
	while (std::getline(std::cin, phone_number)) {
		const std::sregex_token_iterator iterEnd;
		for (std::sregex_token_iterator it {phone_number.cbegin(), phone_number.cend(), r, {1,2,3}}; it != iterEnd; ++it) {
			std::cout << it->str() << std::endl;
		}
	}


}
