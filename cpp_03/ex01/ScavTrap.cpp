#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
    : ClapTrap("noname-Scav")
{
    _hitPoints    = 100;
    _energyPoints = 50;
    _attackDamage = 20;
    std::cout << WHITE << "Default constructor called 'ScavTrap " << _name << "' created." << RESET << std::endl;
}

ScavTrap::ScavTrap(const std::string& name)
    : ClapTrap(name)
{
    _hitPoints    = 100;
    _energyPoints = 50;
    _attackDamage = 20;
    std::cout << WHITE << "Custom constructor called 'ScavTrap " << _name << "' created." << RESET << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other)
    : ClapTrap(other) // base kopyalanır; HP/EP/AD de diğerinden gelir
{
    std::cout << "Copy constructor called 'ScavTrap " << _name << "' duplicated\n";
}

ScavTrap::~ScavTrap()
{
    std::cout << "Destructor called 'ScavTrap " << _name << "' destroyed.\n";
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
    if (this != &other) {
        _name = other._name;
        _hitPoints = other._hitPoints;
        _energyPoints = other._energyPoints;
        _attackDamage = other._attackDamage;
    }
    std::cout << "[ScavTrap] Copy assignment operator called. '" << _name << "' created." << std::endl;
    return *this;
}

void ScavTrap::attack(const std::string& target)
{
    std::cout << BYELLOW;
    if (_hitPoints <= 0) {
        std::cout << "ScavTrap " << _name << " cannot attack: no HP left!\n";
        std::cout << RESET;
        return;
    }
    if (_energyPoints <= 0) {
        std::cout << "ScavTrap " << _name << " cannot attack: no energy!\n";
        std::cout << RESET;
        return;
    }
    --_energyPoints;
    std::cout << "ScavTrap " << _name << " attacks " << target
              << ", causing " << _attackDamage << " points of damage!" << std::endl;
    std::cout << RESET;
}

void ScavTrap::guardGate()
{
    std::cout << WHITE;
    if (_hitPoints <= 0) {
        std::cout << "ScavTrap " << _name << " cannot guard: no HP left!\n";
        std::cout << RESET;
        return;
    }
    if (_energyPoints <= 0) {
        std::cout << "ScavTrap " << _name << " cannot guard: no energy left!\n";
        std::cout << RESET;
        return;
    }
    --_energyPoints;
    std::cout << "[ScavTrap] " << _name << " is now in Gate Keeper mode!\n";
}
