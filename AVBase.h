//
// Created by Alexander on 21.01.2024.
//

#ifndef ANTIVIRUS_AVBASE_H
#define ANTIVIRUS_AVBASE_H
#include "Signature.h"
#include <vector>
#include <string>


class AVBase {
    std::vector<Signature> BaseVector;
public:
    AVBase(std::string Filename);
    void Print();
};


#endif //ANTIVIRUS_AVBASE_H
