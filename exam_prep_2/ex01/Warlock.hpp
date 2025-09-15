#pragma once
#include <iostream>

class Warlock {
private:
    std::string _name;
    std::string _title;
public:

    Warlock() = delete;
    Warlock(const std::string& name, const std::string& title);
    Warlock(const Warlock& other) = delete;
    Warlock& operator=(const Warlock& other) = delete;
    ~Warlock();

    //getters
    const std::string& getName() const;
    const std::string& getTitle() const;

    //setters
    void setTitle(std::string title);

    void introduce() const;
};
