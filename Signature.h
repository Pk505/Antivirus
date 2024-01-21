//
// Created by Alexander on 21.01.2024.
//

#ifndef ANTIVIRUS_SIGNATURE_H
#define ANTIVIRUS_SIGNATURE_H
#include <iostream>

class Signature {
    const unsigned short signatureSize = 16;
    char signatureData[16];
public:
    Signature(const Signature &oldSignature){
        for (int i = 0; i < 16; i++){
            signatureData[i] = oldSignature.signatureData[i];
        }
    }
    Signature(){
        for (int i = 0; i < 16; i++){
            signatureData[i] = 38;
        }
    }
    void Print(){
        for (int i = 0; i < 16; i++){
            std::cout<<signatureData[i]<<' ';
        }
    }
};


#endif //ANTIVIRUS_SIGNATURE_H
