#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal() {
    _type = "WrongCat";
    std::cout << "[WrongCat] Default constractor called. (type=" << _type << ")" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other) {
    std::cout << "[WrongCat] Copy constractor called. (type=" << _type << ")" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other) {
    if (this != &other)
        WrongAnimal::operator=(other);
    std::cout << "[WrongCat] Copy operator called. (type=" << _type << ")" << std::endl;
    return *this;
}

WrongCat::~WrongCat() {
    std::cout << "[WrongCat] destroyed" << std::endl;
}
