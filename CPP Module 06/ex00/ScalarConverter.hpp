#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>

class ScalarConverter {

    private:
        ScalarConverter();
        ScalarConverter(ScalarConverter const &src);
        ScalarConverter & operator=(ScalarConverter const &copy);
        ~ScalarConverter();
        static void checkLiteral(std::string& literal, std::string type);
        static int isChar(std::string& literal);
        static int isInt(std::string& literal);
        static int isFloat(std::string& literal);
        static int checkDot(std::string& literal);

    public:
        static void convert(std::string literal);
};

#endif