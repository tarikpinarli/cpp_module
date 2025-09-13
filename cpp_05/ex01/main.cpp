#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main() {
    try {
        Form FoodDelivery;

        std::cout << FoodDelivery;
        Bureaucrat intern;

        intern.signForm(FoodDelivery);
    }
    catch (const std::exception& e)
    {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }
    // try {
    //     Form fA("Permit-A", 50, 20);
    //     Form fB("TopSecret", 10, 1);
    //     std::cout << fA << "\n" << fB << "\n";
    //     Bureaucrat Boss("Boss", 1);
    //     Boss.signForm(fA);
    // }
    // catch (const std::exception& e) {
    //     std::cout << "Caught exception: " << e.what() << "\n";
    // }
    return 0;
}
