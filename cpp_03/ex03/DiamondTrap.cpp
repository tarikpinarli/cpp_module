#include "DiamondTrap.hpp"

// Default
DiamondTrap::DiamondTrap()
    // With virtual inheritance, the MOST-derived class must construct ClapTrap
    : ClapTrap("default_clap_name"), ScavTrap("default"), FragTrap("default"), _name("default")
{
    // Stats: HP from FragTrap, EP from ScavTrap, AD from FragTrap
    _hitPoints    = 100; // FragTrap default
    _energyPoints = 50;  // ScavTrap default
    _attackDamage = 30;  // FragTrap default

    std::cout << "[DiamondTrap] Default ctor: '" << _name << "' created\n";
}

// Param
DiamondTrap::DiamondTrap(const std::string& name)
    : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), _name(name)
{
    _hitPoints    = 100; // FragTrap
    _energyPoints = 50;  // ScavTrap
    _attackDamage = 30;  // FragTrap

    std::cout << "[DiamondTrap] Param ctor: '" << _name << "' created\n";
}

// Copy
DiamondTrap::DiamondTrap(const DiamondTrap& other)
    : ClapTrap(other), ScavTrap(other), FragTrap(other), _name(other._name)
{
    // Copy base part already done by base copy-ctors; just ensure stats mirror source
    _hitPoints    = other._hitPoints;
    _energyPoints = other._energyPoints;
    _attackDamage = other._attackDamage;

    std::cout << "[DiamondTrap] Copy ctor: '" << _name << "' cloned\n";
}

DiamondTrap::~DiamondTrap()
{
    std::cout << RED << "[DiamondTrap] Dtor: '" << _name << "' destroyed\n" << RESET;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
    if (this != &other) {
        // Let bases assign their parts
        ScavTrap::operator=(other);
        FragTrap::operator=(other);
        _name         = other._name;
        _hitPoints    = other._hitPoints;
        _energyPoints = other._energyPoints;
        _attackDamage = other._attackDamage;
    }
    std::cout << "[DiamondTrap] Copy assign: '" << _name << "'\n";
    return *this;
}

void DiamondTrap::whoAmI()
{
    std::cout << "[DiamondTrap] name='" << _name
              << "', ClapTrap name='" << ClapTrap::_name << "'\n";
}
