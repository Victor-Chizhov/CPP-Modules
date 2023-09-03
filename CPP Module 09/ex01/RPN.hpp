#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <string>
#include <stack>
#include <cmath>
#include <sstream>
#include <iomanip>

class RPN {

    private:
        std::stack<double> _stack;
        void checkExpression(std::string const &expression);
        void printResult() const;

    public:
        RPN();
        RPN(RPN const &other);
        ~RPN();
        RPN &operator=(RPN const &other);
        void calculate(std::string const &expression);
};

#endif