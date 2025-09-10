#include "ASpell.hpp"

ASpell::ASpell(const std::string _name, const std::string _effects) : name(_name), effects(_effects) {}

ASpell::~ASpell() {}

std::string ASpell::getName() {
    return this->name;
}

std::string ASpell::getEffects() {
    return this->name;
}

