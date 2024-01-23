//
// Created by Alexander on 21.01.2024.
//

#include "Signature.h"
#include <iostream>
#include <fstream>


bool isFileEmpty(const std::string &filename) {
    std::ifstream file(filename, std::ios::binary | std::ios::in);

    if (!file.is_open()) {
        std::cerr << "Unable to open file!" << std::endl;
        return false;
    }
    bool result = file.peek() == std::ifstream::traits_type::eof();
    file.close();
    return result;
}

Signature::Signature(const Signature &oldSignature) {
    for (int i = 0; i < signatureLength; i++) {
        signatureData[i] = oldSignature.signatureData[i];
    }
}

Signature::Signature() {
    for (int i = 0; i < signatureLength; i++) {
        signatureData[i] = 38;
    }
}

void Signature::Print() {
    for (int i = 0; i < signatureLength; i++) {
        std::cout << signatureData[i] << ' ';
    }
}

void Signature::WriteToFile(const std::string FileName) {
    std::ofstream file(FileName, std::ios::binary);
    file.write(reinterpret_cast<char *>(this), sizeof(Signature));
    file.close();
}