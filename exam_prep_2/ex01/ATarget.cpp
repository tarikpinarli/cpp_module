#include "ATarget.hpp"
#include "ASpell.hpp"

ATarget::ATarget(const std::string &type) : _type(type) {}

ATarget::~ATarget() {}

const std::string& ATarget::getType() const {
    return _type;
}

void ATarget::getHitBySpell(const ASpell& target) const {

    std::cout   << getType() << " has been " << target.getEffects() << "!\n"
                << getType() << " is the ATarget's type, and " << target.getEffects()
                << " is the return of the ASpell's getEffects function." << std::endl;
}
