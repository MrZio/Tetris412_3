#include "Tauler.h"


Tauler::Tauler()
{}

void Tauler::inicialitza(std::ifstream& fitxer)
{
    int fila = 0;

    // Lee las filas del tablero desde el archivo
    while (fitxer && fila < MAX_FILA) 
    {
        for (int col = 0; col < MAX_COL; col++)
        {
            int valor;
            fitxer >> valor; // Leer el valor de la celda
            
                m_tauler[fila][col] = ColorFigura(valor);
        }
        fila++; // Incrementa la fila
    }
}

void Tauler::escriuTauler(ofstream& fitxer) const
{
    for (int fila = 0; fila < MAX_FILA; fila++) 
    {
        for (int col = 0; col < MAX_COL; col++) 
        {
            // Escribe el valor del tablero (representando el color) en el archivo
            fitxer << static_cast<int>(m_tauler[fila][col]) << " ";
        }
        fitxer << endl; // Nueva línea al final de cada fila
    }
}