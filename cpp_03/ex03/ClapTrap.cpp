#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("no-name"), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
    std::cout << "Default constructor called 'ClapTrap " << _name << "' created." << std::endl;
}

ClapTrap::ClapTrap(const std::string& n)
    : _name(n), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
    std::cout << WHITE << "Custom constructor called 'ClapTrap " << _name << "' created.\n" << RESET;
}

ClapTrap::ClapTrap(const ClapTrap& other) : _name(other._name), _hitPoints(other._hitPoints),
                    _energyPoints(other._energyPoints), _attackDamage(other._attackDamage) {
    std::cout << "Copy constructor called 'ClapTrap " << _name << "' created.\n";
}
ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
    if (this != &other) {
        _name = other._name;
        _hitPoints = other._hitPoints;
        _energyPoints = other._energyPoints;
        _attackDamage = other._attackDamage;
    }
    std::cout << "Copy assignment operator called. '" << _name << "' created." << std::endl;
    return *this;
}

ClapTrap::~ClapTrap()
{
    std::cout << RED << "Destructor called 'ClapTrap " << _name << "' destroyed.\n" << RESET;
}

void ClapTrap::attack(const std::string& target)
{
    if (_hitPoints == 0) {
        std::cout << "ClapTrap " << _name << " cannot attack: no HP left!\n";
        return;
    }
    if (_energyPoints == 0) {
        std::cout << "ClapTrap " << _name << " cannot attack: no energy left!\n";
        return;
    }
    --_energyPoints;
    std::cout << "ClapTrap " << _name << " attacks " << target
              << ", causing " << _attackDamage << " points of damage!\n";
}

void ClapTrap::takeDamage(unsigned int amount)
{
    std::cout << WHITE;
    if (_hitPoints == 0) {
        std::cout << "ClapTrap " << _name << " is already at 0 HP.\n";
        return;
    }
    if (amount >= _hitPoints) {
        _hitPoints = 0;
    } else {
        _hitPoints -= amount;
    }
    std::cout << "ClapTrap " << _name << " takes " << amount
              << " points of damage.\n";
    std::cout << RESET;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    std::cout << WHITE;
    if (_hitPoints == 0) {
        std::cout << "ClapTrap " << _name << " cannot repair: no HP left!\n";
        return;
    }
    if (_energyPoints == 0) {
        std::cout << "ClapTrap " << _name << " cannot repair: no energy left!\n";
        return;
    }
    --_energyPoints;
    _hitPoints += amount;
    std::cout << "ClapTrap " << _name << " repairs itself for "
              << amount << " points.\n";
    std::cout << RESET;
}
// Getters:
const std::string& ClapTrap::getName() const {
    return _name;
}

unsigned int ClapTrap::getHitPoints() const {
    return _hitPoints;
}

unsigned int ClapTrap::getEnergyPoints() const {
    return _energyPoints;
}

unsigned int ClapTrap::getAttackDamage() const {
    return _attackDamage;
}
