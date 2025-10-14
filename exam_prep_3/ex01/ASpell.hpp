#pragma once
#include <iostream>

class ATarget;

class ASpell {
protected:
    std::string _name;
    std::string _effects;

public:
    ASpell() = delete;
    ASpell(const std::string& name, const std::string& effects);
    ASpell(const ASpell& other) = delete;
    ASpell& operator=(const ASpell& other) = delete;
    virtual ~ASpell();

    std::string getName() const;
    std::string getEffects() const;
    void launch(const ATarget& target) const;

    virtual ASpell* clone() const = 0;
};