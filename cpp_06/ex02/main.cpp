#include "identify.hpp"
#include <iostream>

int main() {
    for (int i = 0; i < 3; ++i) {
        Base* p = generate();
        std::cout << "[ptr]  ";
        identify(p);
        std::cout << "[ref]  ";
        identify(*p);
        delete p;
    }
    return 0;
}
