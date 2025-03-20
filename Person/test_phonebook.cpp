#include "PhoneBook.cpp"

int main() {
	PhoneBook phoneBook;
	phoneBook.add_phone_number("Assem Ahmed"_p, "01018639513");
	phoneBook.add_phone_number("Assem Ahmed"_p, "048302347");
	phoneBook.add_phone_number("Mo Salah"_p, "439432049208");
	phoneBook.remove_phone_number("Assem Ahmed"_p, "01018639513");
	auto vec = phoneBook.get_person_numbers("Assem Ahmed"_p);
	for (auto num : vec) std::cout << num;
}
