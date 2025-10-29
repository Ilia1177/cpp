#include "RPN.hpp"

RPN::~RPN(void) {}
RPN::RPN(void) {}
RPN::RPN(const std::string& str): _notation(), _line(str) {}
RPN::RPN(const RPN &other): _notation(other._notation), _line(other._line) {}

// Assignment operator overload
RPN &RPN::operator=(const RPN &other)
{
	if (this != &other) {
		_notation = other._notation;
		_line = other._line;
	}
    return (*this);
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

float RPN::exec()
{
	if (_line.length() < 1 || _line.find_first_not_of(" \t\n\r\f\v") == std::string::npos) {
		throw std::invalid_argument("nothing to process");
	}

	char *end;
	float op1, op2;
	while (_line.length() > 0) {
		_line.erase(0, _line.find_first_not_of(" \t\n\r\f\v"));
		if (_line.empty()) {
			break;
		}
		try {
			if (_line[0] == '*' || _line[0] == '/' || _line[0] == '-' || _line[0] == '+') {
				throw std::invalid_argument("not an operand");
			}
			float operand = ::toFloat(_line, &end);
			_notation.push_back(operand);
			_line = end;
		} catch (...) {
			if (_line[0] == '*' || _line[0] == '/' || _line[0] == '-' || _line[0] == '+') {
				if (_notation.size() >= 2) {
					op1 = _notation.front(); _notation.pop_front();
					op2 = _notation.front(); _notation.pop_front();
					_notation.push_front(calc(op1, op2, _line[0]));
				} else {
					throw std::invalid_argument("missing operand or invalid notation");
				}
				_line.erase(0, 1);
			} else {
				throw std::invalid_argument("forbiden character");
			}
		}
	}
	if (_notation.size() == 1) {
		return (_notation.front());
	} else {
		throw std::invalid_argument("missing operator");
	}
}
