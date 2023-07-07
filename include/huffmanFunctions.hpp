#ifndef HUFFMANFUNCTIONS
#define HUFFMANFUNCTIONS

#include <string>
#include "item.hpp"
#include "huffmanNode.hpp"


HuffmanNode* buildHuffmanTree(TypeItem* characters, int size);

void WriteHuffmanCodeString(HuffmanNode* root, std::string& codes);

std::string StringToBin(std::string& huffmanCode);

void HuffmanCodeStringToTree(HuffmanNode* root, int& position, std::string& codes);

bool FindCharacterInHuffmanTree(HuffmanNode* root, TypeUTF8 character, std::string& charCode);

#endif