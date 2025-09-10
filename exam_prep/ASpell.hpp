#ifndef ASPELL_HPP
#define ASPELL_HPP

#include "Warlock.hpp"

class ASpell {
protected:
    std::string name;
    std::string effects;
public:
    ASpell(const std::string _name, cont std::string _effects);
    virtual ~ASpell();

    std::string getName();
    std::string getEffects();

    virtual ASpell* clone() const = 0;

};

#endif