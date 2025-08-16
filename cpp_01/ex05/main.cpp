// main.cpp
#include "Harl.hpp"
#include <iostream>

int main(int argc, char** argv) {
    Harl harl;

    if (argc == 2) {
        harl.complain(argv[1]); // örn: ./harl INFO
    } else {
        // Basit smoke test: tüm seviyeleri sırayla deneyelim
        const char* tests[] = { "DEBUG", "INFO", "WARNING", "ERROR", "SILLY" };
        for (size_t i = 0; i < sizeof(tests)/sizeof(tests[0]); ++i) {
            std::cout << "[ " << tests[i] << " ]" << std::endl;
            harl.complain(tests[i]);
            std::cout << "----" << std::endl;
        }
    }
    return 0;
}
