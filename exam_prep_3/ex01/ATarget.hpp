#pragma once
#include <iostream>

class ASpell;

class ATarget {
protected:
    std::string _type;
public:
    ATarget() = delete;
    ATarget(const std::string& type);
    ATarget(const ATarget& other) = delete;
    ATarget& operator=(const ATarget& other) = delete;
    virtual ~ATarget();

    const std::string& getType() const;
    void getHitBySpell(const ASpell& spell) const;
    virtual ATarget* clone() const = 0;
};