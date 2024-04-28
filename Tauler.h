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
        
        void figuraToTauler(const Figura& figura);
        
        bool colisio(const Figura& figura, int mov);
        bool eliminacioFiles();
    private:
        ColorFigura m_tauler[MAX_FILA][MAX_COL];

};
#endif