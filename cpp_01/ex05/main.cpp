// main.cpp
#include "Harl.hpp"
#include <iostream>

int main(int argc, char** argv) {
    Harl harl;

    if (argc == 2) {
        harl.complain(argv[1]);
    } else {
        std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
    }
    return 0;
}
