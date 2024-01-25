
#include "AVBase.h"
#include "ScannerFunctions.h"
#include <fstream>

int main() {
    Signature testSignature("123455.zip");
    ClearBase("AVBase.txt");
    testSignature.WriteToFile("AVBase.txt");
    testSignature.WriteToFile("AVBase.txt");
    AVBase Base("AVBase.txt");
    Base.Print();
    ScanDirectory("C:\\CLionProjects\\3semestr"  );
    return 0;
}
