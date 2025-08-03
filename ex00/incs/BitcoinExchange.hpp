#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP
#include <fstream>
# include <iostream>
# include <map>
# include <exception>
# include <stdexcept>
# include <string>
# include <cstdlib>

typedef struct date_s {
	int year;
	int month;
	int day;
	date_s(int y, int m, int d) : year(y), month(m), day(d) {}
	void print() const { std::cout << year << "-" << "-" << month << "-" << day << std::endl; }
	bool operator<(const date_s& other) const {
        if (year != other.year) return year < other.year;
        if (month != other.month) return month < other.month;
        return day < other.day;
	}
} date_t;

typedef struct rate_s {
enum Type { INT, FLOAT, NONE } type;
    union { int i; float f; } value;

    rate_s(int val) { type = INT; value.i = val; }
    rate_s(float val) { type = FLOAT; value.f = val; }
	rate_s() { type = NONE; value.f = 0.0f; }

    void print() const {
        if (type == INT)
            std::cout << value.i;
        else
            std::cout << value.f;
    }
} rate_t;


class BitcoinExchange
{
    public:
        BitcoinExchange();
       // BitcoinExchange(std::string& input);
        BitcoinExchange(const BitcoinExchange& other);
        BitcoinExchange &operator=(const BitcoinExchange &other);
        ~BitcoinExchange();

		void 	getData(const std::string& dbName);
		void 	outputPrice(const std::string& inFile) const;
		date_t 	getDate(std::string& line);
		rate_t 	getRate(std::string& line);
		void 	printAll();
		
	private:
		std::map<date_t, rate_t> _rates;
};

bool isInt(const std::string& str);
bool isFloat(const std::string& str);

#endif

