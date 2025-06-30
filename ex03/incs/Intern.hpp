#ifndef INTERN_HPP
# define INTERN_HPP
# include <iostream>

class AForm;

class Intern
{
    public:
        Intern(void);
        Intern(const Intern& other);
        Intern &operator=(const Intern &other);
        ~Intern();
		AForm* makeForm(const std::string& name, const std::string& target) const;

		class InvalidTypeForm: public std::exception {
			public:
				const char* what() const throw();
		};
};

#endif

