#include "Person.cpp"
#include <algorithm>
#include <map>
#include <vector>

class PhoneBook {
public:
	PhoneBook() = default;

	void add_phone_number(HR::Person person, const std::string& number) {
		m_phonebook[person].push_back(number);
	}

	void remove_phone_number(HR::Person person, const std::string& number) {
		auto& numbers = m_phonebook[person];
		numbers.erase(std::find(numbers.begin(), numbers.end(), number));
	}

	std::vector<std::string> get_person_numbers(HR::Person person) {
		return m_phonebook[person];
	}

private:
	std::map<HR::Person, std::vector<std::string>> m_phonebook;
};
