#include <memory>
#include <iostream>
class Fraction{
	int m_num{ 0 };
	int m_den{ 1 };
 public:
	Fraction(int num = 0, int den = 1):m_num{ num }, m_den{ den }{
	}

	friend std::ostream& operator<<(std::ostream& out, const Fraction& f1){
		out << f1.m_num << '/' << f1.m_den;
		return out;
	}
};

int main(){
	auto f1{ std::make_unique<Fraction>(3, 5) };
	std::cout << *f1 << std::endl;
	auto f2{ std::make_unique<Fraction[]>(4) };
	std::cout << f2[0] << std::endl;
	return 0;
}