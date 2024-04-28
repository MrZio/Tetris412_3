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

bool Tauler::colisio(const Figura& figura, int mov)
{
    char figuraMatriu[MAX_ALCADA][MAX_AMPLADA];
    figura.getMatriz(figuraMatriu);

    int filaInicial = figura.getFila();
    int columnaInicial = figura.getColumna();

    /* Aquest algoritme primer agafa les posicions en que la figura ocupa el espai i després mira al seu alderredor si está ocupat. 
    Depenen del moviment mirar per sota, pel costat esquerra o costat dret*/
    switch(mov)
    {
        case 2:
            for (int fila = 0; fila < MAX_ALCADA; fila++)
            {
                for (int col = 0; col < MAX_AMPLADA; col++)
                {
                    if (figuraMatriu[fila][col] == 'X')
                    {
                        int nuevaFila = filaInicial + fila + 1 - 1;  // +1 perque posició després del  moviment; -1 pel punt de referencia que está en la fila [1] 
                        int nuevaColumna = columnaInicial + col - 2; // -2 pel punt de referencia que está en la columna [2]

                        // Verificar colisió amb la vora inferior del tauler
                        if (nuevaFila >= MAX_FILA)
                        {
                            return true;
                        }

                        // Verificar colisió amb altres figures
                        if (m_tauler[nuevaFila][nuevaColumna] != NO_COLOR)
                        {
                            return true;
                        }
                    }
                }
            }
        case 0:
    }
}