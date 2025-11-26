#include "BitcoinExchange.hpp"
#include <sstream>
#include <iostream>
#include <stdexcept>
#include <climits>
#include <cstdlib>


BitcoinExchange::BitcoinExchange(std::string inputFile) : _inputFile(inputFile), _dataFile("data.csv"){}
BitcoinExchange::~BitcoinExchange() {}

std::string& BitcoinExchange::getDataFileName() {
    return _dataFile;
}

std::string& BitcoinExchange::getInputFileName() {
    return _dataFile;
}



static std::string trim(const std::string &s)
{
    std::string::size_type start = 0;
    while (start < s.size() && (s[start] == ' ' || s[start] == '\t'))
        ++start;

    std::string::size_type end = s.size();
    while (end > start && (s[end - 1] == ' ' || s[end - 1] == '\t'))
        --end;

    return s.substr(start, end - start);
}

static bool isValidDate(const std::string &date)
{
    if (date.size() != 10)
        return false;
    if (date[4] != '-' || date[7] != '-')
        return false;

    for (int i = 0; i < 10; ++i) {
        if (i == 4 || i == 7)
            continue;
        if (date[i] < '0' || date[i] > '9')
            return false;
    }

    int year  = std::atoi(date.substr(0, 4).c_str());
    int month = std::atoi(date.substr(5, 2).c_str());
    int day   = std::atoi(date.substr(8, 2).c_str());

    if (year < 0)
        return false;
    if (month < 1 || month > 12)
        return false;
    if (day < 1 || day > 31)
        return false;
    return true;
}

void BitcoinExchange::findRate() const
{
    std::ifstream inputLine("input.txt");
    if (!inputLine.is_open())
        throw std::runtime_error("Error: could not open the input file");

    std::string line;
    bool firstLine = true;

    while (std::getline(inputLine, line))
    {
        if (firstLine) {
            firstLine = false;
            continue;
        }

        if (line.empty())
            continue;
        std::string::size_type pipePos = line.find('|');
        if (pipePos == std::string::npos) {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }
        std::string dateStr   = trim(line.substr(0, pipePos));
        std::string valueStr  = trim(line.substr(pipePos + 1));
        if (!isValidDate(dateStr)) {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }
        if (valueStr.empty()) {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }

        std::stringstream ss(valueStr);
        double value;
        if (!(ss >> value)) {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }
        if (value < 0.0) {
            std::cout << "Error: not a positive number." << std::endl;
            continue;
        }
        if (value > static_cast<double>(INT_MAX)) {
            std::cout << "Error: too large number." << std::endl;
            continue;
        }
        float fvalue = static_cast<float>(value);
        std::map<std::string, float>::const_iterator it = _rates.lower_bound(dateStr);
        if (it == _rates.end()) {
            if (_rates.empty()) {
                std::cout << "Error: no rate data." << std::endl;
                continue;
            }
            --it;
        } else if (it->first != dateStr) {
            if (it == _rates.begin()) {
                std::cout << "Error: no rate for date " << dateStr << std::endl;
                continue;
            }
            --it;
        }
        float rate   = it->second;
        float result = rate * fvalue;
        std::cout << dateStr << " => " << fvalue << " = " << result << std::endl;
    }
}



void BitcoinExchange::printRates() const
{
    std::map<std::string, float>::const_iterator it = _rates.begin();
    std::map<std::string, float>::const_iterator end = _rates.end();

    for (; it != end; ++it) {
        std::cout << it->first << " => " << it->second << std::endl;
    }
}


static bool parseLine(const std::string &line, std::string &date, float &value)
{
    if (line.empty())
        return false;

    std::string::size_type pos = line.find(',');
    if (pos == std::string::npos)
        return false;

    date = line.substr(0, pos);
    std::string valueStr = line.substr(pos + 1);
    while (!valueStr.empty() && (valueStr[0] == ' ' || valueStr[0] == '\t'))
        valueStr.erase(0, 1);
    while (!valueStr.empty() &&
           (valueStr[valueStr.size() - 1] == ' ' || valueStr[valueStr.size() - 1] == '\t'))
        valueStr.erase(valueStr.size() - 1);
    std::stringstream ss(valueStr);
    ss >> value;
    if (ss.fail())
        return false;

    return true;
}

void BitcoinExchange::loadData(const std::string &filename)
{
    std::ifstream file(filename.c_str());
    if (!file.is_open())
        throw std::runtime_error("Error: could not open data file");

    std::string line;
    if (std::getline(file, line)) {
        if (!line.empty() && !std::isdigit(line[0])) {
        } else {
            std::string date;
            float value;
            if (parseLine(line, date, value))
                this->_rates[date] = value;
        }
    }
    while (std::getline(file, line)) {
        std::string date;
        float value;
        if (!parseLine(line, date, value))
            continue;
        this->_rates[date] = value;
    }

    file.close();
}
