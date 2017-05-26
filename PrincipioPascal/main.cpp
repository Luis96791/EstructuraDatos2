#include <iostream>
#include <SFML/Graphics.hpp>
#include "Imaage.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1200, 600), "Torres de Hanoi");
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
    }

    return 0;
}
