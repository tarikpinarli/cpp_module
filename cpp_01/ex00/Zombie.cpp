#include "Zombie.hpp"

Zombie::~Zombie() {
    cout << RED << name << " destroyed." << RESET << endl;
}

Zombie::Zombie(string name) {
    this->name = name;
}

void    Zombie::announce() {
    cout << GREEN << name << ": BraiiiiiiinnnzzzZ..." << RESET << endl;
}
