
#include "AVBase.h"
#include <fstream>

int main() {
    Signature testSignature("123455.zip");
    ClearBase("AVBase.txt");
    testSignature.WriteToFile("AVBase.txt");
    testSignature.WriteToFile("AVBase.txt");
    AVBase Base("AVBase.txt");
    Base.Print();
    return 0;
}
