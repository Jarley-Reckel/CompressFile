#include <string>
#include <fstream>
#include <bitset>
#include "descompressFile.hpp"
#include "huffmanFunctions.hpp"
#include "huffmanNode.hpp"
#include "UTF8.hpp"
#include "item.hpp"

void WriteInFile(HuffmanNode* root, std::ifstream& inputFile, std::ofstream& outputFile) {
    if(root->GetLeft() == nullptr && root->GetRight() == nullptr) {
        outputFile << root->GetUTF8().GetCharacterString();
        return;
    }
    if(inputFile.eof())
        return;
    char byte;
    inputFile.get(byte);
    if(byte == '1')
        WriteInFile(root->GetRight(), inputFile, outputFile);
    WriteInFile(root->GetLeft(), inputFile, outputFile);
}

void descompressFile(std::string inputFileName, std::string outputFileName) {
    std::ifstream inputFile;
    inputFile.open(inputFileName);
    std::ofstream outputFile;
    outputFile.open(outputFileName, std::ios::binary);

    std::string huffmanCode = "";

    unsigned char endCondition = 0b11111111;
    char byte;
    inputFile.get(byte);
    while(byte != endCondition) {
        std::bitset<8> byteBin(byte);
        huffmanCode += byteBin.to_string();
        inputFile.get(byte);
    }
    HuffmanNode* root = new HuffmanNode();
    int aux = 0;
    HuffmanCodeStringToTree(root, aux, huffmanCode);
    WriteInFile(root, inputFile, outputFile);  
    delete(root);
}