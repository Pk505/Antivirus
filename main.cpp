//#include "ScannerFunctions.h"
//int main() {
//    Signature testSignature("C:\\TEST FILE SYSTEM FOR ANTIVIRUS\\Directory 1\\File 1.3.exe");
//    //Signature testSignature2("C:\\TEST FILE SYSTEM FOR ANTIVIRUS\\Directory 1\\File 1.3.exe");
//    //bool aa = testSignature == testSignature2;
//    ClearBase("AVBase.txt");
//    testSignature.WriteToBase("AVBase.txt");
//   // testSignature2.WriteToBase("AVBase.txt");
//    AVBase Base("AVBase.txt");
//    Base.Print();
//    ScanDirectory("C:\\TEST FILE SYSTEM FOR ANTIVIRUS", Base);
//    return 0;
//}

#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}