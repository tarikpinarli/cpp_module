#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

using std::string;
using std::cout;
using std::endl;

#define GREEN "\033[0;32m"
#define RED "\033[0;31m"
#define RESET "\033[0m"

class Zombie {
private:
    string name;
public:
    Zombie(string name);
    ~Zombie();
    void announce();
};
void    randomChump(string name);
Zombie*    newZombie(string name);
#endif