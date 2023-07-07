#ifndef UTF8
#define UTF8

#include <string>
#include <bitset>

class TypeUTF8 {
    public:
        TypeUTF8();
        TypeUTF8(unsigned char* character);
        bool SetCharacter(unsigned char* character);
        unsigned char* GetCharacter();
        std::string GetCharacterString();
        int GetBytes();
        bool operator==(const TypeUTF8& outro) const;

    private:
        unsigned char* Character;
        int8_t Bytes;
};

int8_t VerifyUTF8(unsigned char byte);
int8_t VerifyUTF8(std::string byte);

#endif