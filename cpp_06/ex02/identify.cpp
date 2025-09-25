#include "identify.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib>  // rand, srand
#include <ctime>    // time

Base* generate(void) {
    static bool start = false;
    if (!start)
    {
        srand(time(0));
        start = true;
    }


    int r = std::rand() % 3;
    if (r == 0)
        return new A;
    if (r == 1)
        return new B;
    return new C;
}

void identify(Base* p) {
    if (!p) {
        std::cout << "Unknown\n";
        return;
    }
    if (dynamic_cast<A*>(p)) {
        std::cout << "A\n";
        return;
    }
    if (dynamic_cast<B*>(p)) {
        std::cout << "B\n";
        return;
    }
    if (dynamic_cast<C*>(p)) {
        std::cout << "C\n";
        return;
    }
    std::cout << "Unknown\n";
}

void identify(Base& p) {
    try {
        (void)dynamic_cast<A&>(p);
        std::cout << "A\n";
        return;
    }
    catch (...) {

    }

    try {
        (void)dynamic_cast<B&>(p);
        std::cout << "B\n";
        return;
    }
    catch (...) {

    }

    try {
        (void)dynamic_cast<C&>(p);
        std::cout << "C\n";
        return;
    }
    catch (...) {

    }
    std::cout << "Unknown\n";
}
