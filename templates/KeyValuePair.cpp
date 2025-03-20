#include <string>
#include <iostream>
#include <concepts>

template <std::integral Key, std::floating_point Value>
class KeyValuePair {
public:
	KeyValuePair() = default;
	KeyValuePair(Key k, Value v): m_key {k}, m_value {v} {};

	Key getKey() const { return m_key; }
	void setKey(Key k) { m_key = k; }

	Value getValue() { return m_value; }
	void setValue(Value v) { m_value = v; }
private:
	Key m_key;
	Value m_value;
};

/*template <>*/
/*class KeyValuePair<const char*, const char*> {*/
/*public:*/
/*	KeyValuePair() = default;*/
/*	KeyValuePair(const char* k, const char* v): m_key {k}, m_value {v} {};*/
/**/
/*	std::string getKey() const { return m_key; }*/
/*	void setKey(std::string& k) { m_key = k; }*/
/**/
/*	std::string getValue() { return m_value; }*/
/*	void setValue(std::string& v) { m_value = v; }*/
/*private:*/
/*	std::string m_key;*/
/*	std::string m_value;*/
/*};*/

int main() {
	auto kv = KeyValuePair(1, 2.3);
	auto kv1 = KeyValuePair(2, 4.3);
	std::cout << kv.getKey() << kv.getValue();
	std::cout << kv1.getKey() << kv1.getValue();
}
