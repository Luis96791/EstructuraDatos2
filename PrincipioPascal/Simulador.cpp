#include "Simulador.h"

Simulador::Simulador(int WIDTH, int HEIGHT, char* title, ImageList* imageList)
{
    this->window.create(sf::VideoMode(WIDTH, HEIGHT), title, sf::Style::Default);
    chargeFonts();

    while(this->window.isOpen())
    {
        this->mouse = this->window.mapPixelToCoords(sf::Mouse::getPosition(this->window));

        sf::Event event;
        while(this->window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed ||
               clickSprite(imageList->getImageInPosition(26)->sprite))
                this->window.close();

            startSimulations(imageList);
            clickEventsDiscs(imageList);
            clicksEventsVelocity(imageList);
            resetSimulations(imageList);
        }

        setDiscs(imageList);

        if(empezar && discos == 3)
            simulacion3(imageList);

        if(empezar && discos == 4)
            simulacion4(imageList);

        if(empezar && discos == 5)
            simulacion5(imageList);

        if(empezar && discos == 6)
            simulacion6(imageList);


        drawImages(imageList);
        window.draw(text_velocidad);
        window.draw(text_movs);
        window.draw(text_discs);
        window.display();
    }
}

void Simulador::drawImages(ImageList* imageList)
{
    for(int x = 0; x < imageList->sizeImageList(); x++)
    {
        if(imageList->getImageInPosition(x)->visible)
            window.draw(imageList->getImageInPosition(x)->sprite);
    }
}

void Simulador::setSimulaciones()
{
    for(int x = 0; x < 64; x++)
    {
        if(!simulaciones[x])
            simulaciones[x] = true;
    }
}

void Simulador::simulacion3(ImageList* imageList)
{
    Imaage* image1 = imageList->getImageInPosition(17);
    Imaage* image2 = imageList->getImageInPosition(16);
    Imaage* image3 = imageList->getImageInPosition(15);

    if(simulaciones[0] && flag)
        moves1(image1, 190, 790, 200, 450, 0);

    if(!simulaciones[0] && simulaciones[1])
        moves1(image2, 170, 470, 200, 450, 1);

    if(!simulaciones[1] && simulaciones[2])
        moves2(image1, 790, 490, 200, 420, 2);

    if(!simulaciones[2] && simulaciones[3])
        moves1(image3, 150, 750, 200, 450, 3);

    if(!simulaciones[3] && simulaciones[4])
        moves2(image1, 490, 190, 200, 450, 4);

    if(!simulaciones[4] && simulaciones[5])
        moves1(image2, 470, 770, 200, 420, 5);

    if(!simulaciones[5])
    {
        moves1(image1, 190, 790, 200, 390, 6);

        if(image1->imageGetPositionX() == 790 && image1->imageGetPositionY() == 390)
        {
            setSimulaciones();
            flag = false;
        }
    }
}

void Simulador::simulacion4(ImageList* imageList)
{
    Imaage* image1 = imageList->getImageInPosition(18);
    Imaage* image2 = imageList->getImageInPosition(17);
    Imaage* image3 = imageList->getImageInPosition(16);
    Imaage* image4 = imageList->getImageInPosition(15);

    if(simulaciones[0] && flag)
        moves1(image1, 210, 510, 200, 450, 0);

    if(!simulaciones[0] && simulaciones[1])
        moves1(image2, 190, 790, 200, 450, 1);

    if(!simulaciones[1] && simulaciones[2])
        moves1(image1, 510, 810, 200, 420, 2);

    if(!simulaciones[2] && simulaciones[3])
        moves1(image3, 170, 470, 200, 450, 3);

    if(!simulaciones[3] && simulaciones[4])
        moves2(image1, 810, 210, 200, 420, 4);

    if(!simulaciones[4] && simulaciones[5])
        moves2(image2, 790, 490, 200, 420, 5);

    if(!simulaciones[5] && simulaciones[6])
        moves1(image1, 210, 510, 200, 390, 6);

    if(!simulaciones[6] && simulaciones[7])
        moves1(image4, 150, 750, 200, 450, 7);

    if(!simulaciones[7] && simulaciones[8])
        moves1(image1, 510, 810, 200, 420, 8);

    if(!simulaciones[8] && simulaciones[9])
        moves2(image2, 490, 190, 200, 450, 9);

    if(!simulaciones[9] && simulaciones[10])
        moves2(image1, 810, 210, 200, 420, 10);

    if(!simulaciones[10] && simulaciones[11])
        moves1(image3, 470, 770, 200, 420, 11);

    if(!simulaciones[11] && simulaciones[12])
        moves1(image1, 210, 510, 200, 450, 12);

    if(!simulaciones[12] && simulaciones[13])
        moves1(image2, 190, 790, 200, 390, 13);

    if(!simulaciones[13])
    {
        moves1(image1, 510, 810, 200, 360, 14);
        if(image1->imageGetPositionX() == 810 && image1->imageGetPositionY() == 360)
        {
            setSimulaciones();
            flag = false; //flag se cambia a true fuera de esta funcion
        }
    }
}

