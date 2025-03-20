#include <string>
#include <iostream>
#include <vector>

int main(){
	std::vector<double> doubles;
	double in;
	while(1) {
		std::cin >> in;
		if (in == 0) break;
		doubles.push_back(in);
	}
	for (auto num : doubles) {
		std::println(std::cout, "{:e} {:f}", num, num);
	}
}
