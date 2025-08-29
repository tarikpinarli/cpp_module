#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"
#include <iostream>

static void section(const std::string& title) {
    std::cout << BLUE << "\n========== " << title << " ==========\n" << RESET << "\n";
}

// Uses ClapTrap getters (works for all derived classes too)
static void printStatus(const ClapTrap& object, const std::string& label) {
    std::cout << CYAN
              << ("[" + label + "] ")
              << "Name: " << object.getName()
              << " | HP=" << object.getHitPoints()
              << " | EP=" << object.getEnergyPoints()
              << " | AD=" << object.getAttackDamage()
              << RESET << "\n";
}

int main() {

    section("DiamondTrap Default Constructor");
    {
        DiamondTrap a;
        printStatus(a, "object a");
        a.whoAmI();
    }

    section("DiamondTrap custom constructor + copy constructor");
    {
        DiamondTrap b("Alpha");
        printStatus(b, "object b");
        b.whoAmI();

        DiamondTrap c(b); // copy-ctor
        printStatus(c, "copy-of-b");
        c.whoAmI();
    }

    section("DiamondTrap custom constructor + some actions");
    {
        DiamondTrap d("Beta");
        printStatus(d, "object d before actions");

        d.attack("Practice Dummy"); // ScavTrap's attack
        d.takeDamage(25);
        d.beRepaired(40);
        d.highFivesGuys(); // FragTrap special
        d.guardGate();     // ScavTrap special
        d.whoAmI();        // DiamondTrap special

        printStatus(d, "object d after actions");
    }

    section("DiamondTrap Copy Assignment Operator");
    {
        DiamondTrap e("Lefty");
        DiamondTrap f("Righty");
        printStatus(e, "object e before");
        printStatus(f, "object f before");

        std::cout << MAGENTA << "------------ Manipulate Righty --------------" << RESET << std::endl;
        f.attack("Target");
        f.beRepaired(15);
        f.takeDamage(60);
        f.highFivesGuys();
        f.guardGate();
        printStatus(f, "object f after manipulation");

        f = e; // copy assignment
        printStatus(e, "object e after copy assignment");
        printStatus(f, "object f after copy assignment");
        f.whoAmI();
    }

    section("DiamondTrap Energy test (EP from ScavTrap)");
    {
        DiamondTrap g("Theta");
        printStatus(g, "start");
        std::cout << WHITE;
        for (int i = 0; i < 55; ++i) {
            g.attack("Void");
        }
        std::cout << RESET;
        printStatus(g, "object g after energy drain");
    }

    section("DiamondTrap Hit point test (HP/AD from FragTrap)");
    {
        DiamondTrap h("Meta");
        for (int i = 0; i < 5; ++i) {
            h.takeDamage(25); // 5 * 25 = 125 → should hit 0
        }
        h.attack("Ghost");   // should fail: 0 HP
        h.beRepaired(5);     // should fail: 0 HP
        printStatus(h, "object h after HP drain");
        h.whoAmI();
    }

    section("Upcast Polymorphism Check (DiamondTrap -> ClapTrap&)");
    {
        DiamondTrap p("Poly");
        ClapTrap& baseRef = p; // upcast
        baseRef.attack("TargetA"); // should dispatch to ScavTrap::attack if 'attack' is virtual in base
        printStatus(p, "after virtual attack");
    }
    return 0;
}
