#include "BitcoinExchange.hpp"

int main(int argc, char** argv) {
    std::string dataFile;
    if (argc != 2) {
        std::cout << "Wrong argument count!\nUsage: ./btc <data_file>\n";
        return 1;
    }
    dataFile = argv[1];
    try
    {
        BitcoinExchange btc(argv[1]);
        btc.loadData(btc.getDataFileName());
        btc.printRates();
    }
    catch(const std::exception& e)
    {
        std::cerr << "Exception cought: " << e.what() << '\n';
    }



    return 0;
}
