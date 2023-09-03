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
        std::map<std::string, float> _rate;
        std::map<std::string, float> _data;

        void copyInputFileInMap(std::string filename, std::map<std::string, float> &map, std::string firstString, char delimiter);
        bool checkDateInMap(std::map<std::string, float>);
        void convertRate(std::map<std::string, float>&, std::map<std::string, float>&);
        bool checkKeyAndValueInMap(std::string key, float value);
        bool checkFormatDate(std::string date);
        std::string searchNearDate(std::map<std::string, float> _data, std::string date);

    public:
        BitcoinExchange();
        ~BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &copy);
        BitcoinExchange &operator=(const BitcoinExchange &op);
        void rate(std::string filename);
};

#endif