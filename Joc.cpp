#include "Joc.h"

void Joc::inicialitza(const string& nomFitxer)
{
     m_tauler.inicialitzaFitxer(nomFitxer);
}
void escriuTauler(const string& nomFitxer)
{
    m_tauler.escriuTauler(nomFitxer);
}