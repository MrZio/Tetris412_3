#ifndef FIGURA_H
#define FIGURA_H

#include "InfoJoc.h"

class Figura
{
public:
    // Constructors
    Figura(); // Coinstructor per defecte
    Figura(TipusFigura tipusFigura, int y, int x, int gir) : m_tipus(tipusFigura), m_posicio{ x - 1, y - 1 }, m_gir(gir), m_color(asignarColor(tipusFigura)) {
        figuraToMatriz();
    }


    // Getters
    TipusFigura getTipus() const { return m_tipus; }
    int getFila() const { return m_posicio[1]; }
    int getColumna() const { return m_posicio[0]; }
    int getGir() const { return m_gir; } //FALTA
    void getMatriz(char matriz[MAX_ALCADA][MAX_AMPLADA]) const;
    ColorFigura getColor() const { return m_color; }

    // Metodes
    void figuraToMatriz();
    ColorFigura asignarColor(TipusFigura tipus);
    void giraFigura(const DireccioGir dgir);
    bool detectarI() const;
    void decreasePosicioY() { m_posicio[1] += 1; };
	void increasePosicioY() { m_posicio[1] -= 1; };
    void decreasePosicioX() { m_posicio[0] -= 1; };
    void increasePosicioX() { m_posicio[0] += 1; };

    void dibuixa();

    Figura& operator=(const Figura& other);

private:
    TipusFigura m_tipus;
    int m_posicio[2]; // Index: 0 = x, 1 = y
    int m_gir; // Per saber quin dels 4 girs te la figura
    ColorFigura m_color;
    char m_matriz[MAX_ALCADA][MAX_AMPLADA];
};

#endif