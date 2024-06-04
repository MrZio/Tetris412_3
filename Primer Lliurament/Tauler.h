#ifndef TAULER_H
#define TAULER_H
#include "Figura.h"




const int MAX_FILA = 8;
const int MAX_COL = 8;

class Tauler
{
    public:
        Tauler (); //Inicialitzem array a NO COLOR
        
        void inicialitza(ifstream& fitxer);
        void escriuTauler(ofstream& fitxer) const;
        
        void figuraToTauler(Figura& figura);
        
        bool colisio(const Figura& figura, int mov);
        int eliminacioFiles();

        void setFiguraColocada(bool estat) {m_figuraColocada = estat;}

    private:
        ColorFigura m_tauler[MAX_FILA][MAX_COL];
        bool m_figuraColocada; // Per impedir que la fiura es posi varies vegades

};
#endif
