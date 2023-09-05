#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <cstdlib>

class BitcoinExchange {

    private:
        std::map<std::string, float> _data;

        void copyDataInMap(std::string filename, std::string firstString, char delimiter);
        bool checkDateInMap(std::string key);
        void convertRate(std::string &line);
        bool checkLine(std::string key, std::string value);
        bool checkFormatDate(std::string date);
        std::string searchNearDate(std::string date);
        void openInput(std::string filename);
        bool isValidFloat(const std::string& str);

    public:
        BitcoinExchange();
        ~BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &copy);
        BitcoinExchange &operator=(const BitcoinExchange &op);
        void rate(std::string filename);
};


#endif