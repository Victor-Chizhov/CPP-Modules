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

bool BitcoinExchange::checkDateInMap(std::string key) {
    int years = std::stoi(key.substr(0, 4));
    int months = std::stoi(key.substr(5, 2));
    int days = std::stoi(key.substr(8, 2));
    if(!checkFormatDate(key))
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
    return true;
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

void BitcoinExchange::copyDataInMap(std::string filename, std::map<std::string, float> &map, std::string firstString, char delimiter) {
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

void BitcoinExchange::copyInputInMap(std::map<std::string, std::string> &_rate, std::string filename) {
    std::ifstream inputFile(filename);
    if (!inputFile.is_open())
        throw std::out_of_range("Error: could not open file");

    std::string firstLine;
    std::getline(inputFile, firstLine);
    if (firstLine != "date | value")
        throw std::invalid_argument("Error: invalid first line");

    std::string line;
    while(std::getline(inputFile, line)) {
        size_t pos = line.find(' ');
        if (pos != std::string::npos) {
            size_t secondPos = line.find(' ', pos + 1);
            if (secondPos != std::string::npos) {
                std::string key = line.substr(0, secondPos);
                std::string value = line.substr(secondPos + 1);
                _rate[key] = value;
            }
            else
                _rate[line] = "nullptr";
        }
        else
            _rate[line] = "nullptr";
    }
    inputFile.close();
}

bool BitcoinExchange::checkKeyAndValueInMap(std::string key, std::string value) {
    float valueFloat;
    for (size_t it = 0; it < key.length(); it++) {
        try {
            valueFloat = std::stof(value);
        } catch (std::exception &e) {
            std::cout << "Error: bad input => " << key << std::endl;
            return false;
        }
        if (!checkDateInMap(key)) {
            std::cout << "Error: bad input => " << key << std::endl;
            return false;
        }
        if (valueFloat > 1000) {
            std::cout << "Error: too large a number." << std::endl;
            return false;
        } else if (valueFloat < 0) {
            std::cout << "Error: not a positive number." << std::endl;
            return false;
        }
    }
    return true;
}

std::string BitcoinExchange::searchNearDate(std::map<std::string, float> _data, std::string date) {
    std::string nearDate = _data.begin()->first;
    if (date < _data.begin()->first || date > _data.rbegin()->first)
        return "nullptr";
    for (std::map<std::string, float>::iterator it = _data.begin(); it != _data.end(); it++) {
       if (it->first > date) {
           --it;
           nearDate = it->first;
           break;
       }
    }
    return nearDate;
}

void BitcoinExchange::convertRate() {
    for (std::map<std::string, std::string>::iterator it = _rate.begin(); it != _rate.end(); it++) {

        if (it->first.length() != 12  || it->first[11] != '|') {
            std::cout << "Error: bad input => " << it->first.substr(0, 10) << std::endl;
            continue;
        }
        std::string trimDate = it->first.substr(0, 10);
        if (checkKeyAndValueInMap(trimDate, it->second)) {
            float valueFloat = std::stof(it->second);
            if (_data.count(trimDate))
                std::cout << trimDate << " => " << valueFloat << " = " << valueFloat * _data[trimDate] << std::endl;
            else {
                std::string nearDate = searchNearDate(_data, trimDate);
                if (nearDate == "nullptr")
                    std::cout << "Error: bad input => " << trimDate << std::endl;
                else
                    std::cout << trimDate << " => " << valueFloat << " = " << valueFloat * _data[nearDate] << " (based on " << nearDate << ")" << std::endl;
            }
        }
    }
}

void BitcoinExchange::rate(std::string filename) {
    copyDataInMap("data.csv", _data, "date,exchange_rate", ',');
    copyInputInMap(_rate, filename);
    for (std::map<std::string, float>::iterator it = _data.begin(); it != _data.end(); it++) {
        try {
            if(!checkDateInMap(it->first))
                throw std::invalid_argument("Error: invalid date format");
        } catch(std::exception &e) {
            throw std::invalid_argument("Error: invalid date format");
        }
    }
    convertRate();
}