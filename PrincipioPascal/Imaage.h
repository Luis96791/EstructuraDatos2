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
        bool visible;
        Imaage* siguiente = NULL;
        Imaage();
        void imageChargeFile(char* data);
        void imageSetPosition(int x, int y);
        int imageGetPositionX();
        int imageGetPositionY();
        void setVisible(bool visible);
        virtual ~Imaage();

    protected:

    private:
};

#endif // IMAAGE_H
