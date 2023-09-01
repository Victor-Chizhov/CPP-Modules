#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

class BitcoinExchange {

    private:
        map<std::string, float> _rate;

    public:
        BitcoinExchange();
        ~BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &copy);
        BitcoinExchange &operator=(const BitcoinExchange &op);

        void copyInputFile(std::string filename);
};

#endif