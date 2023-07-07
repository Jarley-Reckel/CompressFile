#include "auxFunctions.hpp"
#include "UTF8.hpp"
#include "item.hpp"
#include "list.hpp"
#include <fstream>
#include <iostream>

bool checkPassArgument(int argc) {
    if(argc < 4) 
        return false;
    else
        return true;
}

TypeUTF8 PickUTF8InFile(std::ifstream& inputFile) {
    char curentChar;
    inputFile.get(curentChar);
    int8_t bytes = VerifyUTF8(curentChar);
    unsigned char utf8Char[bytes];
    utf8Char[0] = curentChar;
    for(int8_t i = 1; i < bytes; i++) {
        inputFile.get(curentChar);
        utf8Char[i] =  curentChar;
    }
    return TypeUTF8(utf8Char);
}

TypeItem* FindPriority(std::string fileName, int &numberOfChars) {
    std::ifstream inputFile;
    inputFile.open(fileName);
    if(!inputFile.is_open())
        throw unopened_file();

    LinkedList characters;
    while(!inputFile.eof()) {
        TypeUTF8 utf8Char = PickUTF8InFile(inputFile);
        characters.InsertItem(utf8Char.GetCharacter());
    }
    inputFile.close();
    numberOfChars = characters.GetSize();
    TypeItem* charVec = characters.ListToVec();
    //delete characters;
    return charVec;
}