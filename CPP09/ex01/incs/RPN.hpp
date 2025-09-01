#ifndef RPN_HPP
# define RPN_HPP
# include <iostream>
# include <list>
# include <cstdlib>
# include <climits>
# include <cmath>

enum ptype {OPERAND, OPERATOR, FALSE};
typedef struct psymbol_s {

	psymbol_s(void);
	psymbol_s(ptype, float);
	psymbol_s(ptype, char);
	psymbol_s(const psymbol_s& other);
	psymbol_s &operator=(const psymbol_s& other);
	~psymbol_s();

	ptype _type;
	float _operand;
	char _operator;
	
}	psymbol_t;
	
std::ostream& operator<<(std::ostream& os, psymbol_t& symbol); 

class RPN
{
    public:
        RPN(void);
        RPN(const RPN& other);
        RPN &operator=(const RPN &other);
        ~RPN();

		void exec(const std::string&);
		void printList(void);
	private:
		std::list<psymbol_t> _expr;
		std::list<float> _notation;
};

float toFloat(const std::string& str, char **end);
int toInt(const std::string& str, char **end);
#endif

