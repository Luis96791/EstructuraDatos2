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

    if(simulaciones[0])
    {
        if(image1->imageGetPositionY() > 200 && image1->imageGetPositionX() == 190)
            image1->sprite.move(0, -velocity);
        if(image1->imageGetPositionY() == 200 && image1->imageGetPositionX() < 790)
            image1->sprite.move(velocity, 0);
        if(image1->imageGetPositionX() == 790 && image1->imageGetPositionY() < 450)
            image1->sprite.move(0, velocity);
        if(image1->imageGetPositionX() == 790 && image1->imageGetPositionY() == 450)
            simulaciones[0] = false;
    }

    if(!simulaciones[0] && simulaciones[1])
    {
        if(image2->imageGetPositionY() > 200 && image2->imageGetPositionX() == 170)
            image2->sprite.move(0, -velocity);
        if(image2->imageGetPositionY() == 200 && image2->imageGetPositionX() < 470)
            image2->sprite.move(velocity, 0);
        if(image2->imageGetPositionX() == 470 && image2->imageGetPositionY() < 450)
            image2->sprite.move(0, velocity);
        if(image2->imageGetPositionX() == 470 && image2->imageGetPositionY() == 450)
            simulaciones[1] = false;
    }

    if(!simulaciones[1] && simulaciones[2])
    {
        if(image1->imageGetPositionY() > 200 && image1->imageGetPositionX() == 790)
            image1->sprite.move(0, -velocity);
        if(image1->imageGetPositionY() == 200 && image1->imageGetPositionX() > 490)
            image1->sprite.move(-velocity, 0);
        if(image1->imageGetPositionX() == 490 && image1->imageGetPositionY() < 420)
            image1->sprite.move(0, velocity);
        if(image1->imageGetPositionX() == 490 && image1->imageGetPositionY() == 420)
            simulaciones[2] = false;
    }

    if(!simulaciones[2] && simulaciones[3])
    {
        if(image3->imageGetPositionY() > 200 && image3->imageGetPositionX() == 150)
            image3->sprite.move(0, -velocity);
        if(image3->imageGetPositionY() == 200 && image3->imageGetPositionX() < 750)
            image3->sprite.move(velocity, 0);
        if(image3->imageGetPositionX() == 750 && image3->imageGetPositionY() < 450)
            image3->sprite.move(0, velocity);
        if(image3->imageGetPositionX() == 750 && image3->imageGetPositionY() == 450)
            simulaciones[3] = false;
    }

    if(!simulaciones[3] && simulaciones[4])
    {
        if(image1->imageGetPositionY() > 200 && image1->imageGetPositionX() == 490)
            image1->sprite.move(0, -velocity);
        if(image1->imageGetPositionY() == 200 && image1->imageGetPositionX() > 190)
            image1->sprite.move(-velocity, 0);
        if(image1->imageGetPositionX() == 190 && image1->imageGetPositionY() < 450)
            image1->sprite.move(0, velocity);
        if(image1->imageGetPositionX() == 190 && image1->imageGetPositionY() == 450)
            simulaciones[4] = false;
    }

    if(!simulaciones[4] && simulaciones[5])
    {
        if(image2->imageGetPositionY() > 200 && image2->imageGetPositionX() == 470)
            image2->sprite.move(0, -velocity);
        if(image2->imageGetPositionY() == 200 && image2->imageGetPositionX() < 770)
            image2->sprite.move(velocity, 0);
        if(image2->imageGetPositionX() == 770 && image2->imageGetPositionY() < 420)
            image2->sprite.move(0, velocity);
        if(image2->imageGetPositionX() == 770 && image2->imageGetPositionY() == 420)
            simulaciones[5] = false;
    }

    if(!simulaciones[5] && simulaciones[6])
    {
        printf("X: %d, Y: %d \n", image1->imageGetPositionX(), image1->imageGetPositionY());
        if(image1->imageGetPositionY() > 200 && image1->imageGetPositionX() == 190)
            image1->sprite.move(0, -velocity);
        if(image1->imageGetPositionY() == 200 && image1->imageGetPositionX() < 790)
            image1->sprite.move(velocity, 0);
        if(image1->imageGetPositionX() == 790 && image1->imageGetPositionY() < 390)
            image1->sprite.move(0, velocity);
        if(image1->imageGetPositionX() == 790 && image1->imageGetPositionY() == 390)
            simulaciones[6] = false;
    }
}

void Simulador::simulacion4(float velocity, ImageList* imageList)
{
    Imaage* image1 = imageList->getImageInPosition(7);
    Imaage* image2 = imageList->getImageInPosition(6);
    Imaage* image3 = imageList->getImageInPosition(5);
    Imaage* image4 = imageList->getImageInPosition(4);
}

Simulador::~Simulador()
{
    //dtor
}
