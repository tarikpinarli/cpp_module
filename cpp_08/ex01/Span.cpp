#include "Span.hpp"

Span::Span(void) : _N(0)
{
	this->_data.reserve(0);
}

Span::Span(unsigned int N) : _N(N)
{
	this->_data.reserve(_N);
}

Span::~Span() {}

Span::Span(const Span& other)
{
	*this = other;
}

int		Span::size(void) const
{
	return (this->_data.size());
}

Span& Span::operator=(const Span& other)
{
    if (this != &other) {
        this->_N = other._N;
	    this->_data = other._data;
    }
	return (*this);
}

void Span::addNumber(int n)
{
	if (this->_data.size() == _N)
		throw std::overflow_error("Span has no more free spaces");
	this->_data.push_back(n);
}

int Span::shortestSpan(void) const
{
    if (_data.size() < 2)
        throw std::logic_error("Not enough numbers stored to provide shortest span");

    std::vector<int> tmp = _data;
    std::sort(tmp.begin(), tmp.end());

    int minSpan = INT_MAX;

    for (size_t i = 1; i < tmp.size(); i++)
    {
        int diff = tmp[i] - tmp[i - 1];
        if (diff < minSpan)
            minSpan = diff;
    }
    return minSpan;
}


int Span::longestSpan(void) const {
    if (_data.size() < 2)
        throw std::logic_error("Not enough numbers stored to provide longest span");
    std::vector<int> tmp = _data;
    std::sort(tmp.begin(), tmp.end());
    return tmp.back() - tmp.front();
}

void Span::print() const
{
    std::cout << "Numbers in Span: [ ";
    for (size_t i = 0; i < _data.size(); i++)
    {
        std::cout << _data[i];
        if (i + 1 != _data.size())
            std::cout << ", ";
    }
    std::cout << " ]" << std::endl;
}


std::ostream&	operator<<(std::ostream& out, const Span& instance)
{
    out << "Summary:" << std::endl;
	out << "-Size: " << instance.size() << std::endl;
	out << "-Shortest span: " << instance.shortestSpan() << std::endl;
	out << "-Longest span: " << instance.longestSpan() << std::endl;
	return (out);
}
