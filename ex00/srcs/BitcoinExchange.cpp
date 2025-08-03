#include "BitcoinExchange.hpp"
// Destructor
BitcoinExchange::~BitcoinExchange(void) {}

// Default constructor
BitcoinExchange::BitcoinExchange(void) {}

// to be implemented
// Copy constructor
BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
    std::cout << "Copy constructor called" << std::endl;
    (void) other;
    return ;
}
// to be mplemented
// Assignment operator overload
BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
    std::cout << "Assignment operator called" << std::endl;
    (void) other;
    return (*this);
}



void BitcoinExchange::printAll() {
	std::map<date_t, rate_t>::iterator it;
    for (it = _rates.begin(); it != _rates.end(); ++it) {
        const date_t& date = it->first;
        rate_t& val = it->second;

		date.print();
        val.print();
        std::cout << std::endl;
    }
}

// to be improved
date_t BitcoinExchange::getDate(std::string& line)
{
	long year;
	long month;
	long day;
	char *ptr = 0;
	const char *str = line.c_str();

	year = std::strtol(str, &ptr, 10);
	str = ptr;
	month = std::strtol(str, &ptr, 10);
	str = ptr;
	day = std::strtol(str, &ptr, 10);

	line.erase(0, 11);
	return date_t(static_cast<int>(year), static_cast<int>(month), static_cast<int>(day));
}

// to be improved
rate_t BitcoinExchange::getRate(std::string& line)
{
	char *endptr;

	const char *str = line.c_str();
	if (isFloat(line)) {
		float floatVal = std::strtof(str, &endptr);
		return (rate_t(floatVal));
	} else if (isInt(line)) {
		long intVal = std::strtol(str, &endptr, 10);
		return rate_t(static_cast<int>(intVal));
	} else {
		throw std::invalid_argument("bad rate format");
	}
}

// to be improved
void BitcoinExchange::getData(const std::string& dbName) 
{
	std::ifstream	data;
	std::string 	line;

	data.open(dbName.c_str());
	if (!data.is_open() || !data)
		throw  std::runtime_error("Error: opening file");
	while(std::getline(data, line)) {
		try {
			date_t date = getDate(line);
			rate_t rate = getRate(line);
			_rates.insert(std::make_pair(date, rate));
		} catch (...) {} // to be implemented
		line.clear();
	}
}

bool isFloat(const std::string& str)
{
	size_t i = 0;

	if (str == "inf" || str == "-inf" || str == "+inf")
		return true;
	if (str.length() == 0)
		return false;
	if (str[i] == '-' || str[i] == '+')
		i++;
	for (; i < str.length() && str[i] != '.'; i++) {
		if (!std::isdigit(str[i]))
			return false;
	}
	if (str[i++] != '.')
		return false;
	for (; i < str.length(); i++) {
		if (!std::isdigit(str[i]))
			return false;
	}
	return true;
}

bool isInt(const std::string& str) {

	size_t i = 0;

	if (str.length() == 0)
		return false;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (i < str.length()) {
		if (!std::isdigit(str[i]))
			return false;
		i++;
	}
	return true;
}
