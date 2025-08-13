#include "Zombie.hpp"

Zombie *zombieHorde(int count, std::string name) {
    if (count <= 0)
    {
        std::cerr    << RED << "Error: Cannot create a horde with "
                << count << " zombies. Number must be positive."
                << RESET << std::endl;
        return NULL;
    }
    Zombie *horde = new Zombie[count];
    for (int i = 0; i < count; i++) {
        horde[i].setName(name);
    }
    return horde;
}
