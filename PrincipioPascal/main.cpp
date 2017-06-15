#include <iostream>
#include "Simulador.h"
#include <SFML/Graphics.hpp>
#include "Imaage.h"
#include "ImageList.h"

int main()
{
    system("color A");

    Imaage* background = new Imaage();
    background->imageChargeFile("src/background.png");
    background->imageSetPosition(0, -40);
    background->setVisible(true);

    Imaage* torre1 = new Imaage();
    torre1->imageChargeFile("src/torre.png");
    torre1->imageSetPosition(148, 286);
    torre1->setVisible(true);

    Imaage* torre2 = new Imaage();
    torre2->imageChargeFile("src/torre.png");
    torre2->imageSetPosition(448, 286);
    torre2->setVisible(true);

    Imaage* torre3 = new Imaage();
    torre3->imageChargeFile("src/torre.png");
    torre3->imageSetPosition(748, 286);
    torre3->setVisible(true);

    Imaage* disco1 = new Imaage();
    disco1->imageChargeFile("src/discos/disco1.png");
    disco1->imageSetPosition(150, 450);
    disco1->setVisible(true);

    Imaage* disco2 = new Imaage();
    disco2->imageChargeFile("src/discos/disco2.png");
    disco2->imageSetPosition(170, 420);
    disco2->setVisible(true);

    Imaage* disco3 = new Imaage();
    disco3->imageChargeFile("src/discos/disco3.png");
    disco3->imageSetPosition(190, 390);
    disco3->setVisible(true);

    Imaage* disco4 = new Imaage();
    disco4->imageChargeFile("src/discos/disco4.png");
    disco4->imageSetPosition(210, 360);
    disco4->setVisible(false);

    Imaage* disco5 = new Imaage();
    disco5->imageChargeFile("src/discos/disco5.png");
    disco5->imageSetPosition(230, 330);
    disco5->setVisible(false);

    Imaage* disco6 = new Imaage();
    disco6->imageChargeFile("src/discos/disco6.png");
    disco6->imageSetPosition(250, 300);
    disco6->setVisible(false);

    Imaage* boton_up = new Imaage();
    boton_up->imageChargeFile("src/up.png");
    boton_up->imageSetPosition(490, 69);
    boton_up->setVisible(true);

    Imaage* boton_down = new Imaage();
    boton_down->imageChargeFile("src/down.png");
    boton_down->imageSetPosition(490, 90);
    boton_down->setVisible(true);

    Imaage* caja_texto = new Imaage();
    caja_texto->imageChargeFile("src/caja1.png");
    caja_texto->imageSetPosition(438, 69);
    caja_texto->setVisible(true);

    Imaage* texto_vel = new Imaage();
    texto_vel->imageChargeFile("src/velocidad.png");
    texto_vel->imageSetPosition(295, 78);
    texto_vel->setVisible(true);

    Imaage* boton_up1 = new Imaage();
    boton_up1->imageChargeFile("src/up.png");
    boton_up1->imageSetPosition(250, 69);
    boton_up1->setVisible(true);

    Imaage* boton_down1 = new Imaage();
    boton_down1->imageChargeFile("src/down.png");
    boton_down1->imageSetPosition(250, 90);
    boton_down1->setVisible(true);

    Imaage* caja_texto1 = new Imaage();
    caja_texto1->imageChargeFile("src/caja1.png");
    caja_texto1->imageSetPosition(198, 69);
    caja_texto1->setVisible(true);

    Imaage* texto_discos = new Imaage();
    texto_discos->imageChargeFile("src/nDiscos.png");
    texto_discos->imageSetPosition(20, 74);
    texto_discos->setVisible(true);

    Imaage* texto_movs = new Imaage();
    texto_movs->imageChargeFile("src/mMinimos.png");
    texto_movs->imageSetPosition(545, 78);
    texto_movs->setVisible(true);

    Imaage* caja_texto2 = new Imaage();
    caja_texto2->imageChargeFile("src/caja1.png");
    caja_texto2->imageSetPosition(730, 69);
    caja_texto2->setVisible(true);

    Imaage* btnEmpezar = new Imaage();
    btnEmpezar->imageChargeFile("src/boton_empezar.png");
    btnEmpezar->imageSetPosition(810, 66);
    btnEmpezar->setVisible(true);

    Imaage* btnResetear = new Imaage();
    btnResetear->imageChargeFile("src/boton_reiniciar.png");
    btnResetear->imageSetPosition(920, 66);
    btnResetear->setVisible(true);

    Imaage* btnDispose1 = new Imaage();
    btnDispose1->imageChargeFile("src/nohbt_up.png");
    btnDispose1->imageSetPosition(250, 69);
    btnDispose1->setVisible(false);

    Imaage* btnDispose2 = new Imaage();
    btnDispose2->imageChargeFile("src/nohbt_up.png");
    btnDispose2->imageSetPosition(490, 69);
    btnDispose2->setVisible(false);

    Imaage* btnDispose3 = new Imaage();
    btnDispose3->imageChargeFile("src/nohbt_down.png");
    btnDispose3->imageSetPosition(250, 90);
    btnDispose3->setVisible(false);

    Imaage* btnDispose4 = new Imaage();
    btnDispose4->imageChargeFile("src/nohbt_down.png");
    btnDispose4->imageSetPosition(490, 90);
    btnDispose4->setVisible(false);

    Imaage* btnSalir = new Imaage();
    btnSalir->imageChargeFile("src/boton_salir.png");
    btnSalir->imageSetPosition(1030, 66);
    btnSalir->setVisible(true);

    Imaage* textTorre1 = new Imaage();
    textTorre1->imageChargeFile("src/text_torre1.png");
    textTorre1->imageSetPosition(230, 510);
    textTorre1->setVisible(true);

    Imaage* textTorre2 = new Imaage();
    textTorre2->imageChargeFile("src/text_torre2.png");
    textTorre2->imageSetPosition(530, 510);
    textTorre2->setVisible(true);

    Imaage* textTorre3 = new Imaage();
    textTorre3->imageChargeFile("src/text_torre3.png");
    textTorre3->imageSetPosition(830, 510);
    textTorre3->setVisible(true);


    ImageList* imageList = new ImageList();
    imageList->addImage(background);
    imageList->addImage(torre1); //1
    imageList->addImage(torre2); //2
    imageList->addImage(torre3); //3
    imageList->addImage(boton_up); //4
    imageList->addImage(boton_down); //5
    imageList->addImage(caja_texto); //6
    imageList->addImage(texto_vel); //7
    imageList->addImage(boton_up1); //8
    imageList->addImage(boton_down1); //9
    imageList->addImage(texto_discos); //10
    imageList->addImage(caja_texto1); //11
    imageList->addImage(texto_movs); //12
    imageList->addImage(caja_texto2); //13
    imageList->addImage(btnEmpezar); //14
    imageList->addImage(disco1); //15
    imageList->addImage(disco2); //16
    imageList->addImage(disco3); //17
    imageList->addImage(disco4); //18
    imageList->addImage(disco5); //19
    imageList->addImage(disco6); //20
    imageList->addImage(btnResetear); //21
    imageList->addImage(btnDispose1); //22
    imageList->addImage(btnDispose2); //23
    imageList->addImage(btnDispose3); //24
    imageList->addImage(btnDispose4); //25
    imageList->addImage(btnSalir); //26
    imageList->addImage(textTorre1); //27
    imageList->addImage(textTorre2); //28
    imageList->addImage(textTorre3); //29


    Simulador* simulador = new Simulador(1200, 600, "Torres de Hanoi", imageList);

    return 0;
}
