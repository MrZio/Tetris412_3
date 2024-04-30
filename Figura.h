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
    Figura(TipusFigura tipusFigura, int y, int x, int gir) : m_tipus(tipusFigura), m_posicio{x, y}, m_gir(gir), m_color(asignarColor(tipusFigura)) {figuraToMatriz();}
    
    // Setters
    void setPosicioFiguraX(const int x);
    void setPosicioFiguraY(const int y);
    void setFormaActualFigura(const int direccio);

    // Getters
    TipusFigura getTipus() const { return m_tipus; }
    int getFila() const { return m_posicio[1]; }
    int getColumna() const { return m_posicio[0]; }
    int getGir() const { return m_gir; } //FALTA
    void getMatriz(char matriz[MAX_ALCADA][MAX_AMPLADA]) const;
    ColorFigura getColor() const {return m_color;}

    // Metodes
    void figuraToMatriz();
    ColorFigura asignarColor(TipusFigura tipus);

    void giraFigura(const DireccioGir dgir);
    void decreasePosicioY() {m_posicio[1] -= 1;};
    void decreasePosicioX() {m_posicio[0] -= 1;};
    void increasePosicioX() {m_posicio[0] += 1;};

    Figura& operator=(const Figura& other);

private:
    TipusFigura m_tipus;
    // Index: 0 = x, 1 = y
    int m_posicio[2];
    // Per saber quin dels 4 girs te la figura
    int m_gir;
    ColorFigura m_color;
    char m_matriz[MAX_ALCADA][MAX_AMPLADA]; // La posició de referència per a la ubicació de les figures és [1][2]
};


#endif
