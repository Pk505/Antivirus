//
// Created by Alexander on 21.01.2024.
//

#include "Signature.h"
Signature::Signature(const Signature &oldSignature) {
    for (int i = 0; i < signatureLength; i++){
        signatureData[i] = oldSignature.signatureData[i];
    }
}

Signature::Signature() {
    for (int i = 0; i < signatureLength; i++){
        signatureData[i] = 0;
    }
}

void Signature::Print() {
    for (int i = 0; i < signatureLength; i++){
        std::cout<<signatureData[i]<<' ';
    }
}
