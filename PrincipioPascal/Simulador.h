#ifndef SIMULADOR_H
#define SIMULADOR_H
#include <SFML/Graphics.hpp>
#include "Imaage.h"
#include "ImageList.h"

using namespace std;

class Simulador
{
    public:
        bool simulaciones[64] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
        bool flag = true;
        sf::RenderWindow window;
        Simulador(int WIDTH, int HEIGHT, char* title, ImageList* imageList);
        void drawImages(ImageList* imageList);
        void setSimulaciones();
        void simulacion3(float velocity, ImageList* imageList);
        void simulacion4(float velocity, ImageList* imageList);
        void moves1(Imaage* image, int x1, int x2, int y1, int y2, int index, float velocity);
        void moves2(Imaage* image, int x1, int x2, int y1, int y2, int index, float velocity);

        virtual ~Simulador();

    protected:

    private:
};

#endif // SIMULADOR_H
