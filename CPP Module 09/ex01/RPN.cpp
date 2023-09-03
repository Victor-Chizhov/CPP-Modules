#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(RPN const &other) {
    *this = other;
}

RPN::~RPN() {}

RPN &RPN::operator=(RPN const &other) {
    if (this != &other) {
        this->_stack = other._stack;
    }
    return *this;
}

void RPN::checkExpression(const std::string &expression) {
    for (size_t i = 0; i < expression.length(); i++) {
        if (expression[i] == ' ') {
            continue;
        }
        if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/' || expression[i] == '%') {
            if (this->_stack.size() < 2) {
                throw std::runtime_error("Not enough values in stack");
            }
            int a = this->_stack.top();
            this->_stack.pop();
            int b = this->_stack.top();
            this->_stack.pop();
            if (expression[i] == '+') {
                this->_stack.push(b + a);
            } else if (expression[i] == '-') {
                this->_stack.push(b - a);
            } else if (expression[i] == '*') {
                this->_stack.push(b * a);
            } else if (expression[i] == '/') {
                this->_stack.push(b / a);
            } else if (expression[i] == '%') {
                this->_stack.push(b % a);
            }
        } else if (expression[i] >= '0' && expression[i] <= '9') {
            std::stringstream ss;
            ss << expression[i];
            int num;
            ss >> num;
            this->_stack.push(num);
        } else {
            throw std::runtime_error("Invalid character");
        }
    }
}

void RPN::printResult() const {
    if (this->_stack.size() != 1) {
        throw std::runtime_error("Invalid expression");
    }
    std::cout << this->_stack.top() << std::endl;
}

void RPN::calculate(const std::string &expression) {
    checkExpression(expression);
    printResult();
}