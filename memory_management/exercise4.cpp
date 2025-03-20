#include <iostream>

using namespace std;

void fillWithM(string& text) {
	for (auto it = text.begin(); it != text.end(); it++) {
		*it = 'm';
	}
}

int main() {
	string test { "hope hope hope" };
	fillWithM(test);
	print(cout, "{}", test);
}
