// ex01/main.cpp
#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

// ----- Pretty headers -----
static void section(const std::string& title) {
    std::cout << BLUE << "\n========== " << title << " ==========\n" << WHITE << "\n";
}
static void subSection(const std::string& title) {
    std::cout << YELLOW << "------ " << title << " ------" << WHITE << "\n";
}

int main() {
    // 1) Default constructor smoke test
    section("Default constructor test");
    {
        subSection("Animal");
        Animal  a;
        subSection("Cat");
        Cat     c;
        subSection("Dog");
        Dog     d;
        std::cout << RED << std::endl; // close scope to see dtors order
    }

    // 2) Copy constructor test (includes deep copy via Brain)
    section("Copy constructor test");
    {
        subSection("Animal");
        Animal a;
        Animal b(a);

        subSection("Dog (deep copy)");
        Dog d1;
        d1.setIdea(0, "chase the ball");
        Dog d2(d1); // copy-ctor -> deep copy Brain
        std::cout << "d1.idea[0] = " << d1.getIdea(0) << "\n";
        std::cout << "d2.idea[0] = " << d2.getIdea(0) << "\n";
        std::cout << GREEN << "mutate copy -> d2.idea[0] = 'nap on the couch'\n" << WHITE;
        d2.setIdea(0, "nap on the couch");
        std::cout << "d1.idea[0] = " << d1.getIdea(0) << "  (unchanged)\n";
        std::cout << "d2.idea[0] = " << d2.getIdea(0) << "  (changed)\n";

        subSection("Cat (deep copy)");
        Cat c1;
        c1.setIdea(1, "watch birds");
        Cat c2(c1);
        std::cout << "c1.idea[1] = " << c1.getIdea(1) << "\n";
        std::cout << "c2.idea[1] = " << c2.getIdea(1) << "\n";
        std::cout << GREEN << "mutate copy -> c2.idea[1] = 'ignore humans'\n" << WHITE;
        c2.setIdea(1, "ignore humans");
        std::cout << "c1.idea[1] = " << c1.getIdea(1) << "  (unchanged)\n";
        std::cout << "c2.idea[1] = " << c2.getIdea(1) << "  (changed)\n";

        std::cout << RED << std::endl;
    }

    section("Copy assignment test");
    {
        subSection("Dog_1");
        Dog Dog_1;
        Dog_1.setIdea(2, "guard the house");
        subSection("Dog_2");
        Dog Dog_2;
        Dog_2.setIdea(2, "dig holes");
        subSection("Dog_2 = Dog_1");
        Dog_2 = Dog_1; // operator= must deep-copy Brain
        std::cout << "Dog_1.idea[2] = " << Dog_1.getIdea(2) << "\n";
        std::cout << "Dog_2.idea[2] = " << Dog_2.getIdea(2) << "\n";
        std::cout << GREEN << "mutate assignee -> Dog_2.idea[2] = 'sleep'\n" << WHITE;
        Dog_2.setIdea(2, "sleep");
        std::cout << "Dog_1.idea[2] = " << Dog_1.getIdea(2) << "  (unchanged)\n";
        std::cout << "Dog_2.idea[2] = " << Dog_2.getIdea(2) << "  (changed)\n";

        subSection("Cat_1 / Cat_2 assignment");
        Cat Cat_1;
        Cat_1.setIdea(3, "stare at wall");
        Cat Cat_2;
        Cat_2.setIdea(3, "scratch sofa");
        Cat_2 = Cat_1;
        std::cout << "Cat_1.idea[3] = " << Cat_1.getIdea(3) << "\n";
        std::cout << "Cat_2.idea[3] = " << Cat_2.getIdea(3) << "\n";
        std::cout << GREEN << "mutate assignee -> Cat_2.idea[3] = 'hunt laser'\n" << WHITE;
        Cat_2.setIdea(3, "hunt laser");
        std::cout << "Cat_1.idea[3] = " << Cat_1.getIdea(3) << "  (unchanged)\n";
        std::cout << "Cat_2.idea[3] = " << Cat_2.getIdea(3) << "  (changed)\n";

        std::cout << RED << std::endl;
    }

    section("Subject test");
    {
        subSection("Animal");
        const Animal* meta = new Animal();
        subSection("Dog");
        const Animal* j = new Dog();
        subSection("Cat");
        const Animal* i = new Cat();

        subSection("getType");
        std::cout << meta->getType() << " " << std::endl;
        std::cout << j->getType() << " " << std::endl;
        std::cout << i->getType() << " " << std::endl;

        subSection("makeSound");
        meta->makeSound();
        j->makeSound();
        i->makeSound();

        std::cout << RED << std::endl;
        delete i;
        delete j;
        delete meta;
    }

    section("Array of Animal* (half Dog, half Cat)");
    {
        const int N = 6;
        Animal* Animal[N];

        subSection("Construct");
        for (int k = 0; k < N; ++k)
        {
            if (k < N / 2)
                Animal[k] = new Dog();
            else
                Animal[k] = new Cat();
        }

        subSection("Sounds");
        for (int k = 0; k < N; ++k) {
            std::cout << k << ": " << Animal[k]->getType() << " -> ";
            Animal[k]->makeSound();
        }
        subSection("Ideas");
        for (int k = 0; k < N; ++k) {
            std::cout << k << ": " << Animal[k]->getType() << " -> ";

            if (Dog* d = dynamic_cast<Dog*>(Animal[k])) {
                d->setIdea(0, "Dog idea from main");
                std::cout << "idea[0] = " << d->getIdea(0) << "\n";
            } else if (Cat* c = dynamic_cast<Cat*>(Animal[k])) {
                c->setIdea(0, "Cat idea from main");
                std::cout << "idea[0] = " << c->getIdea(0) << "\n";
            } else {
                std::cout << "(no brain)\n";
            }
        }



        subSection("Delete via base pointers");
        for (int k = 0; k < N; ++k) delete Animal[k];

        std::cout << RED << std::endl;
    }

    // 6) Wrong hierarchy demo (no virtual)
    section("Wrong hierarchy (no virtual)");
    {
        subSection("WrongAnimal");
        const WrongAnimal* a = new WrongAnimal();
        subSection("WrongCat");
        const WrongAnimal* b = new WrongCat();

        subSection("getType");
        std::cout << a->getType() << " " << std::endl;
        std::cout << b->getType() << " " << std::endl;

        subSection("makeSound (will call WrongAnimal's)");
        b->makeSound();
        a->makeSound();

        std::cout << RED << std::endl;
        delete a;
        delete b;
    }

    std::cout << RESET;
    return 0;
}
