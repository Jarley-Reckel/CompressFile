#include <bitset>
#include "huffmanNode.hpp"
#include "item.hpp"
#include "UTF8.hpp"


HuffmanNode::HuffmanNode() {
    left = nullptr;
    right = nullptr;
}

HuffmanNode::HuffmanNode(TypeItem character) {
    CharacterUTF8 = character;
    left = nullptr;
    right = nullptr;
}

void HuffmanNode::SetFrequency(int frequency) {
    CharacterUTF8.SetFrequency(frequency);
}

void HuffmanNode::SetItem(TypeItem character) {
    CharacterUTF8 = character;
}

void HuffmanNode::SetLeft(HuffmanNode* node) {
    left = node;
}

void HuffmanNode::SetRight(HuffmanNode* node) {
    right = node;
}

int HuffmanNode::GetFrequency() {
    return CharacterUTF8.GetFrequency();
}

TypeUTF8 HuffmanNode::GetUTF8() {
    return CharacterUTF8.GetCharacter();
}

TypeItem HuffmanNode::GetItem() {
    return CharacterUTF8;
}

HuffmanNode* HuffmanNode::GetLeft() {
    return left;
}

HuffmanNode* HuffmanNode::GetRight() {
    return right;
}