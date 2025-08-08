#include "Zombie.hpp"

void    Zombie::setName(string name) {
    this->name = name;
}

void    Zombie::announce() {
    cout << GREEN << name << ": BraiiiiiiinnnzzzZ..." << RESET << endl;
}

Zombie::~Zombie() {
    cout << RED << name << " destroyed." << RESET << endl;
}