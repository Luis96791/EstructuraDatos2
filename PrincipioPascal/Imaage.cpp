#include "Imaage.h"

Imaage::Imaage()
{
    //ctor
}

sf::Sprite Imaage::new_image(sf::Texture texture, sf::Sprite sprite, char* data)
{
    if(!texture.loadFromFile(data))
        printf("No existe!");
    sprite.setTexture(texture);

    this->sprite = sprite;

    return sprite;
}

Imaage::~Imaage()
{
    //dtor
}
