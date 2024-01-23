//
// Created by Alexander on 21.01.2024.
//

#ifndef ANTIVIRUS_AVBASE_H
#define ANTIVIRUS_AVBASE_H
#include "Signature.h"
#include <vector>


class AVBase {
    std::vector<Signature> BaseVector;
public:
    AVBase(const std::string Filename);
    void Print();

};
void ClearBase(const std::string Filename);

#endif //ANTIVIRUS_AVBASE_H
