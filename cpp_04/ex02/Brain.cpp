#include "Brain.hpp"

Brain::Brain() {
    std::cout << "[Brain] constructed\n";
}

Brain::Brain(const Brain& other) {
    std::cout << "[Brain] copy-constructed\n";
    for (int i = 0; i < 100; ++i)
        ideas[i] = other.ideas[i];
}

Brain& Brain::operator=(const Brain& other) {
    if (this != &other) {
        for (int i = 0; i < 100; ++i)
            ideas[i] = other.ideas[i];
    }
    std::cout << "[Brain] copy-assigned\n";
    return *this;
}

Brain::~Brain() {
    std::cout << "[Brain] destroyed\n";
}

void Brain::setIdea(int index, const std::string& idea) {
    if (index < 0 || index >= 100) {
        std::cout << "[Brain] setIdea: index out of range\n";
        return;
    }
    ideas[index] = idea;
}

const std::string& Brain::getIdea(int index) const {
    static const std::string empty;
    if (index < 0 || index >= 100) {
        std::cout << "[Brain] getIdea: index out of range\n";
        return empty;
    }
    return ideas[index];
}