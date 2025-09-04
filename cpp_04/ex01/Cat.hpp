#ifndef CAT_HPP
#define CAT_HPP

// Cat.hpp
#include "Animal.hpp"
#include "Brain.hpp"
class Cat : public Animal {
private:
    Brain* brain;
public:
    Cat();
    Cat(const Cat& other);
    Cat& operator=(const Cat& other);
    virtual ~Cat();
    virtual void makeSound() const;
    void setIdea(int idx, const std::string& idea);
    std::string getIdea(int idx) const;
};


#endif
