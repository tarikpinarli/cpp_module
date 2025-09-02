#ifndef ANIMAL_HPP
#define ANIMAL_HPP
#include <iostream>

#define CYAN    "\033[1;36m"
#define BLINKRED   "\033[1;5;31m"
#define RED   "\033[1;31m"
#define GREEN "\033[1;92m"
#define DGREEN "\033[1;32m"
#define BLUE  "\033[1;94m"
#define YELLOW  "\033[1;33m"
#define BYELLOW   "\033[1;93m"
#define MAGENTA "\033[1;35m"
#define WHITE   "\033[1;97m"
#define RESET "\033[0m"

class Animal {
protected:
    std::string _type;
public:
    Animal();
    Animal(const Animal& other);
    virtual ~Animal();

    Animal& operator=(const Animal& other);

    const std::string& getType() const;
    virtual void makeSound() const;
};

#endif
