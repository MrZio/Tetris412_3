#ifndef INFO_JOC_H
#define INFO_JOC_H

#include <fstream> // Per llegir i escriure fitxers
using namespace std; // Per no haver d'escriure std:: en les lectures i escriptures de fitxers

#include "GraphicManager.h" // Per poder dibuixar els quadrats

typedef enum
{
    TECLA_ESQUERRA,
    TECLA_DRETA,
    TECLA_AMUNT,
    TECLA_ABAIX,
    TECLA_ESPAI,
    TECLA_ESCAPE,
    NO_TECLA
} TipusTecla;

typedef enum
{
    MOVIMENT_ESQUERRA = 0,
    MOVIMENT_DRETA = 1,
    MOVIMENT_GIR_HORARI = 2,
    MOVIMENT_GIR_ANTI_HORARI = 3,
    MOVIMENT_BAIXA = 4,
    MOVIMENT_BAIXA_FINAL = 5,
} TipusMoviment;

const int N_TIPUS_FIGURES = 7;

typedef enum
{
    COLOR_NEGRE = 0,
    COLOR_GROC,
    COLOR_BLAUCEL,
    COLOR_MAGENTA,
    COLOR_TARONJA,
    COLOR_BLAUFOSC,
    COLOR_VERMELL,
    COLOR_VERD,
    NO_COLOR
} ColorFigura;

typedef enum
{
    NO_FIGURA = 0,
    FIGURA_O,
    FIGURA_I,
    FIGURA_T,
    FIGURA_L,
    FIGURA_J,
    FIGURA_Z,
    FIGURA_S
} TipusFigura;

typedef enum
{
    GIR_HORARI = 0,
    GIR_ANTI_HORARI
} DireccioGir;

// Tamany de la pantalla gràfica
const int SCREEN_SIZE_X = 600;
const int SCREEN_SIZE_Y = 700;

// Mida dels quadrats que formen el tauler
const int MIDA_QUADRAT = 26;

// Tamany del tauler
const int N_FILES_TAULER = 21;
const int N_COL_TAULER = 11;

// Tamany max de la figura
const int MAX_ALCADA = 4;
const int MAX_AMPLADA = 4;

// Posició del tauler a la pantalla
const int POS_X_TAULER = 120;
const int POS_Y_TAULER = 100;

void dibuixaQuadrat(ColorFigura color, int posX, int posY);

#endif