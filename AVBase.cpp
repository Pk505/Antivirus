//
// Created by Alexander on 21.01.2024.
//

#include "AVBase.h"
#include <fstream>
#include <iostream>
AVBase::AVBase(const std::string& Filename) {
    std::ifstream file(Filename, std::ios::binary);
    while (file && file.peek() != EOF) {
        Signature signatureRead;
        file.read(reinterpret_cast<char *>(&signatureRead), sizeof(Signature));
        BaseVector.push_back(signatureRead);
    }

    file.close();
}


void AVBase::Print() {
    for (int i = 0; i < BaseVector.size(); i++) {
        BaseVector[i].Print();
        std::cout << std::endl;
    }
}

void ClearBase(const std::string Filename) {
    std::ofstream file(Filename, std::ios::binary | std::ios::trunc);
    file.close();
}

std::string AVBase::isFileInfected(const std::string &suspiciousFile)const {
    Signature suspiciousFileSignature(suspiciousFile);
    std::string result;
    for (auto & baseElement: BaseVector){
        if (suspiciousFileSignature == baseElement){
            result = suspiciousFile + " is INFECTED!!!";
            std::cout<<"FLAG!!!"<<std::endl;
        }
    }
    return result;
}

