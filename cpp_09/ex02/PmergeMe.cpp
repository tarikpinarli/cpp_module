#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& other) : _dataVector(other._dataVector), _dataDeque(other._dataDeque) {}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
    if (this != &other) {
        _dataVector = other._dataVector;
        _dataDeque = other._dataDeque;
    }
    return *this;
}

double PmergeMe::getTime() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (tv.tv_sec * 1000000.0 + tv.tv_usec);
}

void PmergeMe::parseInput(int argc, char** argv) {
    if (argc < 2) {
        throw std::runtime_error("Error: No input provided");
    }

    for (int i = 1; i < argc; i++) {
        std::string arg = argv[i];

        // Check for empty argument
        if (arg.empty()) {
            throw std::runtime_error("Error: Empty argument");
        }

        // Check for negative numbers or invalid characters
        for (size_t j = 0; j < arg.length(); j++) {
            if (!std::isdigit(arg[j])) {
                throw std::runtime_error("Error: Invalid input");
            }
        }

        // Convert to long to check for overflow
        std::istringstream iss(arg);
        long num;
        iss >> num;

        if (iss.fail() || num < 0 || num > std::numeric_limits<int>::max()) {
            throw std::runtime_error("Error: Invalid number");
        }

        _dataVector.push_back(static_cast<int>(num));
        _dataDeque.push_back(static_cast<int>(num));
    }

    if (_dataVector.empty()) {
        throw std::runtime_error("Error: No valid numbers provided");
    }
}

// Generate Jacobsthal numbers for optimal insertion order
std::vector<int> PmergeMe::generateJacobsthalSequence(size_t n) {
    std::vector<int> jacobsthal;
    if (n == 0)
        return jacobsthal;

    jacobsthal.push_back(0);
    if (n == 1)
        return jacobsthal;

    jacobsthal.push_back(1);

    while (true) {
        size_t next = jacobsthal[jacobsthal.size() - 1] + 2 * jacobsthal[jacobsthal.size() - 2];
        if (next >= n) break;
        jacobsthal.push_back(next);
    }

    return jacobsthal;
}

std::deque<int> PmergeMe::generateJacobsthalSequenceDeque(size_t n) {
    std::deque<int> jacobsthal;
    if (n == 0) return jacobsthal;

    jacobsthal.push_back(0);
    if (n == 1) return jacobsthal;

    jacobsthal.push_back(1);

    while (true) {
        size_t next = jacobsthal[jacobsthal.size() - 1] + 2 * jacobsthal[jacobsthal.size() - 2];
        if (next >= n) break;
        jacobsthal.push_back(next);
    }

    return jacobsthal;
}

void PmergeMe::insertionSortVector(std::vector<int>& arr, int left, int right) {
    for (int i = left + 1; i <= right; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= left && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void PmergeMe::insertionSortDeque(std::deque<int>& arr, int left, int right) {
    for (int i = left + 1; i <= right; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= left) {
            _vectorComparisonCount++;
            if (arr[j] > key) {
                arr[j + 1] = arr[j];
                j--;
            } else {
                break; // Found the spot
            }
        }
        arr[j + 1] = key;
    }
}

// Ford-Johnson Algorithm for Vector
void PmergeMe::mergeInsertSortVector(std::vector<int>& arr) {
    size_t n = arr.size();

    // Base case: use insertion sort for small arrays
    if (n <= 16) {
        insertionSortVector(arr, 0, n - 1);
        return;
    }

    // Step 1: Group elements into pairs and sort each pair
    std::vector<std::pair<int, int> > pairs;
    int straggler = -1;
    bool hasStraggler = (n % 2 != 0);

    if (hasStraggler) {
        straggler = arr[n - 1];
    }

    for (size_t i = 0; i < (hasStraggler ? n - 1 : n); i += 2) {
        int a = arr[i];
        int b = arr[i + 1];
        _vectorComparisonCount++;
        if (a > b) {
            pairs.push_back(std::make_pair(b, a));
        } else {
            pairs.push_back(std::make_pair(a, b));
        }
    }

    // Step 2: Sort pairs by their larger element (recursive)
    if (pairs.size() > 1) {
        std::vector<int> largerElements;
        for (size_t i = 0; i < pairs.size(); i++) {
            largerElements.push_back(pairs[i].second);
        }

        mergeInsertSortVector(largerElements);

        // Reconstruct pairs with sorted larger elements
        std::vector<std::pair<int, int> > sortedPairs;
        for (size_t i = 0; i < largerElements.size(); i++) {
            for (size_t j = 0; j < pairs.size(); j++) {
                if (pairs[j].second == largerElements[i]) {
                    sortedPairs.push_back(pairs[j]);
                    pairs[j].second = -1; // Mark as used
                    break;
                }
            }
        }
        pairs = sortedPairs;
    }

    // Step 3: Create main chain with larger elements
    std::vector<int> mainChain;
    std::vector<int> pending;

    for (size_t i = 0; i < pairs.size(); i++) {
        mainChain.push_back(pairs[i].second);
        pending.push_back(pairs[i].first);
    }

    // Step 4: Insert first smaller element
    if (!pending.empty()) {
        mainChain.insert(mainChain.begin(), pending[0]);
        pending.erase(pending.begin());
    }

    // Step 5: Insert remaining elements using Jacobsthal sequence
    std::vector<int> jacobsthal = generateJacobsthalSequence(pending.size() + 1);
    std::vector<bool> inserted(pending.size(), false);

    for (size_t j = 2; j < jacobsthal.size(); j++) {
        int index = jacobsthal[j];
        int prevIndex = jacobsthal[j - 1];

        for (int i = std::min(index, static_cast<int>(pending.size())) - 1; i >= prevIndex; i--) {
            if (i >= 0 && i < static_cast<int>(pending.size()) && !inserted[i]) {
                int value = pending[i];
                std::vector<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), value);
                mainChain.insert(pos, value);
                inserted[i] = true;
            }
        }
    }

    // Insert any remaining elements
    for (size_t i = 0; i < pending.size(); i++) {
        if (!inserted[i]) {
            int value = pending[i];
            std::vector<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), value);
            mainChain.insert(pos, value);
        }
    }

    // Insert straggler if exists
    if (hasStraggler) {
        std::vector<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), straggler);
        mainChain.insert(pos, straggler);
    }

    arr = mainChain;
}

