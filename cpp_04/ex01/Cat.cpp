// Cat.cpp
#include "Cat.hpp"
#include <iostream>

Cat::Cat() : Animal(), brain(new Brain()) {
   _type = "Cat";
    std::cout << "[Cat] Default constructor (brain@" << brain << ")\n";
}
Cat::Cat(const Cat& other) : Animal(other), brain(new Brain(*other.brain)) {
    std::cout << "[Cat] Copy constructor (brain@" << brain << ")\n";
}
Cat& Cat::operator=(const Cat& other) {
    if (this != &other) {
        Animal::operator=(other);
        Brain* newBrain = new Brain(*other.brain);
        delete brain;
        brain = newBrain;
    }
    std::cout << "[Cat] Copy assignment\n";
    return *this;
}
Cat::~Cat() {
    std::cout << "[Cat] Destructor deleting brain@" << brain << "\n";
    delete brain;
    brain = 0;
}
void Cat::makeSound() const { std::cout << "Meow!\n"; }
void Cat::setIdea(int idx, const std::string& idea){ if(brain) brain->setIdea(idx, idea); }
std::string Cat::getIdea(int idx) const { return brain ? brain->getIdea(idx) : std::string(); }
