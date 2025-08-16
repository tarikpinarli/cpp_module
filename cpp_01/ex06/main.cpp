#include "Harl.hpp"
#include <iostream>
#include <string>

static int levelIndex(const std::string& s) {
    const char* levels[] = { "DEBUG", "INFO", "WARNING", "ERROR" };
    for (int i = 0; i < 4; ++i)
    {
        if (s == levels[i])
            return i;
    }
    return -1;
}

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cout << "[ Probably complaining about insignificant problems ]\n";
        return 0;
    }
    Harl harl;
    switch (levelIndex(argv[1])) {
        case 0:
            harl.complain("DEBUG");
        case 1:
            harl.complain("INFO");
        case 2:
            harl.complain("WARNING");
        case 3:
            harl.complain("ERROR");
            break;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]\n";
    }
    return 0;
}
