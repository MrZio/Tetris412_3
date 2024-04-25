#include "Tauler.h"


Tauler::Tauler()
{}

void Tauler::setCasella(const int numero, const int x, const int y)
{
    m_tauler[x][y] = numero;
}