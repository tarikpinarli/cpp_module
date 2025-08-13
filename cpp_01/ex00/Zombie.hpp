#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

#define GREEN "\033[0;32m"
#define RED "\033[0;31m"
#define RESET "\033[0m"

class Zombie {
private:
    std::string name;
public:
    Zombie(std::string name);
    ~Zombie();
    void announce();
};
void        randomChump(std::string name);
Zombie*     newZombie(std::string name);
#endif
