#include <iostream>
#include <string>
#include <utility>
#include <vector>

template <typename T>
class AssociativeArray {
public:
	AssociativeArray() = default;

	T& operator[](std::string key) {
		for (auto& pair : m_data) {
			if (pair.first == key) {
				return pair.second;
			}
		}
		auto pair = std::make_pair(key, T{});
		m_data.push_back(pair);
		return m_data.back().second;
	}

private:
	std::vector<std::pair<std::string, T>> m_data;
};

int main() {
	AssociativeArray<int> assoc_array = AssociativeArray<int>();

	assoc_array["first"] = 1;
	assoc_array["second"] = 34209;
	std::cout << assoc_array["first"] << std::endl;
	std::cout << assoc_array["second"] << std::endl;
	std::cout << assoc_array["fslkfj"] << std::endl;
}
