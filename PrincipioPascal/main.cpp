#include <iostream>
#include "Simulador.h"
#include <SFML/Graphics.hpp>
#include "Imaage.h"
#include "ImageList.h"

int main()
{
    system("color A");

    Imaage* background = new Imaage();
    background->imageChargeFile("background.png");
    background->imageSetPosition(0, -40);

    Imaage* torre1 = new Imaage();
    torre1->imageChargeFile("torre.png");
    torre1->imageSetPosition(148, 286);

    Imaage* torre2 = new Imaage();
    torre2->imageChargeFile("torre.png");
    torre2->imageSetPosition(448, 286);

    Imaage* torre3 = new Imaage();
    torre3->imageChargeFile("torre.png");
    torre3->imageSetPosition(748, 286);

    Imaage* disco1 = new Imaage();
    disco1->imageChargeFile("discos/disco1.png");
    disco1->imageSetPosition(150, 450);

    Imaage* disco2 = new Imaage();
    disco2->imageChargeFile("discos/disco2.png");
    disco2->imageSetPosition(170, 420);

    Imaage* disco3 = new Imaage();
    disco3->imageChargeFile("discos/disco3.png");
    disco3->imageSetPosition(190, 390);

    Imaage* disco4 = new Imaage();
    disco4->imageChargeFile("discos/disco4.png");
    disco4->imageSetPosition(210, 360);

    Imaage* disco5 = new Imaage();
    disco5->imageChargeFile("discos/disco5.png");
    disco5->imageSetPosition(230, 330);

    Imaage* disco6 = new Imaage();
    disco6->imageChargeFile("discos/disco6.png");
    disco6->imageSetPosition(250, 300);

    ImageList* imageList = new ImageList();
    imageList->addImage(background);
    imageList->addImage(torre1); //1
    imageList->addImage(torre2); //2
    imageList->addImage(torre3); //3
    imageList->addImage(disco1); //4
    imageList->addImage(disco2); //5
    imageList->addImage(disco3); //6
    imageList->addImage(disco4); //7
//    imageList->addImage(disco5); //8
//    imageList->addImage(disco6); //9

    Simulador* simulador = new Simulador(1200, 600, "Torres de Hanoi", imageList);

/*******************************************************************************************/
/*******************************************************************************************/
/*******************************************************************************************/


/*******************************************************************************************/
/*******************************************************************************************/
/*******************************************************************************************/



  /**  sf::RenderWindow window(sf::VideoMode(1200, 600), "Torres de Hanoi");
    sf::RectangleShape rectangle1, rectangle2, rectangle3;

    bool animaciones[7] = {1,1,1,1,1,1,1};

    rectangle1.setSize(sf::Vector2f(220, 30));
    rectangle1.setFillColor(sf::Color::Red);
    rectangle1.setPosition(170, 416);

    rectangle2.setSize(sf::Vector2f(180, 30));
    rectangle2.setFillColor(sf::Color::Blue);
    rectangle2.setPosition(190, 386);

    rectangle3.setSize(sf::Vector2f(140, 30));
    rectangle3.setFillColor(sf::Color::Yellow);
    rectangle3.setPosition(210, 356);


    sf::Texture texture, t_torre;
    sf::Sprite sprite, s_torre1, s_torre2, s_torre3;

    texture.loadFromFile("background.png"); sprite.setTexture(texture); sprite.setPosition(0,-50);
    t_torre.loadFromFile("torre.png"); s_torre1.setTexture(t_torre); s_torre1.setPosition(150,180);
    s_torre2.setTexture(t_torre); s_torre2.setPosition(450,180);
    s_torre3.setTexture(t_torre); s_torre3.setPosition(750,180);

    while (window.isOpen())
    {
//        sf::Event event;
//        while (window.pollEvent(event))
//        {
//            if (event.type == sf::Event::Closed)
//                window.close();
//        }

        if(animaciones[0])
        {
            if(rectangle3.getPosition().y > 120 && rectangle3.getPosition().x == 210)
                rectangle3.move(0, -1);
            if(rectangle3.getPosition().y == 120 && rectangle3.getPosition().x < 810)
                rectangle3.move(1, 0);
            if(rectangle3.getPosition().x == 810 && rectangle3.getPosition().y < 416)
                rectangle3.move(0, 1);
            if(rectangle3.getPosition().x == 810 && rectangle3.getPosition().y == 416)
                animaciones[0] = false;
        }

        if(!animaciones[0]&& animaciones[1])
        {
            if(rectangle2.getPosition().y > 120 && rectangle2.getPosition().x == 190)
                rectangle2.move(0, -1);
            if(rectangle2.getPosition().y == 120 && rectangle2.getPosition().x < 490)
                rectangle2.move(1, 0);
            if(rectangle2.getPosition().x == 490 && rectangle2.getPosition().y < 416)
                rectangle2.move(0, 1);
            if(rectangle2.getPosition().x == 490 && rectangle2.getPosition().y == 416)
                animaciones[1] = false;
        }

        if(!animaciones[1] && animaciones[2])
        {
            if(rectangle3.getPosition().y > 120 && rectangle3.getPosition().x == 810)
                rectangle3.move(0, -1);
            if(rectangle3.getPosition().y == 120 && rectangle3.getPosition().x > 510)
                rectangle3.move(-1, 0);
            if(rectangle3.getPosition().x == 510 && rectangle3.getPosition().y < 386)
                rectangle3.move(0, 1);
            if(rectangle3.getPosition().x == 510 && rectangle3.getPosition().y == 386)
                animaciones[2] = false;
        }

        if(!animaciones[2] && animaciones[3])
        {
            if(rectangle1.getPosition().y > 120 && rectangle1.getPosition().x == 170)
                rectangle1.move(0, -1);
            if(rectangle1.getPosition().y == 120 && rectangle1.getPosition().x < 770)
                rectangle1.move(1, 0);
            if(rectangle1.getPosition().x == 770 && rectangle1.getPosition().y < 416)
                rectangle1.move(0, 1);
            if(rectangle1.getPosition().x == 770 && rectangle1.getPosition().y == 416)
                animaciones[3] = false;
        }

        if(!animaciones[3] && animaciones[4])
        {
            if(rectangle3.getPosition().y > 120 && rectangle3.getPosition().x == 510)
                rectangle3.move(0, -1);
            if(rectangle3.getPosition().y == 120 && rectangle3.getPosition().x > 210)
                rectangle3.move(-1, 0);
            if(rectangle3.getPosition().x == 210 && rectangle3.getPosition().y < 416)
                rectangle3.move(0, 1);
            if(rectangle3.getPosition().x == 210 && rectangle3.getPosition().y == 416)
                animaciones[4] = false;
        }

        if(!animaciones[4] && animaciones[5])
        {
            if(rectangle2.getPosition().y > 120 && rectangle2.getPosition().x == 490)
                rectangle2.move(0, -1);
            if(rectangle2.getPosition().y == 120 && rectangle2.getPosition().x < 790)
                rectangle2.move(1, 0);
            if(rectangle2.getPosition().x == 790 && rectangle2.getPosition().y < 386)
                rectangle2.move(0, 1);
            if(rectangle2.getPosition().x == 790 && rectangle2.getPosition().y == 386)
                animaciones[5] = false;
        }

        if(!animaciones[5] && animaciones[6])
        {
            if(rectangle3.getPosition().y > 120 && rectangle3.getPosition().x == 210)
                rectangle3.move(0, -1);
            if(rectangle3.getPosition().y == 120 && rectangle3.getPosition().x < 810)
                rectangle3.move(1, 0);
            if(rectangle3.getPosition().x ==810 && rectangle3.getPosition().y < 356)
                rectangle3.move(0, 1);
            if(rectangle3.getPosition().x ==810 && rectangle3.getPosition().y == 356){
                animaciones[6] = false;
                window.close();}
            printf("X %f Y %f \n", rectangle3.getPosition().x, rectangle3.getPosition().y);
        }


        window.draw(sprite);
        window.draw(s_torre1);
        window.draw(s_torre2);
        window.draw(s_torre3);
        window.draw(rectangle1);
        window.draw(rectangle2);
        window.draw(rectangle3);
        window.display();
    }**/

    return 0;
}
