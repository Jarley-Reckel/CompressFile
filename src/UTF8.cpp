#include "UTF8.hpp"
#include <string>
#include <bitset>


TypeUTF8::TypeUTF8() {
    Character = nullptr;
    Bytes = -1;
}

TypeUTF8::TypeUTF8(unsigned char* character) {
    int8_t numBytes = VerifyUTF8(character[0]);
    if(numBytes == 0){
        Character = nullptr;
        Bytes = -1;
    } else {
        Character = character;
        Bytes = numBytes;
    }
}

bool TypeUTF8::SetCharacter(unsigned char* character) {
    int8_t numBytes = VerifyUTF8(character[0]);
    if(numBytes == 0)
        return false;
    Character = character;
    Bytes = numBytes;
    return true;
}

unsigned char* TypeUTF8::GetCharacter() {
    return Character;
}

std::string TypeUTF8::GetCharacterString() {
    std::string UTF8String = "";
    for(int i = 0; i < Bytes; i++) {
        UTF8String += Character[i];
    }
    return UTF8String;
}

int TypeUTF8::GetBytes() {
    return Bytes;
}

bool TypeUTF8::operator==(const TypeUTF8& itIqual) const {
    if(Bytes < 0 || itIqual.Bytes < 0)
        return false;
    if(Bytes != itIqual.Bytes)
        return false;
    for(int8_t i = 0; i < Bytes; i++) {
        if(Character[i] != itIqual.Character[i])
            return false;
    }
    return true;
}

int8_t VerifyUTF8(unsigned char byte) {
    if((byte & 0b1) == 0b0)
        return 1;
    if((byte & 0b111) == 0b110)
        return 2;
    if((byte & 0b1111) == 0b1110)
        return 3;
    if((byte & 0b11111) == 0b11110)
        return 4;
    return 0;
}

int8_t VerifyUTF8(std::string byte) {
    if(byte[0] == '0')
        return 1;
    if(byte.substr(0,2) == "110")
        return 2;
    if(byte.substr(0,3) == "1110")
        return 3;
    if(byte.substr(0,4) == "11110")
        return 4;
    return 0;
}