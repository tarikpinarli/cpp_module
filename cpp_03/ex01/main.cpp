#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

void printAll(const ScavTrap& s1) {
    std::cout   << CYAN << "Name: " << s1.getName() << YELLOW
            << "   hitPoints: " << s1.getHitPoints() << MAGENTA
            << "   energyPoints: " << s1.getEnergyPoints() << BLUE
            << "   attackDamage: " << s1.getAttackDamage() << RESET << std::endl;
}

int main()
{
    {
        ScavTrap s1("Night King");

        printAll(s1);
        std::cout << std::endl;
        std::cout << BLUE << "\n---------------------------Hit Points Test-----------------------------\n" << RESET << std::endl;
        for (int i = 0; i < 14; ++i)
        {
            s1.takeDamage(8);
            printAll(s1);
            std::cout << std::endl;
        }
        std::cout << BLUE << "\n--------------------Attack with 0 hit points test----------------------\n" << DGREEN << std::endl;
        s1.attack("Jon Snow");
        std::cout << BLUE << "\n--------------------Repair with 0 hit points test----------------------\n" << DGREEN << std::endl;
        s1.beRepaired(50);
        std::cout << std::endl;
        std::cout << WHITE << "ScavTrap " << s1.getName()
              << " has reached 0 HP and can no longer perform any actions.\n";
        std::cout << RED;
    }
    {
        std::cout << RESET;
        std::cout << BYELLOW << "\n-----------------------------NEW OBJECT-------------------------------\n" << DGREEN << std::endl;
        ScavTrap s2("Jon Snow");
        printAll(s2);
        std::cout << BLUE << "\n-----------------------------Energy Test-------------------------------\n" << DGREEN << std::endl;
        for (int i = 0; i < 51; ++i)
        {
            s2.attack("White Walkers");
            printAll(s2);
            std::cout << std::endl;
        }
        std::cout << BLUE << "\n--------------------Repair with 0 energy points test----------------------\n" << DGREEN << std::endl;
        s2.beRepaired(50);
        std::cout << std::endl;
        std::cout << WHITE << "ScavTrap " << s2.getName()
              << " has reached 0 energy and can no longer perform any actions.\n";
        std::cout << RED;
    }
    {
        std::cout << RESET;
        std::cout << BYELLOW << "\n-----------------------------NEW OBJECT-------------------------------\n" << DGREEN << std::endl;
        ScavTrap s3("Arya Stark");
        printAll(s3);
        std::cout << BLUE << "\n-----------------------------Random Test-------------------------------\n" << DGREEN << std::endl;
        for (int i = 0; i < 5; ++i)
        {
            s3.beRepaired(8);
            printAll(s3);
            std::cout << std::endl;
        }
        for (int i = 0; i < 8; ++i)
        {
            s3.attack("Cersei Lannister");
            printAll(s3);
            std::cout << std::endl;
        }
        for (int i = 0; i < 9; ++i)
        {
            s3.takeDamage(9);
            printAll(s3);
            std::cout << std::endl;
        }
        std::cout << RED;
    }
    return 0;
}
