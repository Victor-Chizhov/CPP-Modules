#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy) {
    *this = copy;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &op) {
    if (this != &op) {
        this->_rate = op._rate;
    }
    return *this;
}

void BitcoinExchange::copyInputFile(std::string filename) {

}


