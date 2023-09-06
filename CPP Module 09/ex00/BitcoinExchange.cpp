#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}
BitcoinExchange::~BitcoinExchange() {}
BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy) {
    *this = copy;
}
BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &op) {
    if (this != &op)
        this->_data = op._data;
    return *this;
}

bool BitcoinExchange::checkDateInMap(std::string key) {

    if(!checkFormatDate(key))
        return false;

    int years = atoi(key.substr(0, 4).c_str());
    int months = atoi(key.substr(5, 2).c_str());
    int days = atoi(key.substr(8, 2).c_str());

    if (years < 0 || months < 1 || months > 12 || days < 1 || days > 31)
        return false;
    if (months == 2) {
        if ((years % 4 == 0 && years % 100 != 0) || years % 400 == 0) {
            if (days > 29)
                return false;
        } else if (days > 28)
            return false;
    } else if (months == 4 || months == 6 || months == 9 || months == 11)
        if (days > 30)
            return false;
    return true;
}

bool BitcoinExchange::checkFormatDate(std::string date) {
    if (date.length() != 10 || date[4] != '-' || date[7] != '-')
        return false;
    for (int i = 0; i < 10; i++) {
        if (i != 4 && i != 7 && !isdigit(date[i]))
            return false;
    }
    return true;
}

void BitcoinExchange::copyDataInMap(std::string filename, std::string firstString, char delimiter) {
    std::ifstream inputFile(filename);
    if (!inputFile.is_open())
        throw std::out_of_range("Error: could not open file");

    std::string firstLine;
    std::getline(inputFile, firstLine);
    if (firstLine != firstString)
        throw std::invalid_argument("Error: invalid file");

    std::string line;
    while (std::getline(inputFile, line)) {
        std::istringstream ss(line);
        std::string key;
        float value;
        if (std::getline(ss, key, delimiter) && ss >> value)
            _data[key] = value;
        else
           throw std::invalid_argument("Error: invalid value");
    }
    inputFile.close();
}

void BitcoinExchange::openInput(std::string filename) {
    std::ifstream inputFile(filename);
    if (!inputFile.is_open())
        throw std::out_of_range("Error: could not open file");

    std::string firstLine;
    std::getline(inputFile, firstLine);
    if (firstLine != "date | value")
        throw std::invalid_argument("Error: invalid file");

    std::string line;
    while (std::getline(inputFile, line)) {
        size_t pos = line.find('|');
        if (pos != std::string::npos) {
            convertRate(line);
        } else {
            std::istringstream iss(line);
            iss >> std::ws;
            if (iss >> line)
                std::cout << "Error: bad input => " << line << std::endl;
            else
                std::cout << "Error: bad input => " << line << std::endl;
        }
    }
    inputFile.close();
}

bool BitcoinExchange::isValidFloat(const std::string& str) {
    std::istringstream iss(str);
    float floatValue;
    return (iss >> floatValue) && iss.eof();
}

bool BitcoinExchange::checkLine(std::string key, std::string value) {

    if (!checkDateInMap(key)) {
        std::cout << "Error: bad input => " << key << std::endl;
        return false;
    }

    if (isValidFloat(value)) {
        float valueFloat = atof(value.c_str());
        if (valueFloat > 1000) {
            std::cout << "Error: too large a number." << std::endl;
            return false;
        } else if (valueFloat < 0) {
            std::cout << "Error: not a positive number." << std::endl;
            return false;
        }
    } else {
        std::cout << "Error: bad input => " << key << std::endl;
        return false;
    }
    return true;
}

std::string BitcoinExchange::searchNearDate(std::string date) {
    std::string nearDate = _data.begin()->first;
    if (date < _data.begin()->first || date > _data.rbegin()->first)
        return "NULL";
    for (std::map<std::string, float>::iterator it = _data.begin(); it != _data.end(); it++) {
       if (it->first > date) {
           --it;
           nearDate = it->first;
           break;
       }
    }
    return nearDate;
}

void BitcoinExchange::convertRate(std::string &line) {
    line.erase(std::remove(line.begin(), line.end(), ' '), line.end());
    if (line[10] != '|')
        std::cout << "Error: bad input => " << line.substr(0, line.find('|')) << std::endl;
    else if (checkLine(line.substr(0, 10), line.substr(11, line.length() - 11))) {
        float value = atof(line.substr(11, line.length() - 11).c_str());
        if (_data.count(line.substr(0, 10)))
            std::cout << line.substr(0, 10) << " => " << value << " = " << value * _data[line.substr(0, 10)] << std::endl;
        else {
            std::string nearDate = searchNearDate(line.substr(0, 10));
            if (nearDate == "NULL")
                std::cout << "Error: bad input => " << line.substr(0, 10) << std::endl;
            else
                std::cout << line.substr(0, 10) << " => " << value << " = " << value * _data[nearDate] << " (based on " << nearDate << ")" << std::endl;
            }
    }
}

void BitcoinExchange::rate(std::string filename) {
    copyDataInMap("data.csv", "date,exchange_rate", ',');
    for (std::map<std::string, float>::iterator it = _data.begin(); it != _data.end(); it++) {
        try {
            if(!checkDateInMap(it->first))
                throw std::invalid_argument("Error: invalid date format");
        } catch(std::exception &e) {
            throw std::invalid_argument("Error: invalid date format");
        }
    }
    openInput(filename);
}