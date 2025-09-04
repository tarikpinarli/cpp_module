#include "Dog.hpp"
#include <iostream>

Dog::Dog() : Animal(), brain(new Brain()) {
    _type = "Dog";
    std::cout << "[Dog] Default constructor (brain@" << brain << ")\n";
}

Dog::Dog(const Dog& other) : Animal(other), brain(new Brain(*other.brain)) {
    std::cout << "[Dog] Copy constructor (brain@" << brain << ")\n";
}

Dog& Dog::operator=(const Dog& other) {
    if (this != &other) {
        Animal::operator=(other);
        Brain* newBrain = new Brain(*other.brain); // derin kopya
        delete brain;
        brain = newBrain;
    }
    std::cout << "[Dog] Copy assignment\n";
    return *this;
}

Dog::~Dog() {
    std::cout << "[Dog] Destructor deleting brain@" << brain << "\n";
    delete brain;
    brain = 0;
}

void Dog::makeSound() const { std::cout << "Woof!\n"; }

void Dog::setIdea(int idx, const std::string& idea) {
    if (!brain) { std::cerr << "[Dog] brain null!\n"; return; }
    brain->setIdea(idx, idea);
}

std::string Dog::getIdea(int idx) const {
    if (!brain) { static std::string empty; return empty; }
    return brain->getIdea(idx);
}
