#include "ScannerFunctions.h"
int main() {
    Signature testSignature("123455.zip");
    Signature testSignature2("123456.zip");
    bool aa = testSignature == testSignature2;
    ClearBase("AVBase.txt");
    testSignature.WriteToBase("AVBase.txt");
    testSignature2.WriteToBase("AVBase.txt");
    AVBase Base("AVBase.txt");
    Base.Print();
    ScanDirectory("C:\\CLionProjects\\3semestr", Base);
    return 0;
}
