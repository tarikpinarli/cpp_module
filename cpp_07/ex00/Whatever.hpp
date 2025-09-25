#pragma once

#include <iostream>

#define BLUE  "\033[1;94m"
#define YELLOW  "\033[1;33m"
#define WHITE   "\033[1;97m"


template <typename T>
void swap(T& a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

template <typename T>
T min(const T &a, T &b)
{
    if (a < b)
        return a;
    else
        return b;
}

template <typename T>
T max(const T &a, const T &b)
{
    if (a > b)
        return a;
    else
        return b;
}
