
#include "AVBase.h"
#include <fstream>

int main() {
    Signature testSignature;
    testSignature.WriteToFile("AVBase.txt");
    testSignature.WriteToFile("AVBase.txt");
    AVBase Base("AVBase.txt");
    Base.Clear("AVBase.txt");
    Base.Print();
    return 0;
}
