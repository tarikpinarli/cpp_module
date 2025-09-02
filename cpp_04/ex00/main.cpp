#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

static void section(const std::string& title) {
    std::cout << BLUE << "\n========== " << title << " ==========\n" << WHITE << "\n";
}
static void subSection(const std::string& title) {
    std::cout << YELLOW << "------ " << title << " ------" << WHITE << "\n";
}

int main() {
    section("Default constractor test");
    {
        subSection("Animal");
        Animal  a;
        subSection("Cat");
        Cat     b;
        subSection("Dog");
        Dog     c;
        std::cout << RED << std::endl;
    }
    section("Copy constractor test");
    {
        subSection("Animal");
        Animal  a;
        Animal  b(a);
        subSection("Dog");
        Dog     c;
        Dog     d(c);
        subSection("Cat");
        Cat     e;
        Cat     f(e);
        std::cout << RED << std::endl;
    }
    section("Copy operator test");
    {
        subSection("Dog_1");
        Dog Dog_1;
        subSection("Dog_2");
        Dog Dog_2;
        subSection("Dog_2 = Dog_1");
        Dog_2 = Dog_1;
        subSection("Dog_3");
        Dog Dog_3;
        subSection("Dog_3 = Dog_2");
        Dog_3 = Dog_2;
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
    section("Wrong hierarchy (no virtual)");
    {
        subSection("WrongAnimal");
        const WrongAnimal* a = new WrongAnimal();
        subSection("WrongCat");
        const WrongAnimal* b = new WrongCat();
        subSection("getType");
        std::cout << a->getType() << " " << std::endl;
        std::cout << b->getType() << " " << std::endl;
        subSection("makeSound");
        b->makeSound();
        a->makeSound();
        std::cout << RED << std::endl;
        delete a;
        delete b;
    }

    std::cout << RESET;
    return 0;
}
