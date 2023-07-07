#ifndef AUXFUNCTIONS
#define AUXFUNCTIONS

#include "item.hpp"
#include "UTF8.hpp"
#include <iostream>
#include <fstream>


bool checkPassArgument(int argc);

TypeUTF8 PickUTF8InFile(std::ifstream& inputFile);

TypeItem* FindPriority(std::string fileName, int &numberOfChars);

class unopened_file : public std::exception {

    public:
        virtual const char* what() const throw() { 
            return "Erro: Can't open file!";
        }
};

#endif