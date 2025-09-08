#ifndef FORM_HPP
# define FORM_HPP
# include <iostream>

class Bureaucrat;

class AForm
{
    public:
        AForm(const std::string&, int, int);
        AForm(const AForm& other);
        AForm &operator=(const AForm &other);
        virtual ~AForm();

		// Exception classes
		class GradeTooHighException : public std::exception {
			public:
				const char* what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				const char* what() const throw();
		};

		class IsNotSigned : public std::exception {
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
		virtual void		execute(const Bureaucrat& executor) const = 0;

	private:
		const std::string	_name;
		bool 				_signed;
		const int			_gradeToExecute;
		const int			_gradeToSign;
};

std::ostream& operator<<(std::ostream& os, const AForm& form);

template <typename T>
T clamp(const T& value, const T& low, const T& high) {
    if (value < low) return low;
    if (value > high) return high;
    return value;
}

#endif

