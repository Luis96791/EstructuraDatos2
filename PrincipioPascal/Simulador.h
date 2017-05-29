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
        sf::RenderWindow window;
        Simulador(int WIDTH, int HEIGHT, char* title, ImageList* imageList);
        void drawImages(ImageList* imageList);
        void setSimulaciones();
        void simulacion3(float velocity, ImageList* imageList);
        void simulacion4(float velocity, ImageList* imageList);

        virtual ~Simulador();

    protected:

    private:
};

#endif // SIMULADOR_H
