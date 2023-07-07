#include "list.hpp"
#include "item.hpp"
#include <iostream>

LinkedList::LinkedList() : List() {
    first = new TypeCell();
    last = first;
}

LinkedList::~LinkedList() {
    Clean();
    delete first;
}

void LinkedList::InsertEnd(TypeItem item) {
    TypeCell *cell = new TypeCell();
    cell->SetItem(item);
    last->SetNext(cell);
    last = cell;
    size++;
}

void LinkedList::InsertItem(unsigned char* character) {
    TypeCell *p = first;
    bool newChar = true;
    for(int i = 0; i < size; i++) {
        if(p->GetItem().GetCharacter().GetCharacter() == character) {
            p->GetItem().IncrementFrequency();
            newChar = false;
            break;
        }
    }
    if(newChar) {
        TypeItem aux = TypeItem(TypeUTF8(character));
        InsertEnd(aux);
    }
}


void LinkedList::Clean() {
    TypeCell *p;

    p = first->GetNext();
    while (p != nullptr)
    {
        first->SetNext(p->GetNext());
        delete p;
        p = first->GetNext();
    }
    last = first;
    size = 0;
}

TypeItem* LinkedList::ListToVec() {
    TypeItem* charVec = new TypeItem[size];
    TypeCell* aux = first->GetNext();
    for(int i = 0; aux != nullptr; i++) {
        charVec[i] = aux->GetItem();
        aux = aux->GetNext();
    }
    return charVec;
}