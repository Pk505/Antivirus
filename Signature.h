//
// Created by Alexander on 21.01.2024.
//

#ifndef ANTIVIRUS_SIGNATURE_H
#define ANTIVIRUS_SIGNATURE_H
#include <iostream>

class Signature {
    static const unsigned short signatureLength = 16;
private:
    char signatureData[signatureLength];
public:
    Signature(const Signature &oldSignature);
    Signature();
    void Print();
//    Signature& operator=(const Signature &oldSignature) {
//        // Оператор присваивания копирования
//        if (this != &oldSignature) {
//            for (int i = 0; i < signatureLength; i++) {
//                signatureData[i] = oldSignature.signatureData[i];
//            }
//        }
//        return *this;
//    }
//
//    Signature& operator=(Signature &&other) noexcept {
//        // Оператор присваивания перемещения
//        if (this != &other) {
//            for (int i = 0; i < signatureLength; i++) {
//                signatureData[i] = std::move(other.signatureData[i]);
//            }
//        }
//        return *this;
//    }

};


#endif //ANTIVIRUS_SIGNATURE_H
