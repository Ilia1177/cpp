#include "RPN.hpp"

psymbol_s::~psymbol_s() {}
psymbol_s::psymbol_s(void): _type(FALSE), _operand(0), _operator(0) {}
psymbol_s::psymbol_s(ptype type, char value): _type(type), _operand(0), _operator(value) {}
psymbol_s::psymbol_s(ptype type, float val): _type(type), _operand(val), _operator(0) {}
psymbol_s::psymbol_s(const psymbol_s& other): _type(other._type), _operand(other._operand), _operator(other._operator) {}

psymbol_s &psymbol_s::operator=(const psymbol_s& other) {
	if (this != &other) {
		this->_type = other._type;
		this->_operand = other._operand;
		this->_operator = other._operator;
	}
	return (*this);
}

std::ostream& operator<<(std::ostream& os, psymbol_t& symbol) {
	if (symbol._type == OPERAND)
		os << symbol._operand;
	else if (symbol._type == OPERATOR)
		os << symbol._operator;
	return os;
}
// Destructor
RPN::~RPN(void) {}
RPN::RPN(void) {}
RPN::RPN(const RPN &other): _expr(other._expr) {}

// Assignment operator overload
RPN &RPN::operator=(const RPN &other)
{
	if (this != &other)
		_expr = other._expr;
    return (*this);
}

int toInt(const std::string& str, char** endptr)
{
    *endptr = NULL;
	const char *cstr = str.c_str();

    errno = 0;
    long value = std::strtol(cstr, endptr, 10);

	if (errno == ERANGE||value > INT_MAX)
        throw std::invalid_argument("int overflow");
	else if (**endptr == '.')
		throw std::exception(); // float value
	if (*endptr == cstr)
		throw std::invalid_argument("no conversion made");
    return static_cast<int>(value);
}

float toFloat(const std::string& str, char **end)
{
	*end = NULL;
	const char *cstr = str.c_str();
	errno = 0;

	double value =  std::strtod(cstr, end);
	if (errno == ERANGE)
		throw std::invalid_argument("out of range");
	else if (*end == cstr)
		throw std::invalid_argument("no conversion made");
	return static_cast<float>(value);
}
void RPN::printList(void) {
    std::cout << "_notation list: ";

    std::list<float>::iterator it = _notation.begin();
    while (it != _notation.end()) {
        std::cout << *it;
        std::list<float>::iterator next = it;
        ++next;
        if (next != _notation.end())
            std::cout << ", ";
        ++it;
    }

    std::cout << std::endl;
}

float calc(float op1, float op2, char operation) {
	const float EPSILON = 1e-6f;

	if (operation == '+')
		return op1 + op2;
	if (operation == '-')
		return op1 - op2;
	if (operation == '*')
		return op1 * op2;
	if (operation == '/') {
		if (std::fabs(op2) > EPSILON) {
			return op1 / op2;
		} else {
			throw std::invalid_argument("divions by 0 forbiden");
		}
	}
	throw std::invalid_argument("bad character");
}

void RPN::exec(const std::string& str) {
	std::string line = str;
	char *end;
	float op1, op2;

	if (line.length() < 1)
		throw std::invalid_argument("nothing to process");
	while (line.length() > 0) {
		line.erase(0, line.find_first_not_of(" \t\n\r\f\v"));
		try {
			_notation.push_back(::toFloat(line, &end));
			line = end;
		} catch (...) {
			if (line[0] == '*' || line[0] == '/' || line[0] == '-' || line[0] == '+') {
				if (_notation.size() >= 2) {
					op1 = _notation.front(); _notation.pop_front();
					op2 = _notation.front(); _notation.pop_front();
					_notation.push_back(calc(op1, op2, line[0]));
				} else {
					throw std::invalid_argument("invalid notation");
				}
				line.erase(0, 1);
			} else {
				throw std::invalid_argument("forbiden character");
			}
		}
		line.erase(0, line.find_first_not_of(' '));
	}
	if (_notation.size() == 1) {
		std::cout << "result: " << _notation.front() << std::endl;
	} else {
		throw std::invalid_argument("missing operator");
	}
}
