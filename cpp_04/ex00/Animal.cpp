#include "Animal.hpp"

Animal::Animal() : _type("Animal") {
    std::cout << "[Animal] constructed (type=" << _type << ")" << std::endl;
}

Animal::Animal(const Animal& other) : _type(other._type) {
    std::cout << "[Animal] copy-constructed" << std::endl;
}

Animal& Animal::operator=(const Animal& other) {
    if (this != &other)
        _type = other._type;
    std::cout << "[Animal] copy-assigned" << std::endl;
    return *this;
}

Animal::~Animal() {
    std::cout << "[Animal] destroyed" << std::endl;
}

const std::string& Animal::getType() const {
    return _type;
}

void Animal::makeSound() const {
    std::cout << "[Animal] *generic animal noise*" << std::endl;
}
