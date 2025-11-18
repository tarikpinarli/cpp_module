#pragma once
#include <iostream>
#include <exception>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <array>
#include <list>
#include <deque>
#include <set>

#define BLUE  "\033[1;94m"
#define YELLOW  "\033[1;33m"
#define WHITE   "\033[1;97m"
#define GREEN "\033[1;32m"


template <typename T>
typename T::iterator easyfind(T& data, int number){
    auto it = std::find(data.begin(), data.end(), number);
    if (it == data.end())
        throw std::runtime_error("Value not found");
    return it;
}
