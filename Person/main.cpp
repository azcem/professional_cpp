#include <iostream>
#include "Person.cpp"

int main() {
	HR::Person person = HR::Person("Assem", "Ahmed");
	std::cout << person;
	HR::Person person2;
	std::cin >> person2;
	std::cout << person2;

	HR::Person p3 = "Assem Ahmed"_p;

	std::string p = person;
	std::cout << p;
}
