#include <iostream>
#include <string>

#define GREEN "\033[0;32m"
#define RED "\033[0;31m"
#define RESET "\033[0m"

using std::string;
using std::cout;
using std::endl;

int main() {
    string brain = "HI THIS IS BRAIN";
    string *stringPTR = &brain;
    string &stringREF = brain;

    cout << GREEN << "Memory address of the string variable:  " << &brain << endl;
    cout << "Memory address held by stringPTR:       " << stringPTR << endl;
    cout << "Memory address held by stringREF:       " << &stringREF << endl;

    cout << "--------------------------------------------------------" << endl;

    cout << "Value of the string variable:           " << brain << endl;
    cout << "Value of the string stringPTR:          " << *stringPTR << endl;
    cout << "Value of the string stringREF:          " << stringREF << RESET << endl;

    return 0;
}
