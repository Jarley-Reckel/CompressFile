#ifndef LIST
#define LIST

#include "item.hpp"

class List
{
    public:
        List() {size = 0;};
        int GetSize() {return size;};
        bool Empty() {return size == 0;};

        virtual void InsertEnd(TypeItem item) = 0;
        virtual void InsertItem(unsigned char* character) = 0;
        virtual void Clean() = 0;

    protected:
        int size;
};

class LinkedList : public List
{
    public:
        LinkedList();
        virtual ~LinkedList();

        void InsertEnd(TypeItem item);
        void InsertItem(unsigned char* character);
        void Clean();
        TypeItem* ListToVec();

    private:
        TypeCell* first;
        TypeCell* last;          
};

#endif