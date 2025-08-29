#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public virtual ClapTrap {
public:
    // Orthodox Canonical Form
    ScavTrap();
    ScavTrap(const std::string& name);
    ScavTrap(const ScavTrap& other);
    virtual ~ScavTrap();

    ScavTrap& operator=(const ScavTrap& other);

    virtual void attack(const std::string& target);

    void guardGate();
};

#endif
