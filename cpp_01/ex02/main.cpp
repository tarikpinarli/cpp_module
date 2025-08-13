#include <iostream>
#include <string>

#define GREEN "\033[0;32m"
#define RED "\033[0;31m"
#define RESET "\033[0m"

int main() {
    std::string brain = "HI THIS IS BRAIN";
    std::string *stringPTR = &brain;
    std::string &stringREF = brain;

    std::cout << GREEN << "Memory address of the string variable:  " << &brain << std::endl;
    std::cout << "Memory address held by stringPTR:       " << stringPTR << std::endl;
    std::cout << "Memory address held by stringREF:       " << &stringREF << std::endl;

    std::cout << "--------------------------------------------------------" << std::endl;

    std::cout << "Value of the string variable:           " << brain << std::endl;
    std::cout << "Value of the string stringPTR:          " << *stringPTR << std::endl;
    std::cout << "Value of the string stringREF:          " << stringREF << RESET << std::endl;

    return 0;
}
