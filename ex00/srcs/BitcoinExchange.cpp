#include "BitcoinExchange.hpp"
#include <iostream>

// Date_t
date_s::date_s(int y, int m, int d) : year(y), month(m), day(d) {}

date_s::date_s(void) : year(9999), month(12), day(31) {}

void date_s::print() const { std::cout << year << "-" << month << "-" << day;}

bool date_s::operator<(const date_s& other) const {
        if (year != other.year) return year < other.year;
        if (month != other.month) return month < other.month;
        return day < other.day;
}

date_s& date_s::operator--() {
    if (--this->day == 0) {
        if (--this->month == 0) {
            --this->year;
            this->month = 12;
        }
		if ((this->month < 7 && this->month % 2 == 0) || (this->month >= 7 && this->month % 2 == 1))
        	this->day = 30;
		else 
			this->day = 31;
    }
    return *this;
}

std::ostream& operator<<(std::ostream& os, const date_s& date) {
	os << std::setfill('0') << date.year << "-";
	os << std::setw(2) << date.month << "-";
	os << std::setw(2) << date.day;
	return os;
}

//Rate_t
rate_s::rate_s(int val) { type = INT; value.i = val; }

rate_s::rate_s(float val) { type = FLOAT; value.f = val; }

rate_s::rate_s(void) { type = NONE; value.f = 0.0f; }

void rate_s::print() const {
        if (type == INT)
            std::cout << value.i;
        else if (type == FLOAT)
            std::cout << value.f;
		else
			std::cout << "none";
}

rate_s rate_s::operator*(const rate_s& other) const {
	if (this->type == INT && other.type == INT)
		return this->value.i * other.value.i;
	if (this->type == FLOAT && other.type == INT)
		return this->value.f * other.value.i;
	if (this->type == INT && other.type == FLOAT)
		return this->value.i * other.value.f;
	if (this->type == FLOAT && other.type == FLOAT)
		return this->value.f * other.value.f; 
	return rate_s();
}

bool rate_s::operator<(const rate_s& other) const {
	if (this->type == INT && other.type == INT)
		return this->value.i < other.value.i;
	if (this->type == FLOAT && other.type == INT)
		return this->value.f < other.value.i;
	if (this->type == INT && other.type == FLOAT)
		return this->value.i < other.value.f;
	if (this->type == FLOAT && other.type == FLOAT)
		return this->value.f < other.value.f; 
	throw std::out_of_range("wrong rate value (none)");
}

std::ostream& operator<<(std::ostream& os, const rate_s& rate) {
	if (rate.type == 0)
		os << rate.value.i;
	else if (rate.type == 1)
		os << rate.value.f;
	else
		os << "NONE";
	return os;
}
// Destructor
BitcoinExchange::~BitcoinExchange(void) {}

// Default constructor
BitcoinExchange::BitcoinExchange(void): _lowestDate(9999, 12, 31) {}

// to be implemented
// Copy constructor
BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) 
{
	_lowestDate = date_s(other._lowestDate.year, other._lowestDate.month, other._lowestDate.day) ;
}

// to be mplemented
// Assignment operator overload
BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	_lowestDate = other._lowestDate;
    return (*this);
}

// debug
void BitcoinExchange::printAll() {
	std::map<date_t, rate_t>::iterator it;
    for (it = _rates.begin(); it != _rates.end(); ++it) {
        const date_t& date = it->first;
        rate_t& val = it->second;

		std::cout << date << " | " << val << std::endl;
    }
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
	else if (value < 0)
		throw std::invalid_argument("negative value");
	return static_cast<float>(value);
}

int toInt(const std::string& str, char** endptr)
{
    *endptr = NULL;
	const char *cstr = str.c_str();

    errno = 0;
    long value = std::strtol(cstr, endptr, 10);

	if (errno == ERANGE||value > INT_MAX)
        throw std::invalid_argument("int overflow");
	else if (value < 0) 
		throw std::invalid_argument("negative value");
	else if (**endptr == '.')
		throw std::exception(); // float value
	if (*endptr == cstr)
		throw std::invalid_argument("no conversion made");
    return static_cast<int>(value);
}

date_t getCurrentDate() {
	std::time_t now = std::time(NULL);
    std::tm* local = std::localtime(&now);

    int year  = 1900 + local->tm_year;
    int month = 1 + local->tm_mon;    // tm_mon is 0-based
    int day   = local->tm_mday;
    return date_t(year, month, day);
}

