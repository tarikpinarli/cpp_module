#include "Zombie.hpp"

int main()
{
    randomChump("Zombie_stack");

    Zombie *Zombie_heap = newZombie("Zombie_Heap");
    Zombie_heap->announce();

    delete Zombie_heap;
    return 0;
}