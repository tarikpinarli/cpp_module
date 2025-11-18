#pragma once
#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <iterator>
#include <vector>
#include <climits>



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
};

std::ostream&	operator<<(std::ostream& out, const Span& instance);
