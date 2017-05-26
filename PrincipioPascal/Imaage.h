#ifndef IMAAGE_H
#define IMAAGE_H
#include <stdlib.h>
#include <stdio.h>
#include <SFML/Graphics.hpp>

class Imaage
{
    public:
        sf::Sprite sprite;
        Imaage();
        sf::Sprite new_image(sf::Texture texture, sf::Sprite sprite, char* data);
        virtual ~Imaage();

    protected:

    private:
};

#endif // IMAAGE_H
