#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <iostream>
# include <exception>

class Bureaucrat
{
    public:
		Bureaucrat(const std::string &name = "Undefined", int grade = 150);
        Bureaucrat(const Bureaucrat& other);
        Bureaucrat &operator=(const Bureaucrat &other);
        ~Bureaucrat();

		//void	GradeTooHighException();
		//void	GradeTooLowException();

		void	gradeUp();
		void	gradeDown();
		
		const std::string	getName(void) const;
		int					getGrade(void) const;

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

