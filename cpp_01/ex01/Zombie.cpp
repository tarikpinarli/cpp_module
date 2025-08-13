#include "Zombie.hpp"

void    Zombie::setName(std::string name) {
    this->name = name;
}

void    Zombie::announce() {
    std::cout << GREEN << name << ": BraiiiiiiinnnzzzZ..." << RESET << std::endl;
}

Zombie::~Zombie() {
    std::cout << RED << name << " destroyed." << RESET << std::endl;
}
