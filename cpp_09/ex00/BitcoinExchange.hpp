#pragma once

#include <iostream>
#include <sstream>
#include <stdexcept>
#include <cctype>
#include <map>
#include <string>
#include <fstream>

#define BLUE  "\033[1;94m"
#define YELLOW  "\033[1;33m"
#define WHITE   "\033[1;97m"
#define GREEN "\033[1;32m"

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
    void findRate() const;
};
