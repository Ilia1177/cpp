#ifndef FORM_HPP
# define FORM_HPP
# include <iostream>

class Bureaucrat;

class Form
{
    public:
        Form(const std::string& name = "Undefined", int gradeToSign = 1, int gradeToExecute = 1);
        Form(const Form& other);
        Form &operator=(const Form &other);
        ~Form();

		// Exception classes
		class GradeTooHighException : public std::exception {
			public:
				const char* what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				const char* what() const throw();
		};

		// getters
		const std::string&	getName() const;
		bool				isSigned() const;
		int					getExecGrade() const;
		int					getSignGrade() const;
	
		// setters
		void				beSigned(const Bureaucrat& signer);
			
	private:
		const std::string	_name;
		bool 				_signed;
		const int			_gradeToExecute;
		const int			_gradeToSign;
};

std::ostream& operator<<(std::ostream& os, const Form& form);

#endif

