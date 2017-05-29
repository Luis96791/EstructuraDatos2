#ifndef IMAAGE_H
#define IMAAGE_H
#include <stdlib.h>
#include <stdio.h>
#include <SFML/Graphics.hpp>

class Imaage
{
    public:
        sf::Texture texture;
        sf::Sprite sprite;
        Imaage* siguiente = NULL;
        Imaage();
        void imageChargeFile(char* data);
        void imageSetPosition(int x, int y);
        int imageGetPositionX();
        int imageGetPositionY();
        virtual ~Imaage();

    protected:

    private:
};

#endif // IMAAGE_H
