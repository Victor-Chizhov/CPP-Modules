#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy) {
    *this = copy;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &op) {
    if (this != &op) {
        this->_rate = op._rate;
        this->_data = op._data;
    }
    return *this;
}

bool BitcoinExchange::checkFormatDate(std::string date) {
    if (date.length() != 10 && date[4] != '-' && date[7] != '-')
        return false;
    for (int i = 0; i < 10; i++) {
        if (i != 4 && i != 7 && !isdigit(date[i]))
            return false;
    }
    return true;
}

void BitcoinExchange::copyInputFileInMap(std::string filename, std::map<std::string, float> &map, std::string firstString, char delimiter) {
    std::ifstream inputFile(filename);
    if (!inputFile.is_open())
        throw std::out_of_range("Error: could not open file");

    std::string firstLine;
    std::getline(inputFile, firstLine);
    if (firstLine != firstString)
        throw std::invalid_argument("Error: invalid first line");

    std::string line;
    while(std::getline(inputFile, line)) {
        std::istringstream ss(line);
        std::string key;
        float value;
        if (std::getline(ss, key, delimiter) && ss >> value)
            map[key] = value;
        else
           throw std::invalid_argument("Error: invalid value");
    }
    inputFile.close();
}

bool BitcoinExchange::checkKeyAndValueInMap(std::string key, float value) {
    for (size_t it = 0; it < key.length(); it++) {
        if (!checkFormatDate(key)) {
            std::cout << "Error: bad input => " << key << std::endl;
            return false;
        }
        if (value > 1000) {
            std::cout << "Error: too large a number." << std::endl;
            return false;
        } else if (value < 0) {
            std::cout << "Error: not a positive number." << std::endl;
            return false;
        }
    }
    return true;
}

std::string BitcoinExchange::searchNearDate(std::map<std::string, float> _data, std::string date) {
    std::string nearDate = _data.begin()->first;
    for (std::map<std::string, float>::iterator it = _data.begin(); it != _data.end(); it++) {
        if (it->first < date)
            nearDate = it->first;
    }
    return nearDate;
}

void BitcoinExchange::convertRate(std::map<std::string, float> &_data, std::map<std::string, float> &_rate) {
    for (std::map<std::string, float>::iterator it = _rate.begin(); it != _rate.end(); it++) {
        std::string trimDate = it->first.substr(0, 10);
        if (checkKeyAndValueInMap(trimDate, it->second)) {

            if (_data.count(trimDate))
                std::cout << trimDate << " => " << it->second << " = " << it->second * _data[trimDate] << std::endl;
            else {
                std::string nearDate = searchNearDate(_data, trimDate);
                std::cout << trimDate << " => " << it->second << " = " << it->second * _data[nearDate] <<  std::endl;
            }
        }
    }
}

bool BitcoinExchange::checkDateInMap(std::map<std::string, float>) {

    int years, months, days;

    for (std::map<std::string, float>::iterator it = this->_rate.begin(); it != this->_rate.end(); it++) {
        years = std::stoi(it->first.substr(0, 4));
        months = std::stoi(it->first.substr(5, 2));
        days = std::stoi(it->first.substr(8, 2));
        if(!checkFormatDate(it->first))
            return false;
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
    }
    return true;
}

void BitcoinExchange::rate(std::string filename) {
    copyInputFileInMap("data.csv", _data, "date,exchange_rate", ',');
    copyInputFileInMap(filename, _rate, "date | value", '|');
    checkDateInMap(_data) ? 0 : throw std::invalid_argument("Error: invalid date format");
    convertRate(_data, _rate);
}