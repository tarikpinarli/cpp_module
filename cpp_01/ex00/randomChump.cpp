#include "Zombie.hpp"

void    randomChump(std::string name) {
    Zombie Zombie_stack(name);
    Zombie_stack.announce();
}
