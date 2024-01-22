//
// Created by Alexander on 21.01.2024.
//

#ifndef ANTIVIRUS_AVBASE_H
#define ANTIVIRUS_AVBASE_H
#include <iostream>
#include <vector>
#include "Signature.h"
#include <fstream>
#include <string>

class AVBase {
    unsigned int BaseSize = 0;
    Signature *BaseArray = nullptr;
public:
    AVBase(std::string Filename) {           //NEED to ADD ability to read more than one signature!!!!!
        std::ifstream file(Filename, std::ios::binary);
        Signature *temporarySignature = new Signature;
        file.read(reinterpret_cast<char *>(&BaseSize), sizeof(BaseSize));
        BaseArray = new Signature[BaseSize];
        int i = 0;
        while (file.read(reinterpret_cast<char *>(&BaseArray[i]), sizeof(Signature))) {
            i++;
        }
        file.close();
    }

    void Print() {
        for (int i = 0; i < BaseSize; i++) {
            BaseArray[i].Print();
            std::cout << std::endl;
        }
    }
    ~AVBase(){
        if (BaseArray != nullptr){
            delete[] BaseArray;
            BaseSize = 0;
        }
    }
};


#endif //ANTIVIRUS_AVBASE_H
