#include "Span.hpp"

int main()
{
    try{
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
        std::cout << sp << std::endl;
    }
    catch (std::exception &e) {
        std::cout << "Exception cought: " << e.what() << std::endl;
    }

    try{
        Span demo = Span(3);
        demo.addNumber(6);
        demo.addNumber(3);
        demo.addNumber(17);
        std::cout << demo.shortestSpan() << std::endl;
        std::cout << demo.longestSpan() << std::endl;
        std::cout << demo << std::endl;
    }
    catch (std::exception &e) {
        std::cout << "Exception cought: " << e.what() << std::endl;
    }
    return 0;
}
