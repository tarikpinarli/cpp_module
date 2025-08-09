#include <iostream>
#include "Replace.hpp"

int main(int argc, char** argv) {
    if (argc != 4) {
        std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>\n";
        return 1;
    }

    const std::string filename = argv[1];
    const std::string s1 = argv[2];
    const std::string s2 = argv[3];

    std::string err;
    if (!replace_file(filename, s1, s2, err)) {
        std::cerr << "Error: " << err << "\n";
        return 1;
    }

    std::cout << "Created: " << filename << ".replace\n";
    return 0;
}
