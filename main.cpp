#include "ScannerFunctions.h"
int main() {
    Signature testSignature("C:\\Windows\\HelpPane.exe");
    Signature testSignature2("C:\\Windows\\HelpPane.exe");
    bool aa = testSignature == testSignature2;
    ClearBase("AVBase.txt");
    testSignature.WriteToBase("AVBase.txt");
    testSignature2.WriteToBase("AVBase.txt");
    AVBase Base("AVBase.txt");
    Base.Print();
    //ScanDirectory("C:\\CLionProjects\\3semestr", Base);
    return 0;
}
