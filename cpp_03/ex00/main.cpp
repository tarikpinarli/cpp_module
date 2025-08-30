#include "ClapTrap.hpp"

#include "ClapTrap.hpp"
#include <iostream>

void printAll(const ClapTrap& s1) {
    std::cout   << CYAN << "Name: " << s1.getName() << YELLOW
            << "   hitPoints: " << s1.getHitPoints() << MAGENTA
            << "   energyPoints: " << s1.getEnergyPoints() << BLUE
            << "   attackDamage: " << s1.getAttackDamage() << WHITE << std::endl;
}

int main()
{
    {
    std::cout << BLUE << "\n-------------------------------------------\n" << BYELLOW << std::endl;
    ClapTrap a;

    printAll(a);
    a.attack("Dummy");
    a.takeDamage(5);
    a.beRepaired(3);
    printAll(a);
    }
    {
    std::cout << BLUE << "\n-------------------------------------------\n" << DGREEN << std::endl;
    ClapTrap b("Legolas");

    printAll(b);
    b.attack("Orc");
    b.takeDamage(4);
    b.beRepaired(3);
    printAll(b);
    }
    {
    std::cout << BLUE << "\n-------------------------------------------\n" << MAGENTA << std::endl;
    ClapTrap b("Legolas");
    ClapTrap c(b);

    printAll(c);
    c.attack("Orc Chief");
    c.takeDamage(8);
    c.beRepaired(1);
    printAll(c);
    }
    {
    std::cout << BLUE << "\n-------------------------------------------\n" << CYAN << std::endl;
    ClapTrap d;
    ClapTrap c("clone");
    printAll(d);
    d = c;

    printAll(d);
    d.attack("Orc");
    d.takeDamage(2);
    d.beRepaired(2);
    printAll(d);
    }
    {
    std::cout << BLUE << "\n-------------------------------------------\n" << YELLOW << std::endl;
    ClapTrap e("Gandalf");
    printAll(e);
    for (int i = 0; i < 11; ++i)
        e.attack("Sauron");
    e.beRepaired(5);
    printAll(e);
    }
    {
    std::cout << BLUE << "\n-------------------------------------------\n" << BYELLOW << std::endl;
    ClapTrap f("Frodo");
    printAll(f);
    f.takeDamage(50);
    f.attack("Sauron");
    f.beRepaired(10);
    f.takeDamage(1);
    printAll(f);
    }
    {
    std::cout << BLUE << "\n-------------------------------------------\n" << MAGENTA << std::endl;
    ClapTrap g("Gollum");
    printAll(g);
    g.takeDamage(7);
    g.beRepaired(20);
    for (int i = 0; i < 9; ++i)
        g.attack("Frodo");
    g.attack("Legolas");
    g.beRepaired(1);
    printAll(g);
    }
    {
    std::cout << BLUE << "\n-------------------------------------------\n" << GREEN << std::endl;
    ClapTrap h("Sam");
    printAll(h);
    h.attack("Gollum");
    h.takeDamage(1);
    h.beRepaired(1);
    printAll(h);
    }
    std::cout << BLUE << "\n-------------------------------------------\n" << RED << std::endl;
    return 0;
}

