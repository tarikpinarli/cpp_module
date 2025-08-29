#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>
#include <string>

class DiamondTrap : public ScavTrap, public FragTrap {
private:
    // Must have EXACTLY the same variable name as ClapTrap's (e.g. "_name")
    std::string _name;

public:
    // Orthodox Canonical Form
    DiamondTrap();
    DiamondTrap(const std::string& name);
    DiamondTrap(const DiamondTrap& other);
    virtual ~DiamondTrap();

    DiamondTrap& operator=(const DiamondTrap& other);

    // Pick ScavTrap's attack implementation
    using ScavTrap::attack;

    // New special capacity
    void whoAmI();
};

#endif // DIAMONDTRAP_HPP
