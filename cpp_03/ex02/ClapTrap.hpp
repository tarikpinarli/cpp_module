
#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>
#include <iostream>

#define CYAN    "\033[1;36m"
#define BLINKRED   "\033[1;5;31m"
#define RED   "\033[1;31m"
#define GREEN "\033[1;92m"
#define DGREEN "\033[1;32m"
#define BLUE  "\033[1;94m"
#define YELLOW  "\033[1;33m"
#define BYELLOW   "\033[1;93m"
#define MAGENTA "\033[1;35m"
#define WHITE   "\033[1;97m"
#define RESET "\033[0m"

class ClapTrap {
protected:
    std::string   _name;
    unsigned int  _hitPoints;
    unsigned int  _energyPoints;
    unsigned int  _attackDamage;

public:
    ClapTrap();
    ClapTrap(const ClapTrap& other);
    ClapTrap& operator=(const ClapTrap& other);
    virtual ~ClapTrap();

    ClapTrap(const std::string& name);
    virtual void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);

    //Getters
    const std::string& getName() const;
    unsigned int       getHitPoints() const;
    unsigned int       getEnergyPoints() const;
    unsigned int       getAttackDamage() const;
};

#endif
