#include <fstream>
#include <iomanip>
#include <iostream>
#include <ostream>
#include <memory>
#include <sstream>
#include <string>
#include <string_view>
#include <vector>

namespace HR {

class Person {
public:
	Person() = default;

	Person(const std::string& first_name, const std::string& last_name) : 
		Person(first_name, last_name, first_name.substr(0, 1) + last_name.substr(0, 1)) {}
	Person(std::string_view first_name, std::string_view last_name, std::string_view initials):
		m_first_name{ first_name }, m_last_name{ last_name }, m_initials{ initials } {}

	void set_last_name(std::string_view last_name) { m_last_name = last_name ; }
	std::string get_last_name() { return m_last_name; }

	void set_first_name(std::string_view first_name) { m_first_name = first_name ; }
	std::string get_first_name() { return m_first_name; }

	void set_initials(std::string_view initials) { m_initials = initials ; }
	std::string get_initials() { return m_initials; }

	virtual std::string to_string() {
		return m_first_name + " " + m_last_name;
	}

	virtual void output(std::ostream& stream) {
		stream << std::quoted(m_first_name) << " " << std::quoted(m_last_name) << std::endl;
	}

	bool operator<(const Person& rhs) const {
		return m_first_name + m_last_name < rhs.m_first_name + rhs.m_last_name;
	}

	virtual operator std::string() {
		return m_first_name + " " + m_last_name;
	}


private:
	std::string m_first_name, m_last_name, m_initials;
};


class Employee : public Person {
public:
	Employee() = default;
	Employee(const std::string& first_name, const std::string& last_name): Person {first_name, last_name}, m_id{emp_id++} {};
	static int emp_id ;
	std::string to_string() override {
		auto str = Person::to_string();
		return str + " Employee id " + std::to_string(m_id);
	}
private:
	int m_id;
};

int Employee::emp_id = 100;

class Manager : public Employee {
public:
	Manager() = default;
	Manager(const std::string& first_name, const std::string& last_name): Employee {first_name, last_name} {};
	virtual std::string to_string() override {
		auto str = Employee::to_string();
		return str + " Manager";
	}
};

class Director : public Employee {
public:
	Director() = default;
	Director(const std::string& first_name, const std::string& last_name): Employee {first_name, last_name} {};
	virtual std::string to_string() override {
		auto str = Employee::to_string();
		return str + " Director ";
	}
};

std::ostream& operator<<(std::ostream& ostr, Person& person) {
	ostr << person.get_first_name() << " " << person.get_last_name();
	return ostr;
}

std::istream& operator>>(std::istream& istr, Person& person) {
	std::string first_name, last_name;
	istr >> first_name >> last_name;
	person.set_first_name(first_name);
	person.set_last_name(last_name);
	return istr;
}

}


HR::Person operator""_p(const char* str, std::size_t len) {
    std::string stdstr(str, len);
    std::istringstream istr(stdstr);
    std::string first_name, last_name;
    istr >> first_name >> last_name;
    return HR::Person(first_name, last_name);
}

