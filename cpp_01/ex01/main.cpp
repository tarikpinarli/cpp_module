#include "Zombie.hpp"

int main() {
    int count = 9;
    Zombie* horde = zombieHorde(count, "Walker");

    for (int i = 0; i < count; i++) {
        horde[i].announce();
    }

    delete[] horde;
    return 0;
}