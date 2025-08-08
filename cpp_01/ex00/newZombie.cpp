#include "Zombie.hpp"

Zombie*    newZombie(string name) {
    Zombie *Zombie_heap;

    Zombie_heap = new Zombie(name);
    return Zombie_heap;
}