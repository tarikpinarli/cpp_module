#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("WrongAnimal") {
   std::cout << "[WrongAnimal] constructed (type=" << _type << ")" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) : _type(other._type) {
    std::cout << "[WrongAnimal] copy-constructed" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) {
    if (this != &other)
        _type = other._type;
    std::cout << "[WrongAnimal] copy-assigned" << std::endl;
    return *this;
}

WrongAnimal::~WrongAnimal() {
    std::cout << "[WrongAnimal] destroyed" << std::endl;
}

const std::string& WrongAnimal::getType() const{
    return _type;
}

void WrongAnimal::makeSound() const {
    std::cout << "[WrongAnimal] *generic animal noise*" << std::endl;
}

