#include <iostream>
#include <algorithm>
#include <cctype>
#include <string>

void trim(std::string& str) {
	auto it = std::find_if(str.begin(), str.end(), [] (const char c) { return std::isalnum(c); });
	if (it != str.begin()) {
		str.erase(str.begin(), it);
	}
	auto it1 = std::find_if(str.rbegin(), str.rend(), [] (const char c) { return std::isalnum(c); });
	if (it1 != str.rbegin()) {
		str.erase(str.begin()+ (str.rend() - it1), str.end());
	}
}

int main() {
	std::string str;
	while(std::getline(std::cin, str)) {
		trim(str);
		std::cout <<'"' << str << '"' << std::endl;
	}
}
