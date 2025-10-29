# include "Base.hpp"
# include "A.hpp"
# include "B.hpp"
# include "C.hpp"
#include <cstdlib>
#include <ctime>

Base* generate(void) 
{
	int r = rand() % 3;

	switch (r) {
		case 0:
			return new A;
		case 1:
		 	return new B;
		case 2:
			return new C;
		default:
			return NULL;
	}
}

void identify(Base* p) 
{
	std::cout << "p: ";
	if (dynamic_cast<A*>(p)) {
		std::cout << "A" << std::endl;
	} else if (dynamic_cast<B*>(p)) {
		std::cout << "B" << std::endl;
	} else if (dynamic_cast<C*>(p)) {
		std::cout << "C" << std::endl;
	} else {
		std::cout << "Not a class" << std::endl;
	}
}

void identify(Base& p)
{
	try {
		A &a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "p: A" << std::endl;
	} catch (...) {}
	try {
		B &b = dynamic_cast<B&>(p);
		(void)b;
		std::cout << "p: B" << std::endl;
	} catch (...) {}
	try {
		C &c = dynamic_cast<C&>(p);
		(void)c;
		std::cout << "p: C" << std::endl;
	} catch (...) {}
}
