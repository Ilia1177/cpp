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
	identify(test);
	identify(*test);
	return 0;
}
