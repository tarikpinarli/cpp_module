#include "Cat.hpp"

Cat::Cat() : Animal() {
    _type = "Cat";
    std::cout << "[Cat] Default constractor called. (type=" << _type << ")" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other) {
    std::cout << "[Cat] Copy constractor called. (type=" << _type << ")" << std::endl;
}

Cat::~Cat() {
    std::cout << "[Cat] destroyed\n";
}

Cat& Cat::operator=(const Cat& other) {
    if (this != &other)
        Animal::operator=(other);
    std::cout << "[Cat] Copy operator called. (type=" << _type << ")" << std::endl;
    return *this;
}

void Cat::makeSound() const {
    std::cout << "Meow!" << std::endl;
}
