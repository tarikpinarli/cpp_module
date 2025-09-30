#include <iostream>
#include <string>
#include "Array.hpp"

static void section(const std::string& title) {
    std::cout << BLUE << "\n========== " << title << " ==========\n" << WHITE << "\n";
}

static void subSection(const std::string& title) {
    std::cout << YELLOW << "------ " << title << " ------" << WHITE << "\n";
}

int main()
{
    section("Test with integers");
    try {
        Array<int> intArray(5);
        std::cout << "size of intArray = " << intArray.size() << std::endl;
        subSection("View content of intArray before change");
        for (size_t i = 0; i < intArray.size(); ++i)
            std::cout << "intArray[" << i << "] = " << intArray[i] << std::endl;
        for (size_t j = 0; j < intArray.size() ; ++j)
            intArray[j] = j * 2;
        subSection("View content of intArray after change");
        for (size_t i = 0; i < intArray.size(); ++i)
            std::cout << "intArray[" << i << "] = " << intArray[i] << std::endl;
    }
    catch (const std::exception& e){
        std::cout << "Exception Caught: " << e.what() << std::endl;
    }
    section("Test with std::string");
    try {
        Array<std::string> stringArray(5);
        std::cout << "size of stringArray = " << stringArray.size() << std::endl;
        subSection("View content of stringArray before change");
        for (size_t i = 0; i < stringArray.size(); ++i)
            std::cout << "stringArray[" << i << "] = " << stringArray[i] << std::endl;
        std::string *list = new std::string[5]{"First", "Second", "Third", "Fourth", "Fifth"};
        for (size_t j = 0; j < stringArray.size() ; ++j)
            stringArray[j] = list[j];
        subSection("View content of stringArray after change");
        for (size_t i = 0; i < stringArray.size(); ++i)
            std::cout << "stringArray[" << i << "] = " << stringArray[i] << std::endl;
        delete[] list;
    }
    catch (const std::exception& e){
        std::cout << "Exception Caught: " << e.what() << std::endl;
    }
    section("Test with floats");
    try {
        Array<float> floatArray(5);
        std::cout << "size of floatArray = " << floatArray.size() << std::endl;
        subSection("View content of floatArray before change");
        for (size_t i = 0; i < floatArray.size(); ++i)
            std::cout << "floatArray[" << i  << "] = " << floatArray[i] << "f" << std::endl;
        for (size_t j = 0; j < floatArray.size() ; ++j)
            floatArray[j] = j / 3.3 ;
        subSection("View content of floatArray after change");
        for (size_t i = 0; i < floatArray.size(); ++i)
            std::cout << "floatArray[" << i << "] = " << floatArray[i] << "f" << std::endl;
    }
    catch (const std::exception& e){
        std::cout << "Exception Caught: " << e.what() << std::endl;
    }
    section("Test with doubles");
    try {
        Array<double> doubleArray(5);
        std::cout << "size of doubleArray = " << doubleArray.size() << std::endl;
        subSection("View content of doubleArray before change");
        for (size_t i = 0; i < doubleArray.size(); ++i)
            std::cout << "doubleArray[" << i  << "] = " << doubleArray[i] << std::endl;
        for (size_t j = 0; j < doubleArray.size() ; ++j)
            doubleArray[j] = j * 3.3 ;
        subSection("View content of doubleArray after change");
        for (size_t i = 0; i < doubleArray.size(); ++i)
            std::cout << "doubleArray[" << i << "] = " << doubleArray[i] << std::endl;
    }
    catch (const std::exception& e){
        std::cout << "Exception Caught: " << e.what() << std::endl;
    }
    section("out of range exeption test");
    try {
        Array<int> rangeArray(5);
        std::cout << "size of rangeArray = " << rangeArray.size() << std::endl;
        subSection("View content of rangeArray (for loop range = 5)");
        for (size_t i = 0; i < rangeArray.size(); ++i)
            std::cout << "rangeArray[" << i  << "] = " << rangeArray[i] << std::endl;
        subSection("View content of rangeArray (for loop range = 6)");
        for (size_t i = 0; i < rangeArray.size() + 1; ++i)
            std::cout << "rangeArray[" << i  << "] = " << rangeArray[i] << std::endl;
        std::cout << "Shoudnt print out" << std::endl;
    }
    catch (const std::exception& e){
        std::cout << "Exception Caught: " << e.what() << std::endl;
    }

    return 0;
}
