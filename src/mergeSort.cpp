#include "mergeSort.hpp"
#include "item.hpp"



void merge(TypeItem*& characters, int first, int middle, int last) {
    int leftSize = middle - first + 1;
    int rightSize = last - middle;

    TypeItem* leftChar = new TypeItem[leftSize]();
    TypeItem* rightChar = new TypeItem[rightSize]();

    int leftIterator;
    int rightIterator;
    int charsIterator;

    for(leftIterator = 0; leftIterator < leftSize; leftIterator++) {
        leftChar[leftIterator] = characters[first + leftIterator];
    }
    for(rightIterator = 0; rightIterator < rightSize; rightIterator++) {
        rightChar[rightIterator] = characters[middle + rightIterator + 1];
    }

    leftIterator = 0;
    rightIterator = 0;
    charsIterator = first;
    while (leftIterator < leftSize && rightIterator < rightSize) {
        if(leftChar[leftIterator].GetFrequency() <= rightChar[rightIterator].GetFrequency()) {
            characters[charsIterator] = leftChar[leftIterator];
            leftIterator++;
        } else {
            characters[charsIterator] = rightChar[rightIterator];
            rightIterator++;
        }
        charsIterator++;
    }
    
    while (leftIterator < leftSize) {
        characters[charsIterator] = leftChar[leftIterator];
        leftIterator++;
        charsIterator++;
    }
    while (rightIterator < rightSize) {
        characters[charsIterator] = rightChar[rightIterator];
        rightIterator++;
        charsIterator++;
    }
    
    delete[] leftChar;
    delete[] rightChar;
}

void mergeSort(TypeItem* itens, int first, int last) {
    int middle;
    if(first < last) {
        middle = (first + last) / 2;
        mergeSort(itens, first, middle);
        mergeSort(itens, middle + 1, last);
        merge(itens, first, middle, last);
    }
}