#pragma once
#include <iostream>
#include "ASpell.hpp"
#include "ATarget.hpp"
#include "Fwoosh.hpp"
#include "Dummy.hpp"
#include <map>

class Warlock {
private:
    std::string _name;
    std::string _title;
    std::map<std::string, ASpell*> _spellBook;
public:
    Warlock() = delete;
    Warlock(const std::string& name, const std::string& title);
    Warlock(const Warlock& other) = delete;
    Warlock& operator=(const Warlock& other) = delete;
    ~Warlock();


    const std::string& getName() const;
    const std::string& getTitle() const;
    void setTitle(const std::string& title);
    void introduce() const;

    void learnSpell(ASpell* spell);
    void forgetSpell(std::string spell);
    void launchSpell(std::string spell, const ATarget& target);


};