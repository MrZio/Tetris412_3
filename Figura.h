#ifndef FIGURA_H
#define FIGURA_H

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
    Figura(TipusFigura tipus, ColorFigura color, int posX = 0, int posY = 0); //Constructor amb tots el paràmetres

    void moureLateral(int dirX);
    void baixar();
    void girar(DireccioGir direccio);
    
    // Mètodes d'accés per obtenir informació sobre la figura
    TipusFigura getTipus() const { return m_tipus; }
    ColorFigura getColor() const { return m_color; }
    int getPosX() const { return m_posX; }
    int getPosY() const { return m_posY; }
private:
    TipusFigura m_tipus;
    ColorFigura m_color;
    int m_posX;
    int m_posY;
    int m_forma[MAX_ALCADA][MAX_AMPLADA]; // Matriu que representa la forma de la figura
};


#endif
