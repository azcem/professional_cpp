#include <string>
#include <iostream>

int main(){
	std::string s1, s2;
	getline(std::cin, s1);
	getline(std::cin, s2);
	auto result = s1 <=> s2;
	if (result < 0) {
		println(std::cout, "{}", s1);
		println(std::cout, "{}", s2);
	} else {
		println(std::cout, "{}", s2);
		println(std::cout, "{}", s1);
	}
}
