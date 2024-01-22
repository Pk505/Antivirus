#include <iostream>
#include "AVBase.h"
int main() {
    Signature testSignature;
    std::ofstream file("AVBase.txt", std::ios::binary);
    unsigned int size = 1;
    file.write((char*)&size,sizeof (int));
    file.write((char*)&testSignature,sizeof (Signature));
    file.close();
    AVBase Base("AVBase.txt");
    Base.Print();
    return 0;
}
