#include <iostream>
#include <memory>

using namespace std;

class Point {
public:
	Point(double x, double y, double z)  { m_x = x; m_y = y; m_z = z; }
	double get_x() { return m_x; }
	double get_y() { return m_y; }
	double get_z() { return m_z; }
private:
	double m_x, m_y, m_z;
};

void print_point(Point& p) {
	print(cout, "({}, {}, {})", p.get_x(), p.get_y(), p.get_z());
}
int main() {
	auto point = make_unique<Point>(1, 2, 3);
	print_point(*point);
}
