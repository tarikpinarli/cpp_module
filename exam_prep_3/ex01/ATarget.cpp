#include "ATarget.hpp"

ATarget::ATarget(const std::string& type) : _type(type) {}

const std::string& ATarget::getType() const{
    return _type;
}

void ATarget::getHitBySpell(const ASpell& spell) const {
    // <TYPE> has been <EFFECTS>!
    std::cout << _type << " has been " << spell.getEffects() << " !" << std::endl;
}

