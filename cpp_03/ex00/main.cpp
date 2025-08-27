#include "ClapTrap.hpp"

#include "ClapTrap.hpp"
#include <iostream>

int main()
{
    std::cout << BLUE << "\n-------------------------------------------\n" << BYELLOW << std::endl;
    ClapTrap a;

    a.attack("Dummy");
    a.takeDamage(5);
    a.beRepaired(3);

    std::cout << BLUE << "\n-------------------------------------------\n" << DGREEN << std::endl;
    ClapTrap b("Legolas");

    b.attack("Orc");
    b.takeDamage(4);
    b.beRepaired(3);

    std::cout << BLUE << "\n-------------------------------------------\n" << MAGENTA << std::endl;
    ClapTrap c(b);

    c.attack("Orc Chief");
    c.takeDamage(8);
    c.beRepaired(1);

    std::cout << BLUE << "\n-------------------------------------------\n" << CYAN << std::endl;
    ClapTrap d;
    d = b;

    d.attack("Orc");
    d.takeDamage(2);
    d.beRepaired(2);

    std::cout << BLUE << "\n-------------------------------------------\n" << YELLOW << std::endl;
    ClapTrap e("Gandalf");
    for (int i = 0; i < 11; ++i)
        e.attack("Sauron");
    e.beRepaired(5);

    std::cout << BLUE << "\n-------------------------------------------\n" << BYELLOW << std::endl;
    ClapTrap f("Frodo");
    f.takeDamage(50);
    f.attack("Sauron");
    f.beRepaired(10);
    f.takeDamage(1);

    std::cout << BLUE << "\n-------------------------------------------\n" << MAGENTA << std::endl;
    ClapTrap g("Gollum");
    g.takeDamage(7);
    g.beRepaired(20);
    for (int i = 0; i < 9; ++i)
        g.attack("Frodo");
    g.attack("Last Swing");
    g.beRepaired(1);

    std::cout << BLUE << "\n-------------------------------------------\n" << GREEN << std::endl;
    ClapTrap h("Sam");
    h.attack("Gollum");
    h.takeDamage(1);
    h.beRepaired(1);

    std::cout << BLUE << "\n-------------------------------------------\n" << RED << std::endl;
    return 0;
}

