// Harl.cpp
#include <iostream>
#include "Harl.hpp"

Harl::Harl() {}
Harl::~Harl() {}

// --- Private seviye fonksiyonları ---
void Harl::debug(void) {
    std::cout
        << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!"
        << std::endl;
}

void Harl::info(void) {
    std::cout
        << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! "
           "If you did, I wouldn’t be asking for more!"
        << std::endl;
}

void Harl::warning(void) {
    std::cout
        << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started "
           "working here since last month."
        << std::endl;
}

void Harl::error(void) {
    std::cout
        << "This is unacceptable! I want to speak to the manager now."
        << std::endl;
}

// --- Public arayüz ---
void Harl::complain(const std::string& level) {
    std::string levels[4] = { "DEBUG", "INFO", "WARNING", "ERROR" };

    // 2) Üye-fonksiyon işaretçileri (aynı sırada olmak zorunda)
    void (Harl::*actions[4])() ={
        &Harl::debug,
        &Harl::info,
        &Harl::warning,
        &Harl::error
    };


    // 3) Eşleşmeyi bul ve çağır
    for (int i = 0; i < 4; ++i) {
        if (level == levels[i]) {
            (this->*actions[i])();
            return;
        }
    }

    // 4) Eşleşme yoksa (tasarım tercihi: kısa bir uyarı bas)
    std::cout << "Unknown level: " << level << std::endl;
}
