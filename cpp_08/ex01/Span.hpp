#pragma once
#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <iterator>
#include <vector>
#include <climits>

#define BLUE  "\033[1;94m"
#define YELLOW  "\033[1;33m"
#define WHITE   "\033[1;97m"
#define GREEN "\033[1;32m"


class Span {
private:
    std::vector<int>    _data;
    unsigned int        _N;
public:
    Span();
    Span(unsigned int N);
    Span(const Span& other);
    ~Span();

    Span&	operator=(const Span& other);

    void addNumber(int add);
    int shortestSpan(void) const;
    int longestSpan(void) const;
    int	size(void) const;
    void print() const;

};

std::ostream&	operator<<(std::ostream& out, const Span& instance);
