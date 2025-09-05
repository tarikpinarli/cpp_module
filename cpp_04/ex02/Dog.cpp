// Dog.cpp
#include "Dog.hpp"
#include <iostream>

Dog::Dog() : Animal(), brain(new Brain()) {
    _type = "Dog";
    std::cout << "[Dog] Default constractor called. brain@" << brain << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other), brain(new Brain(*other.brain)) {
    std::cout << "[Dog] Copy constractor called. this->brain@" << brain
              << " other.brain@" << other.brain << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
    if (this != &other) {
        std::cout << "[Dog] Copy assignment begin. old this->brain@" << brain
                  << " other.brain@" << other.brain << std::endl;

        Animal::operator=(other);

        Brain* newBrain = new Brain(*other.brain);
        std::cout << "[Dog] Copy assignment newBrain@" << newBrain << std::endl;
        delete brain;
        brain = newBrain;

        std::cout << "[Dog] Copy assignment done. this->brain@" << brain << std::endl;
    } else {
        std::cout << "[Dog] Copy assignment self-assignment (skipped)\n";
    }
    return *this;
}

Dog::~Dog() {
    std::cout << "[Dog] destroyed (deleting brain@" << brain << ")\n";
    delete brain;
    brain = 0;
}

void Dog::makeSound() const {
    std::cout << "Woof!\n";
}

void Dog::setIdea(int idx, const std::string& idea) {
    if (!brain) {
        std::cout << "[Dog] brain null!\n";
        return;
    }
    std::cout << "[Dog] setIdea[" << idx << "] on brain@" << brain
              << " = '" << idea << "'\n";
    brain->setIdea(idx, idea);
}

std::string Dog::getIdea(int idx) const {
    if (!brain) { static std::string empty; return empty; }
    std::string s = brain->getIdea(idx);
    std::cout << "[Dog] getIdea[" << idx << "] from brain@" << brain
              << " -> '" << s << "'\n";
    return s;
}
