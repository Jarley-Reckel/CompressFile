#ifndef ITEM
#define ITEM

#include "UTF8.hpp"

class TypeItem {
    public:
        TypeItem();
        TypeItem(TypeUTF8 character);
        void IncrementFrequency();
        void SetFrequency(int frequency);
        TypeUTF8 GetCharacter();
        int GetFrequency();

    private:
        TypeUTF8 Character;
        int Frequency;
};

class TypeCell {
    public:
        TypeCell();

        TypeItem GetItem();
        TypeCell* GetNext();
        void SetItem(TypeItem newItem);
        void SetNext(TypeCell *cell);

    private:
        TypeItem item;
        TypeCell *next;

    friend class LinkedList;
};

#endif