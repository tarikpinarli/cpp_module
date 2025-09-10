#include "Warlock.hpp"

Warlock::Warlock(std::string _name, std::string _title) : name(_name), title(_title){
    std::cout << name << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock() {
    std::cout << name << ": My job here is done!" << std::endl;
}

const std::string& Warlock::getName() const {
    return this->name;
}

const std::string& Warlock::getTitle() const{
    return this->title;
}

void Warlock::setTitle(const std::string& _title) {
    title = _title;
}

void Warlock::introduce() const {
    std::cout << name << ": I am " << name << ", "<< title << "!" << std::endl;
}