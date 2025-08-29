#include "FragTrap.hpp"

FragTrap::FragTrap () : ClapTrap("default"){
    std::cout << WHITE << "Default constructor called 'FragTrap " << _name << "' created." << RESET << std::endl;
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name){
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
    std::cout << WHITE << "Custom constructor called 'FragTrap " << _name << "' created." << RESET << std::endl;
}

FragTrap::FragTrap (const FragTrap& other) : ClapTrap(other){
    std::cout << "Copy constructor called 'FragTrap " << _name << "' created.\n";
}

FragTrap::~FragTrap()
{
    std::cout << RED << "Destructor called 'FragTrap " << _name << "' destroyed.\n" << RESET;
}

FragTrap& FragTrap::operator=(const FragTrap& other) {
    if (this != &other) {
        _name = other._name;
        _hitPoints = other._hitPoints;
        _energyPoints = other._energyPoints;
        _attackDamage = other._attackDamage;
    }
    std::cout << "[FragTrap] Copy assignment operator called. '" << _name << "' created." << std::endl;
    return *this;
}

void FragTrap::highFivesGuys(void) {
    std::cout << WHITE;
    if (_hitPoints <= 0) {
        std::cout << "FragTrap " << _name << " cannot HIGH FIVE: no HP left!\n";
        std::cout << WHITE;
        return;
    }
    if (_energyPoints <= 0) {
        std::cout << "FragTrap " << _name << " cannot HIGH FIVE: no energy!\n";
        std::cout << WHITE;
        return;
    }
    --_energyPoints;
    std::cout << BYELLOW << "FragTrap " << _name << " says HIGH FIVE GUYS!!" << WHITE << std::endl;
}
