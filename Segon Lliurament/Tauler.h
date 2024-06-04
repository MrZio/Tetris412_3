#ifndef TAULER_H
#define TAULER_H
#include "Figura.h"
#include "InfoJoc.h"

class Tauler
{
public:
    Tauler(); //Inicialitzem array a NO COLOR

    void inicialitza(ifstream& fitxer);
    void escriuTauler(ofstream& fitxer) const;

    void figuraToTauler(Figura& figura);

    // bool colisio(const Figura& figura, int mov);
    bool colisio(const Figura& figura);
    int eliminacioFiles();

    void dibuixa();
private:
    ColorFigura m_tauler[N_FILES_TAULER][N_COL_TAULER];
};
#endif