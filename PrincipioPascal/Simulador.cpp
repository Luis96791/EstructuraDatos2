#include "Simulador.h"

Simulador::Simulador(int WIDTH, int HEIGHT, char* title, ImageList* imageList)
{
    this->window.create(sf::VideoMode(WIDTH, HEIGHT), title, sf::Style::Default);

    while(this->window.isOpen())
    {
        sf::Event event;
        while(this->window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
                this->window.close();
        }

//        simulacion3(2, imageList);
        simulacion4(2, imageList);

        drawImages(imageList);
        window.display();
    }
}

void Simulador::drawImages(ImageList* imageList)
{
    for(int x = 0; x < imageList->sizeImageList(); x++)
    {
        window.draw(imageList->getImageInPosition(x)->sprite);
    }
}

void Simulador::setSimulaciones()
{
    //cambiar el 16 por otro numero
    for(int x = 0; x < 16; x++)
    {
        simulaciones[x] = true;
    }
}

void Simulador::simulacion3(float velocity, ImageList* imageList)
{
    Imaage* image1 = imageList->getImageInPosition(6);
    Imaage* image2 = imageList->getImageInPosition(5);
    Imaage* image3 = imageList->getImageInPosition(4);

    if(simulaciones[0] && flag)
        moves1(image1, 190, 790, 200, 450, 0, velocity);

    if(!simulaciones[0] && simulaciones[1])
        moves1(image2, 170, 470, 200, 450, 1, velocity);

    if(!simulaciones[1] && simulaciones[2])
        moves2(image1, 790, 490, 200, 420, 2, velocity);

    if(!simulaciones[2] && simulaciones[3])
        moves1(image3, 150, 750, 200, 450, 3, velocity);

    if(!simulaciones[3] && simulaciones[4])
        moves2(image1, 490, 190, 200, 450, 4, velocity);

    if(!simulaciones[4] && simulaciones[5])
        moves1(image2, 470, 770, 200, 420, 5, velocity);

    if(!simulaciones[5])
    {
        moves1(image1, 190, 790, 200, 390, 6, velocity);

        if(image1->imageGetPositionX() == 790 && image1->imageGetPositionY() == 390)
        {
            setSimulaciones();
            flag = false; //flag se cambia a true fuera de esta funcion
        }
    }
}

void Simulador::simulacion4(float velocity, ImageList* imageList)
{
    Imaage* image1 = imageList->getImageInPosition(7);
    Imaage* image2 = imageList->getImageInPosition(6);
    Imaage* image3 = imageList->getImageInPosition(5);
    Imaage* image4 = imageList->getImageInPosition(4);

    if(simulaciones[0] && flag)
        moves1(image1, 210, 510, 200, 450, 0, velocity);

    if(!simulaciones[0] && simulaciones[1])
        moves1(image2, 190, 790, 200, 450, 1, velocity);

    if(!simulaciones[1] && simulaciones[2])
        moves1(image1, 510, 810, 200, 420, 2, velocity);

    if(!simulaciones[2] && simulaciones[3])
        moves1(image3, 170, 470, 200, 450, 3, velocity);

    if(!simulaciones[3] && simulaciones[4])
        moves2(image1, 810, 210, 200, 420, 4, velocity);

    if(!simulaciones[4] && simulaciones[5])
        moves2(image2, 790, 490, 200, 420, 5, velocity);

    if(!simulaciones[5] && simulaciones[6])
        moves1(image1, 210, 510, 200, 390, 6, velocity);
}

void Simulador::moves1(Imaage* image, int x1, int x2, int y1, int y2, int index, float velocity)
{
    if(image->imageGetPositionY() > y1 && image->imageGetPositionX() == x1)
        image->sprite.move(0, -velocity);
    if(image->imageGetPositionY() == y1 && image->imageGetPositionX() < x2)
        image->sprite.move(velocity, 0);
    if(image->imageGetPositionX() == x2 && image->imageGetPositionY() < y2)
        image->sprite.move(0, velocity);
    if(image->imageGetPositionX() == x2 && image->imageGetPositionY() == y2)
        simulaciones[index] = false;
}

void Simulador::moves2(Imaage* image, int x1, int x2, int y1, int y2, int index, float velocity)
{
    if(image->imageGetPositionY() > y1 && image->imageGetPositionX() == x1)
        image->sprite.move(0, -velocity);
    if(image->imageGetPositionY() == y1 && image->imageGetPositionX() > x2)
        image->sprite.move(-velocity, 0);
    if(image->imageGetPositionX() == x2 && image->imageGetPositionY() < y2)
        image->sprite.move(0, velocity);
    if(image->imageGetPositionX() == x2 && image->imageGetPositionY() == y2)
        simulaciones[index] = false;
}

Simulador::~Simulador()
{
    //dtor
}
