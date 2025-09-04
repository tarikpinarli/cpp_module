#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main() {
    std::cout << "=== Leak check snippet from subject ===\n";
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    delete j; // should not leak
    delete i;

    std::cout << "\n=== Array of Animal* (half Dog, half Cat) ===\n";
    const int N = 6; // even number
    Animal* zoo[N];

    for (int k = 0; k < N; ++k) {
        if (k < N/2)
            zoo[k] = new Dog();
        else
            zoo[k] = new Cat();
    }

    std::cout << "\nSounds from the zoo:\n";
    for (int k = 0; k < N; ++k) {
        std::cout << k << ": " << zoo[k]->getType() << " -> ";
        zoo[k]->makeSound();
    }

    std::cout << "\nDeleting via base pointers:\n";
    for (int k = 0; k < N; ++k) delete zoo[k];

    std::cout << "\n=== Deep copy test (Dog) ===\n";
    Dog d1;
    d1.setIdea(0, "chase the ball");

    Dog d2 = d1; // copy-construct (deep)
    d2.setIdea(0, "nap on the couch");

    std::cout << "d1.idea[0] = " << d1.getIdea(0) << "\n"; // expect: chase the ball
    std::cout << "d2.idea[0] = " << d2.getIdea(0) << "\n"; // expect: nap on the couch

    std::cout << "\n=== Deep copy test (Cat) ===\n";
    Cat c1;
    c1.setIdea(1, "watch birds");

    Cat c2;
    c2 = c1; // copy-assign (deep)
    c2.setIdea(1, "ignore humans");

    std::cout << "c1.idea[1] = " << c1.getIdea(1) << "\n"; // expect: watch birds
    std::cout << "c2.idea[1] = " << c2.getIdea(1) << "\n"; // expect: ignore humans

    std::cout << "\nAll tests done.\n";
    return 0;
}