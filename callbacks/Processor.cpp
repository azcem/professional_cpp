#include <functional>
#include <iostream>

class Processor {
public:
	Processor(std::function<int(int)> func): m_func {func} {}

	int operator() (int val) {
		return m_func(val);
	}
private:
	std::function<int(int)> m_func;
};

int main() {
	Processor p1 {[] (int val) { return val*2;}};
	Processor p2 {[] (int val) { return val+2;}};
	Processor p3 {[] (int val) { return val+100;}};
	int val = 5;

	std::cout << p1(val) << "\n";
	std::cout << p2(val) << "\n";
	std::cout << p3(val) << "\n";
}
