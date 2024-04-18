#ifndef TAULER_H
#define TAULER_H
#include "Figura.h"

const int MAX_FILA = 8;
const int MAX_COL = 8;

class Tauler
{
    public:
        Tauler (); //Inicialitzem array a NO COLOR
        void inicialitzaFitxer(const string& nomFitxer);
        void escriuTauler(const string& nomFitxer) const;
        
        
        void figuraToTauler(const Figura& figura);
        
        bool colisio(); //parametres?
        bool eliminacioFiles();
    private:
        ColorFigura m_tauler[N_FILES][N_COLUMNES];
};
#endif