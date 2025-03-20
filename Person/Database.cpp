#include "Person.cpp"
#include <filesystem>
#include <fstream>

class Database {
public:
	Database() = default;
	void add(HR::Person&& person) {
		auto lvalue_person = std::move(person);
		add(lvalue_person);
	}

	void add(HR::Person& person) {
		m_persons.push_back(person);
	}

	void save(const std::string& directorypath) const {
		std::filesystem::path directory_path { "./" + directorypath };
		std::filesystem::directory_entry dir_entry { directory_path };
		if (!dir_entry.exists()) {
			std::filesystem::create_directory(dir_entry);
		}
		for (HR::Person person : m_persons) {
			auto filepath = directory_path / (person.get_first_name() + "_" + person.get_last_name() + ".person");
			std::ofstream outfile { filepath };
			person.output(outfile);
		}
	}

	void load(const std::string& directorypath) {
		std::filesystem::path directory_path { "./" + directorypath};
		std::filesystem::directory_entry dir_entry { directory_path };
		std::filesystem::recursive_directory_iterator begin { dir_entry };
		std::filesystem::recursive_directory_iterator end { };
		for (auto iter { begin }; iter != end; iter++) {
			if (iter->path().extension() != ".person") {
				continue;
			}
			std::ifstream infile { iter->path().string() };
			std::string first_name, last_name;
			infile >> std::quoted(first_name);
			infile >> std::quoted(last_name);
			add(HR::Person(first_name, last_name));
		}
	}

	void clear(const std::string& filepath) const {
		std::filesystem::path file_path { "./" + filepath };
		std::ofstream outfile { file_path };
		outfile << "";
	}

	void outputAll() const {
		for (auto person : m_persons) {
			person.output(std::cout);
		}
	}
private:
	std::vector<HR::Person> m_persons;
};

int main() {
	Database db;
	auto person = HR::Person("Lvalue", "Person");
	/*db.add(person);*/
	/*db.add(HR::Person("A ssem", "Ahmed"));*/
	/*db.add(HR::Person("Ahmed", "Ahmed"));*/
	/*db.add(HR::Person("Ahmed", "Reda"));*/
	/*db.add(HR::Person("Reda", "Mostafa"));*/
	db.load("Persons");
	db.outputAll();
}
