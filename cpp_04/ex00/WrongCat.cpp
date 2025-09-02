#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal() {
    _type = "WrongCat";
    std::cout << "[WrongCat] constructed (type=" << _type << ")" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other) {
    std::cout << "[WrongCat] copy-constructed" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other) {
    if (this != &other)
        WrongAnimal::operator=(other);
    std::cout << "[WrongAnimal] copy-assigned" << std::endl;
    return *this;
}

WrongCat::~WrongCat() {
    std::cout << "[WrongCat] destroyed" << std::endl;
}
