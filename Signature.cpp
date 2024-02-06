//
// Created by Alexander on 21.01.2024.
//

#include "Signature.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <functional>

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

Signature::Signature(const std::string &FileName) {
    std::ifstream file(FileName, std::ios::binary);
    if (!file.is_open()) {
        std::cerr << "Unable to open file: " << FileName << std::endl;
    }

    // Initialize SHA-256 context
    std::stringstream sha256Context;
    std::hash<std::string> hasher;

    // Process file in chunks
    const size_t bufferSize = 4096;
    char buffer[bufferSize];
    while (!file.eof()) {
        file.read(buffer, bufferSize);
        sha256Context << std::string(buffer, file.gcount());
    }

    // Calculate the hash
    std::string hash = sha256Context.str();
    std::size_t hashValue = hasher(hash);

    // Convert the hash value to a hex string
    std::stringstream hashStream;
    hashStream << std::hex << hashValue;
    file.close();
    for (int i = 0; i < signatureLength; i++)
        signatureData[i] = hashStream.str()[i];
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

void Signature::WriteToBase(const std::string &BaseFileName) {
    std::ofstream file(BaseFileName, std::ios::binary | std::ios::app);
    file.write(reinterpret_cast<char *>(this), sizeof(Signature));
    file.close();
}

bool Signature::operator==(const Signature &other) const {
    return std::equal(this->signatureData, this->signatureData + signatureLength, other.signatureData);
}

