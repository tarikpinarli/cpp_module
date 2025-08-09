#include "Zombie.hpp"

Zombie *zombieHorde(int count, string name) {
    if (count <= 0)
    {
        cerr    << RED << "Error: Cannot create a horde with "
                << count << " zombies. Number must be positive."
                << RESET << endl;
        return NULL;
    }
    Zombie *horde = new Zombie[count];
    for (int i = 0; i < count; i++) {
        horde[i].setName(name);
    }
    return horde;
}
