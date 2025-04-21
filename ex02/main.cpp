#include <iostream>

int main(void)
{
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPtr = &str;
	std::string& stringRef = str;

	std::cout << "Memory address of str      : " << &str << std::endl;
	std::cout << "Memory address held by Ptr : " << stringPtr << std::endl;
	std::cout << "Memory address held by Ref : " << &stringRef << std::endl;
	std::cout << "Value of str               : " << str << std::endl;
	std::cout << "Value pointed by Ptr       : " << *stringPtr << std::endl;
	std::cout << "Value pointed by Ref       : " << stringRef << std::endl;
	return (0);
}
