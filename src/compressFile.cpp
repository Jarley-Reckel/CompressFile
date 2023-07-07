#include <fstream>
#include <string>
#include <bitset>
#include "compressFile.hpp"
#include "huffmanNode.hpp"
#include "huffmanFunctions.hpp"
#include "mergeSort.hpp"
#include "auxFunctions.hpp"


HuffmanNode* huffmanTree(std::string inputFileName) {
    TypeItem* characterPriority;
    int size = 0;
    try{
        characterPriority = FindPriority(inputFileName, size);
    } catch(unopened_file& error) {
        std::cout << error.what() << std::endl;
    }
    mergeSort(characterPriority, 0, size);
    HuffmanNode* root = buildHuffmanTree(characterPriority, size);
    return root;
}

void WriteInFile(std::ofstream& outputFile, std::string& text) {
    std::string binString = StringToBin(text);
    outputFile << binString;
}

void encodeFile(HuffmanNode* root, std::string inputFileName, std::string outputFileName) {
    std::string huffmanCode;
    WriteHuffmanCodeString(root, huffmanCode);

    std::ifstream inputFile;
    inputFile.open(inputFileName);
    std::ofstream outputFile;
    outputFile.open(outputFileName, std::ios::binary);

    WriteInFile(outputFile, huffmanCode);

    std::string text = "";
    while(!inputFile.eof()) {
        TypeUTF8 utf8Char = PickUTF8InFile(inputFile);
        FindCharacterInHuffmanTree(root, utf8Char, text);
        std::string curentUTF8 = utf8Char.GetCharacterString();
        for(int i = 0; i < curentUTF8.size(); i++) {
            std::bitset<8> charBin(curentUTF8[i]);
            std::string binString = charBin.to_string();
            std::cout << binString << std::endl;
        }
    }
    WriteInFile(outputFile, text);
    inputFile.close();
    outputFile.close();
}

void compressFile(std::string inputFileName, std::string outputFileName) {
    HuffmanNode* root = huffmanTree(inputFileName);
    encodeFile(root, inputFileName, outputFileName);
}