#include "easyfind.hpp"

int main() {
    std::vector<int> vec = {1, 2, 4, 8, 16, 32, 64};
    std::cout << WHITE << "vector = ";
    for (auto n : vec) {
        std::cout << WHITE << "["<< n << "] ";
    }
    std::cout << "\nfind 3 in the vector" << std::endl;
    try {
        auto it = easyfind(vec, 3);
        std::cout << "Found: " << *it << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << YELLOW << "Exception cought: " << WHITE  << e.what()<< std::endl;
    }
    std::cout << std::endl;

    std::array<int, 5> arr = {10, 20, 30, 40, 50};
    std::cout << WHITE << "array = ";
    for (auto n : arr) {
        std::cout << WHITE << "["<< n << "] ";
    }
    std::cout << "\nfind 20 in the array" << std::endl;
    try {
        auto it = easyfind(arr, 20);
        std::cout << GREEN << "Found: " << *it << WHITE << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << YELLOW << "Exception cought: " << WHITE  << e.what()<< std::endl;
    }
    std::cout << std::endl;

    std::list<int> lst;
    lst.push_back(1);
    lst.push_back(2);
    lst.push_back(3);
    lst.push_back(4);
    lst.push_back(5);
    lst.push_back(6);
    std::cout << WHITE << "list = ";
    for (auto n : lst) {
        std::cout << WHITE << "["<< n << "] ";
    }
    std::cout << "\nfind 20 in the list" << std::endl;
    try {
        auto it = easyfind(lst, 20);
        std::cout << GREEN << "Found: " << *it << WHITE << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << YELLOW << "Exception cought: " << WHITE  << e.what()<< std::endl;
    }
    std::cout << std::endl;

    std::deque<int> dq;
    dq.push_back(50);
    dq.push_back(60);
    dq.push_back(70);
    std::cout << WHITE << "deque = ";
    for (auto n : dq) {
        std::cout << WHITE << "["<< n << "] ";
    }
    std::cout << "\nfind 20 in the deque" << std::endl;
    try {
        auto it = easyfind(dq, 50);
        std::cout << GREEN << "Found: " << *it << WHITE << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << YELLOW << "Exception cought: " << WHITE  << e.what()<< std::endl;
    }
    std::cout << std::endl;

    std::set<double> set;
    set = {12.5, 24.2, 48.0};
    std::cout << WHITE << "set = ";
    for (auto n : set) {
        std::cout << WHITE << "["<< n << "] ";
    }
    std::cout << "\nfind 48 in the set" << std::endl;
    try {
        auto it = easyfind(set, 48);
        std::cout << GREEN << "Found: " << *it << WHITE << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << YELLOW << "Exception cought: " << WHITE  << e.what()<< std::endl;
    }

}
