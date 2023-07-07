#include <iostream>

#include "auxFunctions.hpp"
#include "item.hpp"
#include "mergeSort.hpp"
#include "huffmanNode.hpp"
#include "huffmanFunctions.hpp"
#include "compressFile.hpp"
#include "descompressFile.hpp"


int main(int argc, char **argv) {

    if(checkPassArgument(argc) == false)
        return 1;

    std::string inputFileName(argv[1]);
    std::string outputFileName(argv[2]);

    if(argv[3] == "-c") {
        compressFile(inputFileName, outputFileName);
    } else if(argv[3] == "-d") {
        descompressFile(inputFileName, outputFileName);
    }
    return 0;
}
