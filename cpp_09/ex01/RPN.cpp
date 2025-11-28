#include "RPN.hpp"
#include <sstream>
#include <stdexcept>
#include <cctype>

RPN::RPN() {}

RPN::RPN(const RPN &other) {
    *this = other;
}

RPN &RPN::operator=(const RPN &other) {
    if (this != &other) {
        _numbers = other._numbers;
    }
    return *this;
}

RPN::~RPN() {}

int RPN::evaluate(const std::string &input) {
    while (!_numbers.empty())
        _numbers.pop();
    std::istringstream iss(input);
    std::string token;
    while (iss >> token) {
        if (token.size() == 1 && (token[0] == '+' || token[0] == '-' ||
                                  token[0] == '*' || token[0] == '/')) {
            if (_numbers.size() < 2)
                throw std::runtime_error("Error");
            int b = _numbers.top(); _numbers.pop();
            int a = _numbers.top(); _numbers.pop();
            int result = 0;

            switch (token[0]) {
                case '+':
                    result = a + b;
                    break;
                case '-':
                    result = a - b;
                    break;
                case '*':
                    result = a * b;
                    break;
                case '/':
                    if (b == 0)
                        throw std::runtime_error("Error");
                    result = a / b;
                    break;
            }
            _numbers.push(result);
        }
        else {
            if (token.size() != 1 || !std::isdigit(token[0]))
                throw std::runtime_error("Error");

            int value = token[0] - '0';
            _numbers.push(value);
        }
    }
    if (_numbers.size() != 1)
        throw std::runtime_error("Error");
    return _numbers.top();
}
