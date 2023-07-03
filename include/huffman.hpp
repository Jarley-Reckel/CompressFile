#ifndef HUFFMAN
#define HUFFMAN

#include <string>
#include "item.hpp"


class HuffmanNode {
    public:
        HuffmanNode();
        HuffmanNode(TypeItem character);
        void SetFrequency(int frequency);
        void SetItem(TypeItem character);
        void SetLeft(HuffmanNode* node);
        void SetRight(HuffmanNode* node);
        int GetFrequency();
        char GetCharacter();
        HuffmanNode* GetLeft();
        HuffmanNode* GetRight();

    private:
        TypeItem Character;
        HuffmanNode *left;
        HuffmanNode *right;
};

HuffmanNode* buildHuffmanTree(TypeItem* characteres, int size);

void WriteHuffmanCode(HuffmanNode* root, std::string* codes);

void HuffmanCodeToTree(HuffmanNode* root, int* position, std::string* codes);


#endif