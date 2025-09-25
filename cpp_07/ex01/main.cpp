#include "Iter.hpp"

static void section(const std::string& title) {
    std::cout << BLUE << "\n========== " << title << " ==========\n" << WHITE << "\n";
}

static void subSection(const std::string& title) {
    std::cout << YELLOW << "------ " << title << " ------" << WHITE << "\n";
}

int main() {

    section("Test with integers");
    {
        int array[] = {1, 2, 3};
        size_t arrayLength = sizeof(array) / sizeof(array[0]);
        subSection("Before iter");
        for (size_t i = 0; i < arrayLength; i++)
            std::cout << array[i] << std::endl;
        ::iter(array, arrayLength, minusOne);
        subSection("After iter");
        for (size_t i = 0; i < arrayLength; i++)
            std::cout << array[i] << std::endl;
    }
    section("Test with chars");
    {
        char array[] = {'a', 'b', 'c'};
        size_t arrayLength = sizeof(array) / sizeof(array[0]);
        subSection("Before iter");
        for (size_t i = 0; i < arrayLength; i++)
            std::cout << array[i] << std::endl;
        ::iter(array, arrayLength, minusOne);
        subSection("After iter");
        for (size_t i = 0; i < arrayLength; i++)
            std::cout << array[i] << std::endl;
    }
    section("Test with floats");
    {
        float array[] = {1.1f, 2.1f, 3.1f};
        size_t arrayLength = sizeof(array) / sizeof(array[0]);
        subSection("Before iter");
        for (size_t i = 0; i < arrayLength; i++)
            std::cout << array[i] << std::endl;
        ::iter(array, arrayLength, minusOne);
        subSection("After iter");
        for (size_t i = 0; i < arrayLength; i++)
            std::cout << array[i] << std::endl;
    }
    section("Test with doubles");
    {
        double array[] = {1.1, 2.1, 3.1};
        size_t arrayLength = sizeof(array) / sizeof(array[0]);
        subSection("Before iter");
        for (size_t i = 0; i < arrayLength; i++)
            std::cout << array[i] << std::endl;
        ::iter(array, arrayLength, minusOne);
        subSection("After iter");
        for (size_t i = 0; i < arrayLength; i++)
            std::cout << array[i] << std::endl;
    }
}
