#include "Bureaucrat.hpp"
#include <iostream>
#include <exception>

int main() {
    try {
        std::cout << "Inside try block\n";

        // Something goes wrong → throw an exception
        throw std::runtime_error("Something bad happened!");

        std::cout << "This line will NOT run\n";
    }
    catch (std::exception& e) {
        std::cout << "Caught an exception: " << e.what() << std::endl;
    }

    std::cout << "Program continues after catch\n";
}

