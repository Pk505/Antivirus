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
    std::vector<Signature> BaseVector;
public:
    AVBase(std::string Filename) {           //NEED to ADD ability to read more than one signature!!!!!
        std::ifstream file(Filename, std::ios::binary);
        Signature temporarySignature;
        file.read((char *) &temporarySignature, sizeof(Signature));
        temporarySignature.Print();
        BaseVector.push_back(temporarySignature); //NEED copy-constructor
        file.close();
    }
    void Print(){
        for (auto &i:BaseVector){
            i.Print();
            std::cout<<std::endl;
        }
    }
};


#endif //ANTIVIRUS_AVBASE_H