void Simulador::simulacion5(ImageList* imageList)
{
    Imaage* image1 = imageList->getImageInPosition(19);
    Imaage* image2 = imageList->getImageInPosition(18);
    Imaage* image3 = imageList->getImageInPosition(17);
    Imaage* image4 = imageList->getImageInPosition(16);
    Imaage* image5 = imageList->getImageInPosition(15);

    if(simulaciones[0] && flag)
        moves1(image1, 230, 830, 200, 450, 0);

    if(!simulaciones[0] && simulaciones[1])
        moves1(image2, 210, 510, 200, 450, 1);

    if(!simulaciones[1] && simulaciones[2])
        moves2(image1, 830, 530, 200, 420, 2);

    if(!simulaciones[2] && simulaciones[3])
        moves1(image3, 190, 790, 200, 450, 3);

    if(!simulaciones[3] && simulaciones[4])
        moves2(image1, 530, 230, 200, 390, 4);

    if(!simulaciones[4] && simulaciones[5])
        moves1(image2, 510, 810, 200, 420, 5);

    if(!simulaciones[5] && simulaciones[6])
        moves1(image1, 230, 830, 200, 390, 6);

    if(!simulaciones[6] && simulaciones[7])
        moves1(image4, 170, 470, 200, 450, 7);

    if(!simulaciones[7] && simulaciones[8])
        moves2(image1, 830, 530, 200, 420, 8);

    if(!simulaciones[8] && simulaciones[9])
        moves2(image2, 810, 210, 200, 420, 9);

    if(!simulaciones[9] && simulaciones[10])
        moves2(image1, 530, 230, 200, 390, 10);

    if(!simulaciones[10] && simulaciones[11])
        moves2(image3, 790, 490, 200, 420, 11);

    if(!simulaciones[11] && simulaciones[12])
        moves1(image1, 230, 830, 200, 450, 12);

    if(!simulaciones[12] && simulaciones[13])
        moves1(image2, 210, 510, 200, 390, 13);

    if(!simulaciones[13] && simulaciones[14])
        moves2(image1, 830, 530, 200, 360, 14);

    if(!simulaciones[14] && simulaciones[15])
        moves1(image5, 150, 750, 200, 450, 15);

    if(!simulaciones[15] && simulaciones[16])
        moves2(image1, 530, 230, 200, 450, 16);

    if(!simulaciones[16] && simulaciones[17])
        moves1(image2, 510, 810, 200, 420, 17);

    if(!simulaciones[17] && simulaciones[18])
        moves1(image1, 230, 830, 200, 390, 18);

    if(!simulaciones[18] && simulaciones[19])
        moves2(image3, 490, 190, 200, 450, 19);

    if(!simulaciones[19] && simulaciones[20])
        moves2(image1, 830, 530, 200, 420, 20);

    if(!simulaciones[20] && simulaciones[21])
        moves2(image2, 810, 210, 200, 420, 21);

    if(!simulaciones[21] && simulaciones[22])
        moves2(image1, 530, 230, 200, 390, 22);

    if(!simulaciones[22] && simulaciones[23])
        moves1(image4, 470, 770, 200, 420, 23);

    if(!simulaciones[23] && simulaciones[24])
        moves1(image1, 230, 830, 200, 390, 24);

    if(!simulaciones[24] && simulaciones[25])
        moves1(image2, 210, 510, 200, 450, 25);

    if(!simulaciones[25] && simulaciones[26])
        moves2(image1, 830, 530, 200, 420, 26);

    if(!simulaciones[26] && simulaciones[27])
        moves1(image3, 190, 790, 200, 390, 27);

    if(!simulaciones[27] && simulaciones[28])
        moves2(image1, 530, 230, 200, 450, 28);

    if(!simulaciones[28] && simulaciones[29])
        moves1(image2, 510, 810, 200, 360, 29);

    if(!simulaciones[29])
    {
        moves1(image1, 230, 830, 200, 330, 30);
        if(image1->imageGetPositionX() == 830 && image1->imageGetPositionY() == 330)
        {
            setSimulaciones();
            flag = false; //flag se cambia a true fuera de esta funcion
        }
    }
}

