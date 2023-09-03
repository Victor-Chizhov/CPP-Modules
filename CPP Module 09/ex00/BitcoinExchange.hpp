#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <fstream>
#include <sstream>

class BitcoinExchange {

    private:
        std::map<std::string, std::string> _rate;
        std::map<std::string, float> _data;

        void copyDataInMap(std::string filename, std::map<std::string, float> &map, std::string firstString, char delimiter);
        bool checkDateInMap(std::string key);
        void convertRate();
        bool checkKeyAndValueInMap(std::string key, std::string value);
        bool checkFormatDate(std::string date);
        std::string searchNearDate(std::map<std::string, float> _data, std::string date);
        void copyInputInMap(std::map<std::string, std::string>&, std::string filename);

    public:
        BitcoinExchange();
        ~BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &copy);
        BitcoinExchange &operator=(const BitcoinExchange &op);
        void rate(std::string filename);
};


#endif