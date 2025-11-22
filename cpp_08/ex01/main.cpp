#include "Span.hpp"

static void subSection(const std::string& title) {
    std::cout << BLUE << "------ " << title << " ------" << WHITE << "\n";
}

int main()
{
    std::cout << WHITE;
    try{
        subSection("Subject Test");
        int size = 5;
        Span sp = Span(size);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        sp.print();
        std::cout << "Shortest span is: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span is: " << sp.longestSpan() << std::endl;
        std::cout << sp;
        std::cout << GREEN << "success!" << WHITE << std::endl;
    }
    catch (std::exception &e) {
        std::cout << YELLOW << "Exception cought: " << WHITE << e.what() << std::endl;
    }

    try{
        subSection("Success test");
        int size = 3;
        Span demo_00 = Span(size);
        demo_00.addNumber(6);
        demo_00.addNumber(3);
        demo_00.addNumber(17);
        demo_00.print();
        std::cout << "Shortest span is: "<< demo_00.shortestSpan() << std::endl;
        std::cout << "Longest span is: " << demo_00.longestSpan() << std::endl;
        std::cout << demo_00;
        std::cout << GREEN << "success!" << WHITE << std::endl;
    }
    catch (std::exception &e) {
        std::cout << YELLOW << "Exception cought: " << WHITE << e.what() << std::endl;
    }

    try{
        subSection("Not enough numbers tp provide shortest span exception test");
        int size = 3;
        Span demo_01 = Span(size);
        demo_01.addNumber(6);
        demo_01.print();
        std::cout << "Shortest span is: " << demo_01.shortestSpan() << std::endl;
        std::cout << "Longest span is: " << demo_01.longestSpan() << std::endl;
        std::cout << demo_01 << std::endl;
    }
    catch (std::exception &e) {
        std::cout << YELLOW << "Exception cought: " << WHITE << e.what() << std::endl;
    }

        try{
        subSection("Not enough numbers to provide longest span exception test");
        int size = 3;
        Span demo_01 = Span(size);
        demo_01.addNumber(6);
        demo_01.print();
        std::cout << "Longest span is: " << demo_01.longestSpan() << std::endl;
        std::cout << "Shortest span is: " << demo_01.shortestSpan() << std::endl;
        std::cout << demo_01 << std::endl;
    }
    catch (std::exception &e) {
        std::cout << YELLOW << "Exception cought: " << WHITE << e.what() << std::endl;
    }

    try{
        subSection("No space exception test");
        int size = 2;
        Span demo_02 = Span(size);
        demo_02.addNumber(6);
        demo_02.addNumber(8);
        demo_02.addNumber(0);
        std::cout << demo_02.shortestSpan() << std::endl;
        std::cout << demo_02.longestSpan() << std::endl;
        std::cout << demo_02 << std::endl;
    }
    catch (std::exception &e) {
        std::cout << YELLOW << "Exception cought: " << WHITE << e.what() << std::endl;
    }
    return 0;
}
