#include <iostream>
#include "AVBase.h"
int main() {
    Signature testSignature;
    std::ofstream file("AVBase.txt", std::ios::binary);
    file.write((char*)&testSignature,sizeof (Signature));
    file.close();
    Signature testSignature2;
    std::ifstream file2("AVBase.txt", std::ios::binary);
    file2.read((char*)&testSignature2,sizeof (Signature));
    file2.close();
    testSignature2.Print();
    return 0;
}
