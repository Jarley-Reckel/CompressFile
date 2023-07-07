#include "item.hpp"
#include <iostream>


TypeItem::TypeItem() {
    Frequency = 0;
}

TypeItem::TypeItem(TypeUTF8 character) {
    Frequency = 1;
    Character = character;
}

void TypeItem::IncrementFrequency() {
    Frequency++;
}

void TypeItem::SetFrequency(int frequency){
    Frequency = frequency;
}

TypeUTF8 TypeItem::GetCharacter() {
    return Character;
}

int TypeItem::GetFrequency() {
    return Frequency;
}

TypeCell::TypeCell() {
    item = TypeItem();
    next = nullptr;
}

TypeItem TypeCell::GetItem() {
    return item;
}

TypeCell *TypeCell::GetNext() {
    return next;
}

void TypeCell::SetItem(TypeItem newItem) {
    item = newItem;
}

void TypeCell::SetNext(TypeCell *cell) {
    next = cell;
}
