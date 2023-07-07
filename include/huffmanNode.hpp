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
        TypeUTF8 GetUTF8();
        TypeItem GetItem();
        HuffmanNode* GetLeft();
        HuffmanNode* GetRight();

    private:
        TypeItem CharacterUTF8;
        HuffmanNode *left;
        HuffmanNode *right;
};


#endif