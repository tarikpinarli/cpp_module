#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <string>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <ctime>
#include <sys/time.h>
#include <stdexcept>
#include <limits>

class PmergeMe {
private:
    std::vector<int> _dataVector;
    std::deque<int> _dataDeque;
    
    std::vector<int> generateJacobsthalSequence(size_t n);
    std::deque<int> generateJacobsthalSequenceDeque(size_t n);
    double getTime();
    void mergeInsertSortVector(std::vector<int>& arr);
    void insertionSortVector(std::vector<int>& arr, int left, int right);
    void mergeInsertSortDeque(std::deque<int>& arr);
    void insertionSortDeque(std::deque<int>& arr, int left, int right);

public:
    PmergeMe();
    ~PmergeMe();
    PmergeMe(const PmergeMe& other);
    PmergeMe& operator=(const PmergeMe& other);
    void parseInput(int argc, char** argv);
    void sort();
    void displayBefore() const;
    void displayAfter() const;
};

#endif