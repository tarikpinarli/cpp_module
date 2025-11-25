#pragma once

#include <iostream>
#include <sstream>
#include <stdexcept>
#include <cctype>
#include <map>
#include <string>
#include <fstream>

class BitcoinExchange {
private:
    std::string _inputFile;
    std::string _dataFile;
    std::map<std::string, float> _rates;
public:
    BitcoinExchange(std::string inputFile);
    ~BitcoinExchange();

    std::string& getDataFileName();
    std::string& getInputFileName();
    void loadData(const std::string &filename);
    void printRates() const;
};
