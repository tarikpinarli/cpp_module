// Cat.cpp
#include "Cat.hpp"
#include <iostream>

Cat::Cat() : Animal(), brain(new Brain()) {
    _type = "Cat";
    std::cout << "[Cat] Default constractor called. brain@" << brain << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other), brain(new Brain(*other.brain)) {
    std::cout << "[Cat] Copy constractor called. this->brain@" << brain
              << " other.brain@" << other.brain << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
    if (this != &other) {
        std::cout << "[Cat] Copy assignment begin. old this->brain@" << brain
                  << " other.brain@" << other.brain << std::endl;

        Animal::operator=(other);

        Brain* newBrain = new Brain(*other.brain);   // derin kopya
        std::cout << "[Cat] Copy assignment newBrain@" << newBrain << std::endl;

        delete brain;                                 // eski kaynağı serbest bırak
        brain = newBrain;

        std::cout << "[Cat] Copy assignment done. this->brain@" << brain << std::endl;
    } else {
        std::cout << "[Cat] Copy assignment self-assignment (skipped)\n";
    }
    return *this;
}

Cat::~Cat() {
    std::cout << "[Cat] destroyed (deleting brain@" << brain << ")\n";
    delete brain;
    brain = 0;
}

void Cat::makeSound() const {
    std::cout << "Meow!\n";
}

void Cat::setIdea(int idx, const std::string& idea){
    if (brain) {
        std::cout << "[Cat] setIdea[" << idx << "] on brain@" << brain
                  << " = '" << idea << "'\n";
        brain->setIdea(idx, idea);
    }
}

std::string Cat::getIdea(int idx) const {
    if (!brain) {
        std::string empty;
        return empty;
    } else {
        std::string s = brain->getIdea(idx);
        std::cout << "[Cat] getIdea[" << idx << "] from brain@" << brain
                  << " -> '" << s << "'\n";
        return s;
    }
}
