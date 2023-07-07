#include <string.h>
#include <bitset>
#include "huffmanFunctions.hpp"
#include "huffmanNode.hpp"
#include "item.hpp"
#include "UTF8.hpp"


HuffmanNode** buildLeafs(TypeItem* characters, int size) {
    HuffmanNode** huffmanLeaf = new HuffmanNode*[size];
    for(int i = 0; i < size; i++) {
        huffmanLeaf[i]->SetItem(characters[i]);
    }
    return huffmanLeaf;
}

HuffmanNode* SetDad(HuffmanNode** huffmanLeaf, int position) {
    HuffmanNode* dad = new HuffmanNode();
    dad->SetLeft(new HuffmanNode(huffmanLeaf[position]->GetItem()));
    dad->SetRight(new HuffmanNode(huffmanLeaf[position-1]->GetItem()));
    int sumFrequency = dad->GetLeft()->GetFrequency() + dad->GetRight()->GetFrequency();
    dad->SetFrequency(sumFrequency);
    return dad;
}

void rebuildLeafs(HuffmanNode** huffmanLeaf, HuffmanNode* dad, int position) {
    bool inserted = false;
    int j = position - 1;
    while(!inserted) {
        if(dad->GetFrequency() < huffmanLeaf[j-1]->GetFrequency()) {
            huffmanLeaf[position] = dad;
            inserted = true;
        } else {
            huffmanLeaf[j] = huffmanLeaf[j-1];
        }
        j--;
    }
}

HuffmanNode* LeafToTree(HuffmanNode** huffmanLeaf, int size) {
    for(int i = size - 1; i >= 0; i--) {
        HuffmanNode* dad = SetDad(huffmanLeaf, i);
        rebuildLeafs(huffmanLeaf, dad, i); 
    }
    return *huffmanLeaf;
}


HuffmanNode* buildHuffmanTree(TypeItem* characters, int size) {
    HuffmanNode** huffmanLeaf = buildLeafs(characters, size);
    HuffmanNode* root = LeafToTree(huffmanLeaf, size);
    return root;
}

bool isLeaf(HuffmanNode* root) {
    if(root->GetLeft() == nullptr && root->GetRight() == nullptr)
        return true;
    return false;
}

void WriteCharInHuffmanCode(HuffmanNode* root, std::string& codes) {
    codes += '1';
    int8_t bytes = root->GetUTF8().GetBytes();
    unsigned char* utf8Char = root->GetUTF8().GetCharacter();
    for(int8_t i = 0; i < bytes; i++) {
        std::bitset<8> charBin(utf8Char[i]);
        std::string binString = charBin.to_string();
        codes.append(binString);
    }
}
void continueWrite(HuffmanNode* root, std::string& codes) {
    codes += '0';
    WriteHuffmanCodeString(root->GetLeft(), codes);
    WriteHuffmanCodeString(root->GetRight(), codes);
}


void WriteHuffmanCodeString(HuffmanNode* root, std::string& codes) {
    if(isLeaf(root)) {
        WriteCharInHuffmanCode(root, codes);
        return;
    }
    continueWrite(root, codes);
}

std::string StringToBin(std::string& huffmanCode) {
    std::string binCode = "";
    int i = 0;
    while(huffmanCode.size() - i < 9) {
        int8_t decimalValue = stoi(huffmanCode.substr(i,i+8), nullptr, 2);
        i += 8;
        unsigned char byte = static_cast<char>(decimalValue);
        binCode += byte;
    }
    std::string endBits = huffmanCode.substr(i, huffmanCode.size());
    while(endBits.size() < 9) {
        endBits += "0";
    }
    int8_t decimalValue = stoi(endBits);
    unsigned char byte = static_cast<char>(decimalValue);
    binCode += byte;
    unsigned char lastChar = 0b11111111;
    binCode += lastChar;
    return binCode;
}

bool foundLeaf(int& position, std::string& codes) {
    if(codes[position] == '1')
        return true;
    return false;
}

void buildLeaf(HuffmanNode* root, int& position, std::string& codes) {
    position++;
    int8_t bytes = VerifyUTF8(codes.substr(position, position + 8));
    unsigned char utf8Char[bytes];
    for(int8_t i = 0; i < bytes; i++) {
        std::bitset<8> bits(codes.substr(position, position + 8));
        position += 8;
        int8_t decimalChar = bits.to_ulong();
        unsigned char character = static_cast<unsigned char>(decimalChar);
        utf8Char[bytes] = character;
    }
    TypeUTF8 characterUTF8 = TypeUTF8(utf8Char);
    root->SetItem(characterUTF8);
}

void continueCodeToTree(HuffmanNode* root, int& position, std::string& codes) {
    position++;
    root->SetLeft(new HuffmanNode());
    HuffmanCodeStringToTree(root->GetLeft(), position, codes);
    root->SetRight(new HuffmanNode());
    HuffmanCodeStringToTree(root->GetRight(), position, codes);
}

bool lastChar(int& position, int size) {
    if(size - position < 9)
        return true;
    return false;
}

void HuffmanCodeStringToTree(HuffmanNode* root, int& position, std::string& codes) {
    if(root == nullptr)
        return;
    
    if(foundLeaf(position, codes)) {
        buildLeaf(root, position, codes);
        return;
    }

    if(lastChar(position, codes.size()))int8_t VerifyUTF8(std::bitset<8> bits);
        return;
    continueCodeToTree(root, position, codes);
}

bool FindCharacterInHuffmanTree(HuffmanNode* root, TypeUTF8 character, std::string& charCode) {
    if(root == nullptr)
        return false;
    if(root->GetUTF8() == character)
        return true;
    if(FindCharacterInHuffmanTree(root->GetLeft(), character, charCode)) {
        charCode = "0" + charCode;
        return true;
    }
    if(FindCharacterInHuffmanTree(root->GetRight(), character, charCode)) {
        charCode += "1" + charCode;
        return true;
    }
    return false;
}