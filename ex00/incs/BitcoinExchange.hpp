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
	int year;
	int month;
	int day;
	date_s(int y, int m, int d);
	date_s(void);
	void print() const;
	bool operator<(const date_s& other) const;
	date_s& operator--();
} date_t;

typedef struct rate_s {
	enum Type { INT, FLOAT, NONE } type;
    union { int i; float f; } value;
    rate_s(int val);
	rate_s(float val);
	rate_s(void);
    void print() const;
	rate_s operator*(const rate_s&) const;
} rate_t;

// bad date == std::invalid_argument("bad date format");
class BitcoinExchange
{
    public:
        BitcoinExchange();
       // BitcoinExchange(std::string& input);
        BitcoinExchange(const BitcoinExchange& other);
        BitcoinExchange &operator=(const BitcoinExchange &other);
        ~BitcoinExchange();

		void 	getData(const std::string& dbName);
		void 	outputPrice(const std::string& inFile);
		date_t 	getDate(std::string& line);
		rate_t 	getRate(std::string& line);
		void 	printAll();
		rate_t 	rateAt(const date_t) const;
		
	private:
		std::map<date_t, rate_t> _rates;
		date_t  				_lowestDate;
};

//bool isInt(const std::string& str);
//bool isFloat(const std::string& str);

int toInt(const std::string& str, char **end);
float toFloat(const std::string& str);
date_t getCurrentDate();

std::ostream& operator<<(std::ostream&, const date_s&);
std::ostream& operator<<(std::ostream&, const rate_s&);

#endif

