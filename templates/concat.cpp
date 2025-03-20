#include <string>
#include <concepts>
#include <string_view>
#include <type_traits>

template <typename t1>
concept toString = requires (t1 T1){
std::to_string(T1);
};

std::string concat(const toString auto& T1, const toString auto& T2){
	std::string str_t1 = std::to_string(T1);
	std::string str_t2 = std::to_string(T2);
	return str_t1 + str_t2;
}

int main(){
	return 0;
	auto test1 = concat(1, 2);
	auto test2 = concat("hope", "plight");
	std::string str1 = "death";
	std::string str2 = "bright";
	auto test3 = concat(str1, str2);
	auto test4 = concat(str1, "hope");
}