// to be improved
date_t BitcoinExchange::getDate(std::string& line)
{
	int year;
	int month;
	int day;
	
	std::string str = line;
	char *end = NULL;
	try {
		year = ::toInt(line, &end);
		if (end - line.c_str() != 4 || *end != '-') throw std::invalid_argument("invalid date");
		line.erase(0, 5);
		end = NULL;
		month = ::toInt(line, &end);
		if (end - line.c_str() != 2 || *end != '-') throw std::invalid_argument("invalid date");
		line.erase(0, 3);
		end = NULL;
		day = ::toInt(line, &end);
		if (end - line.c_str() != 2) throw std::invalid_argument("invalid date");
		line.erase(0, 2);
		if (year < 1970 || month > 12 || day > 31) {
			str.erase(10, str.length());
			throw std::invalid_argument("invalid date");
		}
	} catch (std::exception &e) {
		line = str;
		throw;
	}
	date_t date = date_t(year, month, day);
	if (getCurrentDate() < date) {
		line = str.erase(10, str.length());
		throw std::invalid_argument("Rate of tomorrow cannot be guess...");
	}
	return date;
}

// to be improved
rate_t BitcoinExchange::getRate(std::string& line)
{
	rate_t rate;
	char *end = NULL;
	try {
		rate = rate_t(toInt(line, &end));
		line.erase(0, end - line.c_str());
	} catch (...) {
		end = NULL;
		rate = rate_t(toFloat(line, &end));
		line.erase(0, end - line.c_str());
	}
	return rate;
}

// to be improved
void BitcoinExchange::readData(const std::string& dbName) 
{
	std::ifstream	data;
	std::string 	line;

	data.open(dbName.c_str());
	if (!data || !data.is_open())
		throw  std::runtime_error("Cannot open database");
	while(std::getline(data, line)) {
		try {
			date_t date = getDate(line);
			if (line.length() < 2 || line[0] != ',') throw std::invalid_argument("invalid date format"); // ??
			line.erase(0, 1);
			if (date < _lowestDate) _lowestDate = date;
			rate_t rate = getRate(line);
			_rates.insert(std::make_pair(date, rate));
		} catch (...) { 
		}
		line.clear();
	}
}

void BitcoinExchange::outputPrice(const std::string& inFile) {
	std::ifstream input;
	std::string line;

	input.open(inFile.c_str());
	rate_t value;
	if (!input || !input.is_open())
		throw  std::runtime_error("cannot open infile");
	while (std::getline(input, line)) {
		try {
			date_t date = getDate(line);
			if (line.length() < 4)
				throw std::invalid_argument("no value found");
			if (line.length() < 4 || line[0] != ' ' || line[1] != '|' || line[2] != ' ')
				throw std::invalid_argument("bad format");
			line.erase(0, 3);
			value = getRate(line);
			if (rate_s(1000) < value)
				throw std::out_of_range("value is too large (> 1000)");
			if (line[0] != '\0')
				throw std::invalid_argument("invalid format");
			std::cout << date << " => " << value << " => " << value * rateAt(date) << std::endl;	
		} catch (std::invalid_argument& e) {
			std::cout << "Error: " << e.what() << " => '" << line << "'" << std::endl;
		} catch (std::out_of_range& e) {
			std::cout << "Error: " << e.what() << " => '" << value << "'" << std::endl;
		} catch (...) {}
		line.clear();
	}
};

rate_t BitcoinExchange::rateAt(date_t date) const {
    std::map<date_t, rate_t>::const_iterator it = _rates.find(date);

    while (it == _rates.end() && _lowestDate < date) {
        it = _rates.find(--date);
    }
    if (it == _rates.end()) throw std::invalid_argument("no entry for this date");
    return it->second;
}
//bool isFloat(const std::string& str)
//{
//	size_t i = 0;
//
//	if (str == "inf" || str == "-inf" || str == "+inf")
//		return true;
//	if (str.length() == 0)
//		return false;
//	if (str[i] == '-' || str[i] == '+')
//		i++;
//	for (; i < str.length() && str[i] != '.'; i++) {
//		if (!std::isdigit(str[i]))
//			return false;
//	}
//	if (str[i++] != '.')
//		return false;
//	for (; i < str.length(); i++) {
//		if (!std::isdigit(str[i]))
//			return false;
//	}
//	return true;
//}
//
//	bool isInt(const std::string& str) {
//
//		size_t i = 0;
//
//		if (str.length() == 0)
//			return false;
//		if (str[i] == '-' || str[i] == '+')
//			i++;
//		while (i < str.length()) {
//			if (!std::isdigit(str[i])) // ?? what about '-' cahr at the end ?
//				return false;
//			i++;
//		}
//		return true;
//	}
