#ifndef SIMULADOR_H
#define SIMULADOR_H
#include <SFML/Graphics.hpp>
#include "Imaage.h"
#include "ImageList.h"

using namespace std;

class Simulador
{
    public:
        bool simulaciones[64] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
                                 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
                                 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
                                 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
        bool flag = true, empezar = false, pause = false;
        float velocity = 2.0;
        int movimientos = 0, discos = 3;

        sf::RenderWindow window;
        sf::Vector2f mouse;
        sf::Font font;
        sf::Text text_velocidad, text_movs, text_discs;
        sf::Image icon;


        Simulador(int WIDTH, int HEIGHT, char* title, ImageList* imageList);
        void drawImages(ImageList* imageList);
        void setSimulaciones();
        void simulacion3(ImageList* imageList);
        void simulacion4(ImageList* imageList);
        void simulacion5(ImageList* imageList);
        void simulacion6(ImageList* imageList);
        void moves1(Imaage* image, int x1, int x2, int y1, int y2, int index);
        void moves2(Imaage* image, int x1, int x2, int y1, int y2, int index);
        bool clickSprite(sf::Sprite sprite);
        void chargeFonts();
        void clicksEventsVelocity(ImageList* imageList);
        void clickEventsDiscs(ImageList* imageList);
        void setDiscs(ImageList* imageList);
        string toString(int numero);
        void resetSimulations(ImageList* imageList);
        void startSimulations(ImageList* imageList);

        virtual ~Simulador();

    protected:

    private:
};

#endif // SIMULADOR_H