void Simulador::simulacion6(ImageList* imageList)
{
    Imaage* image1 = imageList->getImageInPosition(20);
    Imaage* image2 = imageList->getImageInPosition(19);
    Imaage* image3 = imageList->getImageInPosition(18);
    Imaage* image4 = imageList->getImageInPosition(17);
    Imaage* image5 = imageList->getImageInPosition(16);
    Imaage* image6 = imageList->getImageInPosition(15);

    if(simulaciones[0] && flag)
        moves1(image1, 250, 550, 200, 450, 0);

    if(!simulaciones[0] && simulaciones[1])
        moves1(image2, 230, 830, 200, 450, 1);

    if(!simulaciones[1] && simulaciones[2])
        moves1(image1, 550, 850, 200, 420, 2);

    if(!simulaciones[2] && simulaciones[3])
        moves1(image3, 210, 510, 200, 450, 3);

    if(!simulaciones[3] && simulaciones[4])
        moves2(image1, 850, 250, 200, 360, 4);

    if(!simulaciones[4] && simulaciones[5])
        moves2(image2, 830, 530, 200, 420, 5);

    if(!simulaciones[5] && simulaciones[6])
        moves1(image1, 250, 550, 200, 390, 6);

    if(!simulaciones[6] && simulaciones[7])
        moves1(image4, 190, 790, 200, 450, 7);

    if(!simulaciones[7] && simulaciones[8])
        moves1(image1, 550, 850, 200, 420, 8);

    if(!simulaciones[8] && simulaciones[9])
        moves2(image2, 530, 230, 200, 390, 9);

    if(!simulaciones[9] && simulaciones[10])
        moves2(image1, 850, 250, 200, 360, 10);

    if(!simulaciones[10] && simulaciones[11])
        moves1(image3, 510, 810, 200, 420, 11);

    if(!simulaciones[11] && simulaciones[12])
        moves1(image1, 250, 550, 200, 450, 12);

    if(!simulaciones[12] && simulaciones[13])
        moves1(image2, 230, 830, 200, 390, 13);

    if(!simulaciones[13] && simulaciones[14])
        moves1(image1, 550, 850, 200, 360, 14);

    if(!simulaciones[14] && simulaciones[15])
        moves1(image5, 170, 470, 200, 450, 15);

    if(!simulaciones[15] && simulaciones[16])
        moves2(image1, 850, 250, 200, 420, 16);

    if(!simulaciones[16] && simulaciones[17])
        moves2(image2, 830, 530, 200, 420, 17);

    if(!simulaciones[17] && simulaciones[18])
        moves1(image1, 250, 550, 200, 390, 18);

    if(!simulaciones[18] && simulaciones[19])
        moves2(image3, 810, 210, 200, 420, 19);

    if(!simulaciones[19] && simulaciones[20])
        moves1(image1, 550, 850, 200, 420, 20);

    if(!simulaciones[20] && simulaciones[21])
        moves2(image2, 530, 230, 200, 390, 21);

    if(!simulaciones[21] && simulaciones[22])
        moves2(image1, 850, 250, 200, 360, 22);

    if(!simulaciones[22] && simulaciones[23])
        moves2(image4, 790, 490, 200, 420, 23);

    if(!simulaciones[23] && simulaciones[24])
        moves1(image1, 250, 550, 200, 390, 24);

    if(!simulaciones[24] && simulaciones[25])
        moves1(image2, 230, 830, 200, 450, 25);

    if(!simulaciones[25] && simulaciones[26])
        moves1(image1, 550, 850, 200, 420, 26);

    if(!simulaciones[26] && simulaciones[27])
        moves1(image3, 210, 510, 200, 390, 27);

    if(!simulaciones[27] && simulaciones[28])
        moves2(image1, 850, 250, 200, 420, 28);

    if(!simulaciones[28] && simulaciones[29])
        moves2(image2, 830, 530, 200, 360, 29);

    if(!simulaciones[29] && simulaciones[30])
        moves1(image1, 250, 550, 200, 330, 30);

    if(!simulaciones[30] && simulaciones[31])
        moves1(image6, 150, 750, 200, 450, 31);

    if(!simulaciones[31] && simulaciones[32])
        moves1(image1, 550, 850, 200, 420, 32);

    if(!simulaciones[32] && simulaciones[33])
        moves2(image2, 530, 230, 200, 450, 33);

    if(!simulaciones[33] && simulaciones[34])
        moves2(image1, 850, 250, 200, 420, 34);

    if(!simulaciones[34] && simulaciones[35])
        moves1(image3, 510, 810, 200, 420, 35);

    if(!simulaciones[35] && simulaciones[36])
        moves1(image1, 250, 550, 200, 390, 36);

    if(!simulaciones[36] && simulaciones[37])
        moves1(image2, 230, 830, 200, 390, 37);

    if(!simulaciones[37] && simulaciones[38])
        moves1(image1, 550, 850, 200, 360, 38);

    if(!simulaciones[38] && simulaciones[39])
        moves2(image4, 490, 190, 200, 450, 39);

    if(!simulaciones[39] && simulaciones[40])
        moves2(image1, 850, 250, 200, 420, 40);

    if(!simulaciones[40] && simulaciones[41])
        moves2(image2, 830, 530, 200, 420, 41);

    if(!simulaciones[41] && simulaciones[42])
        moves1(image1, 250, 550, 200, 390, 42);

    if(!simulaciones[42] && simulaciones[43])
        moves2(image3, 810, 210, 200, 420, 43);

    if(!simulaciones[43] && simulaciones[44])
        moves1(image1, 550, 850, 200, 420, 44);

    if(!simulaciones[44] && simulaciones[45])
        moves2(image2, 530, 230, 200, 390, 45);

    if(!simulaciones[45] && simulaciones[46])
        moves2(image1, 850, 250, 200, 360, 46);

    if(!simulaciones[46] && simulaciones[47])
        moves1(image5, 470, 770, 200, 420, 47);

    if(!simulaciones[47] && simulaciones[48])
        moves1(image1, 250, 550, 200, 450, 48);

    if(!simulaciones[48] && simulaciones[49])
        moves1(image2, 230, 830, 200, 390, 49);

    if(!simulaciones[49] && simulaciones[50])
        moves1(image1, 550, 850, 200, 360, 50);

    if(!simulaciones[50] && simulaciones[51])
        moves1(image3, 210, 510, 200, 450, 51);

    if(!simulaciones[51] && simulaciones[52])
        moves2(image1, 850, 250, 200, 420, 52);

    if(!simulaciones[52] && simulaciones[53])
        moves2(image2, 830, 530, 200, 420, 53);

    if(!simulaciones[53] && simulaciones[54])
        moves1(image1, 250, 550, 200, 390, 54);

    if(!simulaciones[54] && simulaciones[55])
        moves1(image4, 190, 790, 200, 390, 55);

    if(!simulaciones[55] && simulaciones[56])
        moves1(image1, 550, 850, 200, 360, 56);

    if(!simulaciones[56] && simulaciones[57])
        moves2(image2, 530, 230, 200, 450, 57);

    if(!simulaciones[57] && simulaciones[58])
        moves2(image1, 850, 250, 200, 420, 58);

    if(!simulaciones[58] && simulaciones[59])
        moves1(image3, 510, 810, 200, 360, 59);

    if(!simulaciones[59] && simulaciones[60])
        moves1(image1, 250, 550, 200, 450, 60);

    if(!simulaciones[60] && simulaciones[61])
        moves1(image2, 230, 830, 200, 330, 61);

    if(!simulaciones[61])
    {
        moves1(image1, 550, 850, 200, 300, 62);

        if(image1->imageGetPositionX() == 850 && image1->imageGetPositionY() == 300)
        {
            setSimulaciones();
            flag = false;
        }
    }
}

