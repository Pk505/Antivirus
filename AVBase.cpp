//
// Created by Alexander on 21.01.2024.
//

#include "AVBase.h"
AVBase::AVBase(std::string Filename) {
    std::ifstream file(Filename, std::ios::binary);
    unsigned int baseSize;
    file.read(reinterpret_cast<char *>(&baseSize), sizeof(baseSize));

    BaseVector.resize(baseSize); // Устанавливаем размер вектора

    for (int i = 0; i < baseSize; i++) {
        file.read(reinterpret_cast<char *>(&BaseVector[i]), sizeof(Signature));
    }

    file.close();
}


void AVBase::Print() {
    for (int i = 0; i < BaseVector.size(); i++) {
        BaseVector[i].Print();
        std::cout << std::endl;
    }
}

