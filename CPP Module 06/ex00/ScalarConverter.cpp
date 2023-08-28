#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(ScalarConverter const & copy) { *this = copy; }
ScalarConverter::~ScalarConverter() {}

ScalarConverter& ScalarConverter::operator=(ScalarConverter const & copy) {
    (void)copy;
    return *this;
}

void ScalarConverter::checkLiteral(std::string &literal, std::string type) {

    int countDot = 0;
    int countF = 0;

    if (literal[0] == '.') {
        printf("Error: Must be normal argument\n");
        exit(1);
    }

    if (type == "Int") {
        for (unsigned long i = 0; i < literal.length(); i++) {
            if (i == 0 && (literal[i] == '-' || literal[i] == '+'))
                continue ;
            if (!isdigit(literal[i])) {
                std::cout << "Error: literal must be a number" << std::endl;
                exit(1);
            }
        }
    } else if (type == "Double") {
        for (unsigned long i = 0; i < literal.length(); i++) {
            if (i == 0 && (literal[i] == '-' || literal[i] == '+'))
                continue ;
            else if (literal[i] == '.') {
                countDot++;
                continue;
            }
            else if (!isdigit(literal[i]) || countDot > 1) {
                std::cout << "Error: literal must be a number" << std::endl;
                exit(1);
            }
        }
    } else if (type == "Float") {
        for (unsigned long i = 0; i < literal.length(); i++)
            if (i == 0 && (literal[i] == '-' || literal[i] == '+'))
                continue ;
            else if (literal[i] == '.') {
                countDot++;
                continue;
            }
            else if (literal[i] == 'f') {
                countF++;
                continue;
            }
            else if (!isdigit(literal[i]) || countDot > 1 || countF > 1) {
                std::cout << "Error: literal must be a number" << std::endl;
                exit(1);
            }
    }
}

int ScalarConverter::isChar(std::string& literal) {
    if (literal.length() == 1 && !isdigit(literal[0])) {
        char c = literal[0];
        std::cout << "char: '" << c << "'" << std::endl;
        std::cout << "int: " << static_cast<int>(c) << std::endl;
        std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
        std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
        return 1;
    }
    return 0;
}

int ScalarConverter::isInt(std::string& literal) {

    int i;

    checkLiteral(literal, "Int");
    if ((literal.length() == 1 && isdigit(literal[0])) || literal.length() > 1) {
        try {
            i = std::stoi(literal);
        } catch (std::exception &e) {
            std::cout << "Error: " << e.what() << std::endl;
            exit(1);
        }

        if (i < 32 || i > 126)
            std::cout << "char: Non displayable" << std::endl;
        else
            std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;
        std::cout << "int: " << i << std::endl;
        std::cout << "float: " << i << ".0f" << std::endl;
        std::cout << "double: " << i << ".0" << std::endl;
        return 1;
    }
    return 0;
}

int ScalarConverter::isFloat(std::string &literal) {

    float f;

    checkLiteral(literal, "Float");
    try {
        f = std::stof(literal);
    } catch (std::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
        exit(1);
    }
    if (f < 32 || f > 126)
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << static_cast<char>(f) << "'" << std::endl;
    std::cout << "int: " << static_cast<int>(f) << std::endl;
    std::cout << "float: " << static_cast<float>(f) << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(f) << std::endl;
    return 1;
}

int ScalarConverter::isDouble(std::string& literal) {

    double d;

    checkLiteral(literal, "Double");
    try {
        d = std::stod(literal);
    } catch (std::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
        exit(1);
    }
    if (d < 32 || d > 126)
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;
    std::cout << "int: " << static_cast<int>(d) << std::endl;
    std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(d) << std::endl;
    return 1;
}

int ScalarConverter::checkDot(std::string &literal) {
    for (unsigned long i = 0; i < literal.length(); i++) {
        if (literal[i] == '.')
            return 1;
    }
    return 0;
}

void ScalarConverter::handleSpecificLiterals(std::string& literal) {

    if (literal == "-inff" || literal == "+inff" || literal == "nanf" || literal == "-inf" || literal == "+inf" || literal == "nan") {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << literal << "f" << std::endl;
        std::cout << "double: " << literal << std::endl;
        exit(1);
    }
}

void ScalarConverter::convert(std::string literal) {

    handleSpecificLiterals(literal);

    if (!checkDot(literal)) {
        if (isChar(literal) || isInt(literal))
            return;
    } else {
        if (isFloat(literal) || isDouble(literal))
            return;
    }
}