void Simulador::moves1(Imaage* image, int x1, int x2, int y1, int y2, int index)
{
    if(image->imageGetPositionY() > y1 && image->imageGetPositionX() == x1)
        image->sprite.move(0, -velocity);
    if(image->imageGetPositionY() == y1 && image->imageGetPositionX() < x2)
        image->sprite.move(velocity, 0);
    if(image->imageGetPositionX() == x2 && image->imageGetPositionY() < y2)
        image->sprite.move(0, velocity);
    if(image->imageGetPositionX() == x2 && image->imageGetPositionY() == y2)
    {
        simulaciones[index] = false;
        movimientos = movimientos+1;
        text_movs.setString(toString(movimientos));
    }
}

void Simulador::moves2(Imaage* image, int x1, int x2, int y1, int y2, int index)
{
    if(image->imageGetPositionY() > y1 && image->imageGetPositionX() == x1)
        image->sprite.move(0, -velocity);
    if(image->imageGetPositionY() == y1 && image->imageGetPositionX() > x2)
        image->sprite.move(-velocity, 0);
    if(image->imageGetPositionX() == x2 && image->imageGetPositionY() < y2)
        image->sprite.move(0, velocity);
    if(image->imageGetPositionX() == x2 && image->imageGetPositionY() == y2)
    {
        simulaciones[index] = false;
        movimientos = movimientos+1;
        text_movs.setString(toString(movimientos));
    }
}

