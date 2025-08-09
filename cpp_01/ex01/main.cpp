#include "Zombie.hpp"

int main() {
    int count = 20;
    Zombie* horde = zombieHorde(count, "Heap Walker");

    for (int i = 0; i < count; i++) {
        horde[i].announce();
    }

    delete[] horde;
    return 0;
}
