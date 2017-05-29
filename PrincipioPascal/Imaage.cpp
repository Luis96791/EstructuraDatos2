#include "Imaage.h"

Imaage::Imaage()
{
    //ctor
}

void Imaage::imageChargeFile(char* data)
{
    this->texture.loadFromFile(data);
    this->sprite.setTexture(this->texture);
}

void Imaage::imageSetPosition(int x, int y)
{
    this->sprite.setPosition(x, y);
}

int Imaage::imageGetPositionX()
{
    return this->sprite.getPosition().x;
}

int Imaage::imageGetPositionY()
{
    return this->sprite.getPosition().y;
}

Imaage::~Imaage()
{
    //dtor
}
