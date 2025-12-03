#include "PmergeMe.hpp"

int main(int argc, char** argv) {
    try {
        PmergeMe pmerge;
        
        // Parse input from command line arguments
        pmerge.parseInput(argc, argv);
        
        // Display before sorting
        pmerge.displayBefore();
        
        // Sort and display results with timing
        pmerge.sort();
        
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}