// Ford-Johnson Algorithm for Deque (similar implementation)
void PmergeMe::mergeInsertSortDeque(std::deque<int>& arr) {
    size_t n = arr.size();

    if (n <= 16) {
        insertionSortDeque(arr, 0, n - 1);
        return;
    }

    std::vector<std::pair<int, int> > pairs;
    int straggler = -1;
    bool hasStraggler = (n % 2 != 0);

    if (hasStraggler) {
        straggler = arr[n - 1];
    }

    for (size_t i = 0; i < (hasStraggler ? n - 1 : n); i += 2) {
        int a = arr[i];
        int b = arr[i + 1];
        _dequeComparisonCount++;
        if (a > b) {
            pairs.push_back(std::make_pair(b, a));
        } else {
            pairs.push_back(std::make_pair(a, b));
        }
    }

    if (pairs.size() > 1) {
        std::deque<int> largerElements;
        for (size_t i = 0; i < pairs.size(); i++) {
            largerElements.push_back(pairs[i].second);
        }

        mergeInsertSortDeque(largerElements);

        std::vector<std::pair<int, int> > sortedPairs;
        for (size_t i = 0; i < largerElements.size(); i++) {
            for (size_t j = 0; j < pairs.size(); j++) {
                if (pairs[j].second == largerElements[i]) {
                    sortedPairs.push_back(pairs[j]);
                    pairs[j].second = -1;
                    break;
                }
            }
        }
        pairs = sortedPairs;
    }

    std::deque<int> mainChain;
    std::deque<int> pending;

    for (size_t i = 0; i < pairs.size(); i++) {
        mainChain.push_back(pairs[i].second);
        pending.push_back(pairs[i].first);
    }

    if (!pending.empty()) {
        mainChain.push_front(pending[0]);
        pending.pop_front();
    }

    std::deque<int> jacobsthal = generateJacobsthalSequenceDeque(pending.size() + 1);
    std::vector<bool> inserted(pending.size(), false);

    for (size_t j = 2; j < jacobsthal.size(); j++) {
        int index = jacobsthal[j];
        int prevIndex = jacobsthal[j - 1];

        for (int i = std::min(index, static_cast<int>(pending.size())) - 1; i >= prevIndex; i--) {
            if (i >= 0 && i < static_cast<int>(pending.size()) && !inserted[i]) {
                int value = pending[i];
                std::deque<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), value);
                mainChain.insert(pos, value);
                inserted[i] = true;
            }
        }
    }

    for (size_t i = 0; i < pending.size(); i++) {
        if (!inserted[i]) {
            int value = pending[i];
            std::deque<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), value);
            mainChain.insert(pos, value);
        }
    }

    if (hasStraggler) {
        std::deque<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), straggler);
        mainChain.insert(pos, straggler);
    }

    arr = mainChain;
}

void PmergeMe::sort() {
    double startVector;
    double endVector;
    double startDeque;
    double endDeque;

    // Sort with vector
    std::vector<int> vecCopy = _dataVector;
    startVector = getTime();
    mergeInsertSortVector(vecCopy);
    endVector = getTime();

    // Sort with deque
    std::deque<int> dequeCopy = _dataDeque;
    startDeque = getTime();
    mergeInsertSortDeque(dequeCopy);
    endDeque = getTime();

    // Update data with sorted results
    _dataVector = vecCopy;
    _dataDeque = dequeCopy;

    // Display results
    displayAfter();
    std::cout << std::endl;

    double timeVector = endVector - startVector;
    double timeDeque = endDeque - startDeque;

    std::cout << "Time to process a range of " << _dataVector.size()
              << " elements with std::vector : " << timeVector << " us" << std::endl;
    std::cout << "Time to process a range of " << _dataDeque.size()
              << " elements with std::deque  : " << timeDeque << " us" << std::endl;
}

void PmergeMe::displayBefore() const {
    std::cout << std::endl;
    std::cout << "Before: ";
    for (size_t i = 0; i < _dataVector.size() && i < 5; i++) {
        std::cout << _dataVector[i] << " ";
    }
    if (_dataVector.size() > 5) {
        std::cout << "[...]";
    }
    std::cout << std::endl;
}

void PmergeMe::displayAfter() const {

    std::cout << "After:  ";
    for (size_t i = 0; i < _dataVector.size() && i <= 5; i++) {
        std::cout << _dataVector[i] << " ";
    }
    if (_dataVector.size() > 5) {
        std::cout << "[...]";
    }
    std::cout << std::endl;
    std::cout << "Comparison count for Vector = " << _vectorComparisonCount << std::endl;
    std::cout << "Comparison count for Deque = " << _vectorComparisonCount << std::endl;
}
