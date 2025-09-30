#pragma once
#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <stdexcept>   // std::out_of_range
# include <typeinfo>

#define BLUE  "\033[1;94m"
#define YELLOW  "\033[1;33m"
#define WHITE   "\033[1;97m"

template <typename T>
class Array
{
private:
    T*      _data;
    size_t  _size;

    void    allocate_and_value_init(size_t n);
    void    copy_from(const Array& other);
    void    destroy();
public:
    Array();
    Array(unsigned int n);
    Array(const Array& other);

    ~Array();

    Array& operator=(const Array& other);

    T& operator[](size_t index);
    const T& operator[](size_t index) const;

    size_t size() const;
};

# include "Array.tpp"
#endif
