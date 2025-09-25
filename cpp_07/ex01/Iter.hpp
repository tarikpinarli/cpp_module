#pragma once
#include <cstddef>
#include <iostream>

#define BLUE  "\033[1;94m"
#define YELLOW  "\033[1;33m"
#define WHITE   "\033[1;97m"

template <typename T>
void minusOne(T& num)
{
    num -= 1;
}

template <typename T>
void iter(T* array, size_t length, void (*function)(T&)) {
    for (size_t i = 0; i < length; ++i) {
        function(array[i]);
    }
}

