//
//  main.cpp
//
//  Copyright Â© 2018 Compiled Creations Limited. All rights reserved.
//
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__) || defined  (_WIN64)

#define SDL_MAIN_HANDLED //Definicio necesaria per poder incloure la llibreria i que trobi el main

//Llibreria grafica
#elif __APPLE__
#include "../Graphic Lib/libreria.h"
#include "../Graphic Lib/NFont/NFont.h"
#pragma clang diagnostic push // Ignora els warnings de la llibreria SDL
#pragma clang diagnostic ignored "-Wdocumentation" // Ignora els warnings de la llibreria SDL
#include <SDL2/SDL.h> // Llibreria SDL
#pragma clang diagnostic pop // Fi de l'ignorar els warnings de la llibreria SDL
#endif

#include "./Tetris.h"
#include "./InfoJoc.h"

static void menuPrincipal()
{
    cout << "----------------------------------" << endl;
    cout << "-\t\t\t\t -" << endl;
    cout << "-\tMENU PRINCIPAL\t\t -" << endl;
    cout << "-\t\t\t\t -" << endl;
    cout << "----------------------------------" << endl;
    cout << endl;
    cout << "1. Joc en mode normal" << endl;
    cout << "2. Joc en mode test" << endl;
    cout << "3. Puntuacions" << endl;
    cout << "4. Tancar" << endl;
}

int main(int argc, const char* argv[])
{
    //Instruccions necesaries per poder incloure la llibreria i que trobi el main
    SDL_SetMainReady();
    SDL_Init(SDL_INIT_VIDEO);

    //Inicialitza un objecte de la classe Screen que s'utilitza per gestionar la finestra grafica
    Screen pantalla(SCREEN_SIZE_X, SCREEN_SIZE_Y);

    Tetris tetris;;
	tetris.inicialitza(); // Inicialitza la llista de puntuacions

    bool TANCAR = false;
    int punts;
    string jugador;

    do
    {
        menuPrincipal();
        int opcio;
        cin >> opcio;
        switch (opcio)
        {
        case 1:
            punts = tetris.juga(pantalla, 0, "", "", "");
            cout << "Nom del jugador: ";
            cin >> jugador;
            tetris.guardaPuntuacio(jugador, punts);
            break;
        case 2:
            punts = tetris.juga(pantalla, 1, "./data/Games/partida.txt", "./data/Games/figures.txt", "./data/Games/moviments.txt");
            break;
        case 3:
            tetris.mostraPuntuacions();
            break;
        case 4:
            TANCAR = true;
            break;
        default:
            cout << "Opcio incorrecta" << endl;
        }
    } while (!TANCAR); // Sortim del bucle si pressionem amb la opcio 4

    //Instruccio necesaria per alliberar els recursos de la llibreria 
    SDL_Quit();
    return 0;
}