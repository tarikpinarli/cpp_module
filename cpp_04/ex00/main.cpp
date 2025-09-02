#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
    std::cout << "=== Provided test ===\n";
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); // will output the cat sound!
    j->makeSound(); // dog sound
    meta->makeSound();

    std::cout << "\n=== Wrong hierarchy (no virtual) ===\n";
    const WrongAnimal* w = new WrongAnimal();
    const WrongAnimal* wc = new WrongCat();

    std::cout << wc->getType() << " " << std::endl;
    wc->makeSound(); // WrongAnimal sound (because makeSound isn't virtual)
    w->makeSound();

    delete wc; // base dtor is non-virtual (intentional for the exercise)
    delete w;

    std::cout << "\n=== Extra polymorphism test ===\n";
    Animal* zoo[3];
    zoo[0] = new Dog();
    zoo[1] = new Cat();
    zoo[2] = new Animal();

    for (int k = 0; k < 3; ++k) {
        std::cout << zoo[k]->getType() << ": ";
        zoo[k]->makeSound();
    }

    std::cout << "\n=== Copy semantics sanity check ===\n";
    Dog d1;
    Dog d2 = d1;     // copy ctor
    Dog d3;
    d3 = d2;         // copy assign
    d1.makeSound(); d2.makeSound(); d3.makeSound();

    return 0;
}
