#ifndef RPN_HPP
#define RPN_HPP
#include <cerrno>
#include <climits>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <list>

class RPN
{
  public:
    RPN(const std::string& line);
    ~RPN();

    float exec();
    void printList(void);

  private:
    std::list<float>     _notation;
    std::string          _line;

    RPN(void);
    RPN(const RPN& other);
    RPN& operator=(const RPN& other);
};

float toFloat(const std::string& str, char** end);
#endif
