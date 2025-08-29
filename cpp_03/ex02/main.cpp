#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

static void section(const std::string& title) {
    std::cout << BLUE << "\n========== " << title << " ==========\n" << RESET << "\n";
}

// Compact status print (uses ClapTrap getters)
static void printStatus(const ClapTrap& object, const std::string& label) {
    std::cout << CYAN
              << ("[" + label + "] ")
              << "Name: "<< object.getName()
              << " | HP=" << object.getHitPoints()
              << " | EP=" << object.getEnergyPoints()
              << " | AD=" << object.getAttackDamage()
              << RESET << "\n";
}

int main() {

    section("FragTrap Default Constructor");
    {
        FragTrap a;
        printStatus(a, "object a");
    }

    section("FragTrap costum constructor + copy constructor");
    {
        FragTrap b("Alpha");
        printStatus(b, "object b");

        FragTrap c(b);
        printStatus(c, "copy-of-b");
    }

    section("FragTrap custom constructor + some actions");
    {
        FragTrap d("Beta");
        printStatus(d, "object d before actions");

        d.attack("something");
        d.takeDamage(25);
        d.beRepaired(105);
        d.highFivesGuys();
        printStatus(d, "object d after actions");
    }

    section("FragTrap Copy Assignment Operator");
    {
        FragTrap e("Lefty");
        FragTrap f("Righty");
        printStatus(e,  "object e before");
        printStatus(f, "object f before");
        std::cout << MAGENTA << "------------ Manipulate Righty --------------" << RESET << std::endl;
        f.attack("something");
        f.beRepaired(999);
        f.takeDamage(888);
        printStatus(f, "object f after manipulation");
        f = e;
        printStatus(e,  "object e after copy assignment");
        printStatus(f, "object f after copy assignment");
    }

    section("FragTrap Energy test");
    {
        FragTrap g("Theta");
        printStatus(g, "start");
        std::cout << WHITE;
        for (int i = 0; i < 51; ++i)
        {
            g.attack("Void");
            g.highFivesGuys();
        }
        printStatus(g, "object g after drain enrgy");
    }
    section("FragTrap Hit point test");
    {
        FragTrap h("Meta");
        for (int i = 0; i < 7; ++i)
        {
            h.takeDamage(20);
        }
        h.attack("Ghost");
        h.beRepaired(5);
        printStatus(h, "object h after drain hit points");
    }
    return 0;
}
