#pragma once

#include <iostream>

class ASpell;

class ATarget {
protected:
    std::string _type;
public:
    ATarget(const std::string &type);
    virtual~ATarget();

    const std::string& getType() const;
    void getHitBySpell(const ASpell& target) const;
};
