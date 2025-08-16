// Harl.cpp
#include "Harl.hpp"
#include <iostream>

void Harl::debug(void) {
    std::cout << "[ DEBUG ]\n"
              << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!\n";
}

void Harl::info(void) {
    std::cout << "[ INFO ]\n"
              << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! "
                 "If you did, I wouldn’t be asking for more!\n";
}

void Harl::warning(void) {
    std::cout << "[ WARNING ]\n"
              << "I think I deserve to have some extra bacon for free.\n"
              << "I've been coming for years whereas you started working here since last month.\n";
}

void Harl::error(void) {
    std::cout << "[ ERROR ]\n"
              << "This is unacceptable, I want to speak to the manager now.\n";
}

void Harl::complain(const std::string& level) {
    if (level == "DEBUG")   debug();
    else if (level == "INFO")    info();
    else if (level == "WARNING") warning();
    else if (level == "ERROR")   error();
}
