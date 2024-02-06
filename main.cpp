#include "ScannerFunctions.h"
int main() {
    Signature testSignature("C:\\TEST FILE SYSTEM FOR ANTIVIRUS\\Directory 1\\File 1.3.exe");
    //Signature testSignature2("C:\\TEST FILE SYSTEM FOR ANTIVIRUS\\Directory 1\\File 1.3.exe");
    //bool aa = testSignature == testSignature2;
    ClearBase("AVBase.txt");
    testSignature.WriteToBase("AVBase.txt");
   // testSignature2.WriteToBase("AVBase.txt");
    AVBase Base("AVBase.txt");
    Base.Print();
    ScanDirectory("C:\\TEST FILE SYSTEM FOR ANTIVIRUS", Base);
    return 0;
}
