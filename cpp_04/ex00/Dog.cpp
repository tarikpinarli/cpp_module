#include "Dog.hpp"

Dog::Dog() : Animal() {
    _type = "Dog";
    std::cout << "[Dog] constructed (type=" << _type << ")" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other) {
    std::cout << "[Dog] copy-constructed" << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
    if (this != &other)
        Animal::operator=(other);
    std::cout << "[Dog] copy-assigned" << std::endl;
    return *this;
}

Dog::~Dog() {
    std::cout << "[Dog] destroyed\n";
}

void Dog::makeSound() const {
    std::cout << "Woof!" << std::endl;
}
