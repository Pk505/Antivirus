#include <SFML/Graphics.hpp>
#include <iostream>
#include "ScannerFunctions.h"
//int main() {
//    Signature testSignature("/home/vboxuser/TEST_FILESYSTEM/Directory/FILE1.py");
//   // Signature testSignature2("C:\\TEST FILE SYSTEM FOR ANTIVIRUS\\Directory 1\\File 1.3.exe");
//    //bool aa = testSignature == testSignature2;
//    ClearBase("AVBase.txt");
//    testSignature.WriteToBase("AVBase.txt");
//   // testSignature2.WriteToBase("AVBase.txt");
//    AVBase Base("AVBase.txt");
//    Base.Print();
//    ScanDirectory("/home/vboxuser/TEST_FILESYSTEM", Base);
//    return 0;
//}


class FocusObject
{
public:
    virtual void setFocus () = 0 ;
    virtual void deleteFocus () = 0 ;
    virtual void event ( const sf::Event & ) = 0 ;
} ;



class TextBox : public sf::Drawable , public FocusObject /*, public sf::Transformable */
{
public:
    TextBox ( const sf::Text & text ) : m_text ( text )
    {
        m_newText = m_text.getString() ;
        updateRect() ;
        m_box.setFillColor( sf::Color::Blue ) ;
    }
    virtual void draw ( sf::RenderTarget & render , sf::RenderStates states ) const
    {
        if ( m_textChanged )
        {
            const_cast<TextBox*>(this)->setText ( m_newText ) ;

            m_textChanged = false ;
        }
        render.draw ( m_box , states ) ;
        render.draw ( m_text , states ) ;
    }
    virtual void setFocus ()
    {
        m_box.setFillColor( sf::Color::Red ) ;
    }
    virtual void deleteFocus ()
    {
        m_box.setFillColor( sf::Color::Blue ) ;
    }
    virtual void event ( const sf::Event & event )
    {
        if (event.type == sf::Event::TextEntered)
        {
            //Обработка ввода
            m_textChanged = true ;
            switch ( event.text.unicode )
            {
                case 0xD: //Return
                    m_newText += L'\n' ;
                    break ;
                case 0x8://Backspace
                    if ( !m_newText.isEmpty() )
                        m_newText.erase(m_newText.getSize()-1) ;
                    break ;
                default :
                {
                    m_newText += static_cast<wchar_t>(event.text.unicode) ;
                }
            }
        }
    }
    void setText ( const sf::String & str )
    {
        m_text.setString ( str ) ;
        updateRect() ;
    }
private:
    void updateRect ()
    {
        sf::FloatRect rect = m_text.getGlobalBounds() ;
        m_box.setPosition ( rect.left-5 , rect.top-5 ) ;
        m_box.setSize( sf::Vector2f(rect.width+10 , rect.height+10) ) ;
    }
    mutable sf::RectangleShape m_box ;
    mutable sf::Text m_text ;
    mutable sf::String m_newText ;
    mutable bool m_textChanged ;
} ;



class FocusController
{
public:
    FocusController ( FocusObject * obj = 0 ) : m_object (obj)
    {
        if ( m_object != 0 )
        {
            m_object->setFocus () ;
        }
    }
    void setFocusObject ( FocusObject * new_obj )
    {
        if ( m_object == new_obj )
            return ;
        if ( m_object != 0 )
            m_object->deleteFocus() ;
        if ( new_obj != 0 )
            new_obj->setFocus() ;
        m_object = new_obj ;
    }
    FocusObject * getFocusObject ( )
    {
        return m_object ;
    }

private:
    FocusObject * m_object ;
} ;

FocusController fc ;


int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Antivirus");

    // Создание текста для кнопки выбора файла
    sf::Font font;
    if (!font.loadFromFile("arial.ttf")) {
        std::cerr << "Ошибка загрузки шрифта" << std::endl;
        return 1;
    }

    // Создание кнопки для scan
    sf::RectangleShape ScanButton(sf::Vector2f(200.f, 50.f));
    ScanButton.setFillColor(sf::Color::Blue);
    ScanButton.setPosition(300.f, 150.f);

    sf::Text ScanButtonText("Scan", font, 24);
    ScanButtonText.setPosition(310.f, 160.f);

    // Создание кнопки для report
    sf::RectangleShape ReportButton(sf::Vector2f(200.f, 50.f));
    ReportButton.setFillColor(sf::Color::Red);
    ReportButton.setPosition(300.f, 300.f);

    sf::Text ReportButtonText("Report", font, 24);
    ReportButtonText.setPosition(310.f, 310.f);


    // Главный цикл приложения
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            // Обработка нажатия на кнопку выбора файла
            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                    sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
                    if (ScanButton.getGlobalBounds().contains(mousePosF)) {
                        std::cout << "Scan Button was pressed" << std::endl;

                        Signature testSignature("/home/vboxuser/TEST_FILESYSTEM/Directory/FILE1.py");
                        ClearBase("AVBase.txt");
                        testSignature.WriteToBase("AVBase.txt");
                        AVBase Base("AVBase.txt");
                        Base.Print();
                        ScanDirectory("/home/vboxuser/TEST_FILESYSTEM", Base);
                    }
                    if (ReportButton.getGlobalBounds().contains(mousePosF)) {
                        std::cout << "Report Button was pressed" << std::endl;
                        sf::RenderWindow app(sf::VideoMode(800, 600), L"SFML window");
                        sf::Text txt ;
                        txt.setPosition ( 50 , 50 ) ;
                        txt.setFont ( font ) ;
                        txt.setString ( L"" ) ;
                        int x = 0 ;
                        TextBox tb ( txt ) ;
                        fc.setFocusObject( &tb ) ;
                        while (app.isOpen())
                        {
                            sf::Event event;
                            while (app.pollEvent(event))
                            {
                                // Close window : exit
                                if (event.type == sf::Event::Closed)
                                    app.close();
                                if ( event.type == sf::Event::MouseButtonPressed )
                                {
                                    //Меняем фокус на нужный объект
                                }
                                FocusObject * fo = fc.getFocusObject() ;
                                if ( fo!= 0 )
                                {
                                    fo->event ( event ) ;
                                }
                            }
                            app.clear();
                            app.draw ( tb ) ;
                            app.display();
                        }

                    }
                }
            }


        }

        window.clear();
        window.draw(ScanButton);
        window.draw(ScanButtonText);
        window.draw(ReportButton);
        window.draw(ReportButtonText);
        window.display();
    }

    return 0;
}