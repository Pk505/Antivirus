//
// Created by Alexander on 21.01.2024.
//

#ifndef ANTIVIRUS_SIGNATURE_H
#define ANTIVIRUS_SIGNATURE_H
#include <string>
static const unsigned short signatureLength = 16;

class Signature {
private:
    char signatureData[signatureLength];
public:
    Signature(const Signature &oldSignature);
    Signature(const std::string FileName);
    Signature();
    void Print();
    void WriteToFile(const std::string FileName);

};


#endif //ANTIVIRUS_SIGNATURE_H
