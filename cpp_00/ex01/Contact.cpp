#include <iostream>
#include <iomanip>
#include "Contact.hpp"
#include <cstdlib>


void Contact::setContact() {
    std::cout << "Enter First Name: ";
    while (1)
    {
        std::getline(std::cin, firstName);
        if (std::cin.eof()) {
            std::cout << "\nExiting...\n";
            exit(1);
        }
        if (firstName.empty())
        {
            std::cout << "firstName can't be empty.\nEnter first Name: ";
            continue;
        }
        else
            break;
    }
    std::cout << "Enter Last Name: ";
    while (1)
    {
        std::getline(std::cin, lastName);
        if (std::cin.eof()) {
            std::cout << "\nExiting...\n";
            exit(1);
        }
        if (lastName.empty())
        {
            std::cout << "lastName can't be empty.\nEnter Last Name: ";
            continue;
        }
        else
            break;
    }
    std::cout << "Enter Nickname: ";
    while (1)
    {
        std::getline(std::cin, nickName);
        if (std::cin.eof()) {
            std::cout << "\nExiting...\n";
            exit(1);
        }
        if (nickName.empty())
        {
            std::cout << "nickname can't be empty.\nEnter Nickname: ";
            continue;
        }
        else
            break;
    }
    std::cout << "Enter Phone Number: ";
    while (1)
    {
        std::getline(std::cin, phoneNumber);
        if (std::cin.eof()) {
            std::cout << "\nExiting...\n";
            exit(1);
        }
        if (phoneNumber.empty())
        {
            std::cout << "phoneNumber can't be empty.\nEnter Phone Number: ";
            continue;
        }
        else
            break;
    }
    std::cout << "Enter Darkest Secret: ";
    while (1)
    {
        std::getline(std::cin, darkestSecret);
        if (std::cin.eof()) {
            std::cout << "\nExiting...\n";
            exit(1);
        }
        if (darkestSecret.empty())
        {
            std::cout << "darkestSecret can't be empty.\nEnter Darkest Secret: ";
            continue;
        }
        else
            break;
    }
}

static std::string format(const std::string &s) {
    return s.length() > 10 ? s.substr(0, 9) + "." : s;
}

void Contact::displaySummary(int index) const {
    std::cout << "|" << std::setw(10) << index
              << "|" << std::setw(10) << format(firstName)
              << "|" << std::setw(10) << format(lastName)
              << "|" << std::setw(10) << format(nickName)
              << "|" << std::endl;
}

void Contact::displayDetails() const {
    std::cout << "First Name: " << firstName << std::endl;
    std::cout << "Last Name: " << lastName << std::endl;
    std::cout << "Nickname: " << nickName << std::endl;
    std::cout << "Phone Number: " << phoneNumber << std::endl;
    std::cout << "Darkest Secret: " << darkestSecret << std::endl;
}
