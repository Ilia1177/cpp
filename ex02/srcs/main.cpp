#include "MutantStack.hpp"
#include <vector>
#include <list>

int main()
{
	std::cout << "Personal test" << std::endl;
	{
		{
			std::cout << "int" << std::endl;
			MutantStack<int> stk;


			for (size_t i = 0; i < 10; ++i) {
				stk.push(i);
			}
			for (MutantStack<int>::iterator it = stk.begin(); it != stk.end(); ++it) {
				std::cout << *it;
				if (it != stk.end() - 1) std::cout << ", ";
			}
			std::cout << std::endl << std::endl;
		}
		{
			std::cout << "vector<char>" << std::endl;

			MutantStack<std::vector<char> > stk;
			for (char i = 76; i < 86; ++i) {
				stk.push(std::vector<char>(1, i));  // Push a vector<int>
			}
			for (MutantStack<std::vector<char> >::iterator it = stk.begin(); it != stk.end(); ++it) {
				std::cout << (*it)[0];
				if (it != stk.end() - 1) std::cout << ", ";
			}
			std::cout << std::endl << std::endl;
		}
		{
			std::cout << "list<char>" << std::endl;

			MutantStack<std::list<char> > stk;
			for (char i = 76; i < 86; ++i) {
				stk.push(std::list<char>(1, i));  // Push a vector<int>
			}
			MutantStack<std::list<char> >::iterator it = stk.begin();
			MutantStack<std::list<char> >::iterator last = stk.end();
			--last;
			for (; it != stk.end(); ++it) {
				for (std::list<char>::const_iterator lit = it->begin(); lit != it->end(); ++lit) {
					std::cout << *lit;
				}
				if (it != last) std::cout << ", ";
			}
			std::cout << std::endl << std::endl;
		}
	}

	std::cout << "Main test from subject:" << std::endl;
	{
		std::cout << "Testing MutantStack" << std::endl;
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << ", ";
		mstack.pop();
		std::cout << mstack.size() << " - ";
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		//[...]
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		std::cout << "Iteration: ";
		while (it != ite) {
			std::cout << *it;
			if (it != ite - 1) std::cout << ", ";
			++it;
		}
		std::stack<int> s(mstack);
		std::cout << std::endl << std::endl;
	}
	{
		std::cout << "Testing deque" << std::endl;;
		std::deque<int> mstack;
		mstack.push_back(5);
		mstack.push_back(17);
		std::cout << mstack.back() << ", ";
		mstack.pop_back();
		std::cout << mstack.size() << " - ";
		mstack.push_back(3);
		mstack.push_back(5);
		mstack.push_back(737);
		//[...]
		mstack.push_back(0);
		std::deque<int>::iterator it = mstack.begin();
		std::deque<int>::iterator ite = mstack.end();
		++it;
		--it;
		std::cout << "Iteration: ";
		while (it != ite) {
			std::cout << *it;
			if (it != ite - 1) std::cout << ", ";
			++it;
		}
		std::stack<int> s(mstack);
		std::cout << std::endl << std::endl;
	}
	{
		std::cout << "Testing list" << std::endl;;
		std::list<int> mstack;
		mstack.push_back(5);
		mstack.push_back(17);
		std::cout << mstack.back() << ", ";
		mstack.pop_back();
		std::cout << mstack.size() << " - ";
		mstack.push_back(3);
		mstack.push_back(5);
		mstack.push_back(737);
		//[...]
		mstack.push_back(0);
		std::list<int>::iterator it = mstack.begin();
		std::list<int>::iterator ite = mstack.end();
		++it;
		--it;
		std::cout << "Iteration: ";
		std::list<int>::iterator last = ite; 
		--last; 					// Cannot get random access (ite - 1) using decrementing operator to get last elem
		while (it != ite) {
			std::cout << *it;
			if (it != last) std::cout << ", ";
			++it;
		}
		std::stack<int, std::list<int> > s(mstack);
		std::cout << std::endl << std::endl;
	}
	{
		std::cout << "Testing vector" << std::endl;;
		std::vector<int> mstack;
		mstack.push_back(5);
		mstack.push_back(17);
		std::cout << mstack.back() << ", ";
		mstack.pop_back();
		std::cout << mstack.size() << " - ";
		mstack.push_back(3);
		mstack.push_back(5);
		mstack.push_back(737);
		//[...]
		mstack.push_back(0);
		std::vector<int>::iterator it = mstack.begin();
		std::vector<int>::iterator ite = mstack.end();
		++it;
		--it;
		std::cout << "Iteration: ";
		std::vector<int>::iterator last = ite;
		--last;
		while (it != ite) {
			std::cout << *it;
			if (it != last) std::cout << ", ";
			++it;
		}
		std::stack<int, std::vector<int> > s(mstack);
		std::cout << std::endl << std::endl;
	}


	return 0;
}
