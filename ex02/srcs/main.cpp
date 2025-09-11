#include <cstdlib>
#include <ctime>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base* generate(void);
void identify(Base* p);
void identify(Base& p);

int main() {
	srand(time(0));
	Base* test;

	test = generate();
	std::cout << "Identify pointer" << std::endl;
	identify(test);
	std::cout << "Identify by reference" << std::endl;
	identify(*test);
	if (test) delete test;

	return 0;
}
