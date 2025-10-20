#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP
# include <fstream>
# include <fstream>
# include <climits>
#include <iomanip> // for std::setw, std::setfill
# include <iostream>
# include <map>
# include <exception>
# include <stdexcept>
# include <string>
# include <cstdlib>
# include <ctime>

typedef struct date_s {
	date_s(void);
	date_s(int y, int m, int d);
	date_s(const date_s& other);
	date_s& operator=(const date_s&);
	~date_s(void);

	void print() const;
	bool operator<(const date_s& other) const;
	date_s& operator--();

	int year;
	int month;
	int day;
} date_t;

typedef struct rate_s {
	~rate_s(void);
    rate_s(int val);
	rate_s(float val);
	rate_s(void);
	rate_s(const rate_s&);
	rate_s& operator=(const rate_s& other);
	rate_s operator*(const rate_s&) const;
	bool operator<(const rate_s& other) const;

	enum Type { INT, FLOAT, NONE } type;
    union { int i; float f; } value;
} rate_t;

// bad date == std::invalid_argument("bad date format");
class BitcoinExchange
{
    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& other);
        BitcoinExchange &operator=(const BitcoinExchange &other);
        ~BitcoinExchange();

		void 	readData(const std::string& dbName);
		void 	outputPrice(const std::string& inFile);
		date_t 	getDate(std::string& line);
		rate_t 	getRate(std::string& line);
		void 	printAll();
		rate_t 	rateAt(const date_t) const;
		
	private:
		std::map<date_t, rate_t> _rates;
		date_t  				_lowestDate;
};

bool isLeapYear(int year);
bool isValidDate(int year, int month, int day);
int toInt(const std::string& str, char **end);
float toFloat(const std::string& str);
date_t getCurrentDate();

std::ostream& operator<<(std::ostream&, const date_s&);
std::ostream& operator<<(std::ostream&, const rate_s&);

#endif