bool Simulador::clickSprite(sf::Sprite sprite)
{
    sf::FloatRect bounds = sprite.getGlobalBounds();

    if(bounds.contains(this->mouse))
    {
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
            return true;
    }
    return false;
}

void Simulador::chargeFonts()
{
    icon.loadFromFile("src/icono2.png");
    this->window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

    if(!this->font.loadFromFile("src/Switch.ttf"))
        printf("Error de inicializacion ttf\n");

    text_velocidad.setFont(font);
    text_velocidad.setCharacterSize(32);
    text_velocidad.setColor(sf::Color::Black);
    text_velocidad.setPosition(447, 68);
    text_velocidad.setString("2.0");

    text_movs.setFont(font);
    text_movs.setCharacterSize(32);
    text_movs.setColor(sf::Color::Black);
    text_movs.setPosition(738, 68);
    text_movs.setString(toString(movimientos));

    text_discs.setFont(font);
    text_discs.setCharacterSize(32);
    text_discs.setColor(sf::Color::Black);
    text_discs.setPosition(206, 69);
    text_discs.setString(toString(discos));
}

void Simulador::clicksEventsVelocity(ImageList* imageList)
{
    if(clickSprite(imageList->getImageInPosition(5)->sprite) &&
       this->text_velocidad.getString()== "5.0" &&
       imageList->getImageInPosition(5)->visible == true) //Cambiar numero
    {
       velocity = 2;
       this->text_velocidad.setString("2.0");
       return;
    }

    if(clickSprite(imageList->getImageInPosition(5)->sprite) &&
       this->text_velocidad.getString()== "2.0" &&
       imageList->getImageInPosition(5)->visible == true) //Cambiar numero
    {
       velocity = 1;
       this->text_velocidad.setString("1.0");
       return;
    }

    if(clickSprite(imageList->getImageInPosition(5)->sprite) &&
       this->text_velocidad.getString()== "1.0" &&
       imageList->getImageInPosition(5)->visible == true) //Cambiar numero
    {
       velocity = 0.5;
       this->text_velocidad.setString("0.5");
       return;
    }

    if(clickSprite(imageList->getImageInPosition(4)->sprite) &&
       this->text_velocidad.getString()== "0.5" &&
       imageList->getImageInPosition(4)->visible == true) //Cambiar numero
    {
        velocity = 1;
        this->text_velocidad.setString("1.0");
        return;
    }

    if(clickSprite(imageList->getImageInPosition(4)->sprite) &&
       this->text_velocidad.getString()== "1.0" &&
       imageList->getImageInPosition(4)->visible == true) //Cambiar numero
    {
        velocity = 2;
        this->text_velocidad.setString("2.0");
        return;
    }

    if(clickSprite(imageList->getImageInPosition(4)->sprite) &&
       this->text_velocidad.getString()== "2.0" &&
       imageList->getImageInPosition(4)->visible == true) //Cambiar numero
    {
        velocity = 5;
        this->text_velocidad.setString("5.0");
        return;
    }
}

