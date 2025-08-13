#include "Zombie.hpp"

Zombie::~Zombie() {
    std::cout << RED << name << " destroyed." << RESET << std::endl;
}

Zombie::Zombie(std::string name) {
    this->name = name;
}

void    Zombie::announce() {
    std::cout << GREEN << name << ": BraiiiiiiinnnzzzZ..." << RESET << std::endl;
}
