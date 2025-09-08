#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <iostream>
# include <exception>
# include "Form.hpp"

class Bureaucrat
{
    public:
		Bureaucrat(const std::string &name = "Unknown", int grade = 150);
        Bureaucrat(const Bureaucrat& other);
        Bureaucrat &operator=(const Bureaucrat &other);
        ~Bureaucrat();

		// getters
		const std::string&	getName(void) const;
		int					getGrade(void) const;

		// to immplement
		void	signForm(Form& paper) const;
		void	gradeUp();
		void	gradeDown();

		// Exception classes
		class GradeTooHighException : public std::exception {
			public:
				const char* what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				const char* what() const throw();
		};

	private:
		const std::string	_name;
		int					_grade;

};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& admin);

#endif

