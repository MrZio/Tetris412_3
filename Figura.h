#ifndef FIGURA_H
#define FIGURA_H
#include <string>
#include <fstream>
#include <iostream>
using namespace std;


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
    FIGURA_S,
} TipusFigura;

const int MAX_ALCADA = 4;
const int MAX_AMPLADA = 4;

typedef enum
{
    GIR_HORARI = 0,
    GIR_ANTI_HORARI
} DireccioGir;

class Figura
{
public:
    // Constructors
    Figura(); // Coinstructor per defecte
    Figura(TipusFigura tipusFigura, int x, int y, int gir) : m_tipus(tipusFigura), m_posicio{x, y}, m_gir(gir) {figuraToMatriz();}
    
    // Setters
    void setPosicioFiguraX(const int x);
    void setPosicioFiguraY(const int y);
    void setFormaActualFigura(const int direccio);

    // Getters
    TipusFigura getTipus() const { return m_tipus; }
    int getFila() const { return m_posicio[1]; }
    int getColumna() const { return m_posicio[0]; }
    int getGir() const { return m_gir; }
    void getMatriz(char matriz[MAX_ALCADA][MAX_AMPLADA]) const;

    // Metodes
    void figuraToMatriz();
    void giraFigura();

    void decreasePosicioY() {m_posicio[1] -= 1;};
    void decreasePosicioX();
    void increasePosicioX();

private:
    ColorFigura m_color;
    TipusFigura m_tipus;

    char m_matriz[MAX_ALCADA][MAX_AMPLADA]; // La posició de referència per a la ubicació de les figures és [1][2]

    // Index: 0 = x, 1 = y
    int m_posicio[2];

    // Per saber quina de les 4 posicions te la figura
    int m_gir;
};


#endif