void Simulador::clickEventsDiscs(ImageList* imageList)
{
    if(clickSprite(imageList->getImageInPosition(8)->sprite) &&
       this->text_discs.getString() == toString(discos) &&
       imageList->getImageInPosition(8)->visible == true)
    {
        if(discos < 6)
        {
            discos = discos + 1;
            this->text_discs.setString(toString(discos));
            return;
        }
    }

    if(clickSprite(imageList->getImageInPosition(9)->sprite) &&
       this->text_discs.getString() == toString(discos) &&
       imageList->getImageInPosition(9)->visible == true)
    {
        if(discos > 3)
        {
            discos = discos - 1;
            this->text_discs.setString(toString(discos));
            return;
        }
    }

}

string Simulador::toString(int numero)
{
    if(numero == 0)
        return "0";
        if(numero < 0)
            return "-"+toString(-numero);

    string temp = " ";
    string returnValue = " ";
        while(numero > 0)
        {
            temp += numero%10+48;
            numero /= 10;
        }
        for(int x = 0; x < (int)temp.length(); x++)
            returnValue += temp[temp.length()-x-1];
        return returnValue;
}

void Simulador::setDiscs(ImageList* imageList)
{
    if(!empezar)
    {
        if(discos >= 4)
            imageList->getImageInPosition(18)->setVisible(true);
        else
            imageList->getImageInPosition(18)->setVisible(false);

        if(discos >= 5)
            imageList->getImageInPosition(19)->setVisible(true);
        else
            imageList->getImageInPosition(19)->setVisible(false);

        if(discos == 6)
            imageList->getImageInPosition(20)->setVisible(true);
        else
            imageList->getImageInPosition(20)->setVisible(false);
    }
}

void Simulador::resetSimulations(ImageList* imageList)
{
    if(clickSprite(imageList->getImageInPosition(21)->sprite))
    {
        imageList->getImageInPosition(20)->setVisible(false);
        imageList->getImageInPosition(20)->imageSetPosition(250, 300);
        imageList->getImageInPosition(19)->setVisible(false);
        imageList->getImageInPosition(19)->imageSetPosition(230, 330);
        imageList->getImageInPosition(18)->setVisible(false);
        imageList->getImageInPosition(18)->imageSetPosition(210, 360);

        imageList->getImageInPosition(17)->imageSetPosition(190, 390);
        imageList->getImageInPosition(16)->imageSetPosition(170, 420);
        imageList->getImageInPosition(15)->imageSetPosition(150, 450);

        this->movimientos = 0;
        this->discos = 3;
        text_movs.setString(toString(movimientos));
        text_discs.setString(toString(discos));
        text_velocidad.setString("2.0");
        empezar = false;
        flag = true;
        setSimulaciones();
    }
}

void Simulador::startSimulations(ImageList* imageList)
{
    if(clickSprite(imageList->getImageInPosition(14)->sprite))
    {
        empezar = true;
    }

    if(empezar)
    {
        imageList->getImageInPosition(22)->setVisible(true);
        imageList->getImageInPosition(23)->setVisible(true);
        imageList->getImageInPosition(24)->setVisible(true);
        imageList->getImageInPosition(25)->setVisible(true);

        imageList->getImageInPosition(4)->setVisible(false);
        imageList->getImageInPosition(5)->setVisible(false);
        imageList->getImageInPosition(8)->setVisible(false);
        imageList->getImageInPosition(9)->setVisible(false);
    }
    else{
        imageList->getImageInPosition(22)->setVisible(false);
        imageList->getImageInPosition(23)->setVisible(false);
        imageList->getImageInPosition(24)->setVisible(false);
        imageList->getImageInPosition(25)->setVisible(false);

        imageList->getImageInPosition(4)->setVisible(true);
        imageList->getImageInPosition(5)->setVisible(true);
        imageList->getImageInPosition(8)->setVisible(true);
        imageList->getImageInPosition(9)->setVisible(true);
    }
}

Simulador::~Simulador()
{
    //dtor
}
