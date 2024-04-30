#include "Tauler.h"


Tauler::Tauler()
{
    for (int i = 0; i < MAX_FILA; i++) {
        for (int j = 0; j < MAX_COL; j++) {
            m_tauler[i][j] = NO_COLOR;
        }
    }
}

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

void Tauler::figuraToTauler(const Figura& figura)
{
    char figuraMatriu[MAX_ALCADA][MAX_AMPLADA];
    figura.getMatriz(figuraMatriu);

    int filaInicial = figura.getFila();
    int columnaInicial = figura.getColumna();
    ColorFigura color = figura.getColor(); // Obtener el color de la figura

    for (int fila = 0; fila < MAX_ALCADA; fila++)
    {
        for (int col = 0; col < MAX_AMPLADA; col++)
        {
            if (figuraMatriu[fila][col] == 'X')
            {
                int posFila = filaInicial + fila - 1; // -1 pel punt de referencia que está en la fila [1] 
                int posColumna = columnaInicial + col - 2; // -2 pel punt de referencia que está en la columna [2]
                m_tauler[posFila][posColumna] = color; // Colocar el color de la figura en el tauler
            }
        }
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
        case 2: // La figura baixa
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
            break;
        case 1: // La figura va a la dreta
            for (int fila = 0; fila < MAX_ALCADA; fila++)
            {
                for (int col = 0; col < MAX_AMPLADA; col++)
                {
                    if (figuraMatriu[fila][col] == 'X')
                    {
                        int nuevaFila = filaInicial + fila - 1; // -1 pel punt de referencia que está en la fila [1] 
                        int nuevaColumna = columnaInicial + col + 1 - 2; // +1 pel moviment cap a la dreta; -2 pel punt de referencia que está en la columna [2]

                        // Verificar col·lisió amb la vora dreta del tauler
                        if (nuevaColumna >= MAX_AMPLADA)
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
            break;
        case -1: // La figura va a la esquerra
           for (int fila = 0; fila < MAX_ALCADA; fila++)
            {
                for (int col = 0; col < MAX_AMPLADA; col++)
                {
                    if (figuraMatriu[fila][col] == 'X')
                    {
                        int nuevaFila = filaInicial + fila - 1; // -1 pel punt de referencia que está en la fila [1] 
                        int nuevaColumna = columnaInicial + col - 1 - 2; // -1 pel moviment cap a la esquerra; -2 pel punt de referencia que está en la columna [2]

                        // Verificar col·lisió amb la vora esquerra del tauler
                        if (nuevaColumna < 0) 
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
            break; 
        case 0: // Gir horari
        case 3: // Giro antihorari
            // Crear una còpia temporal de la figura per no modificar l'original
            Figura figuraTemporal = figura;
            // Aplicar el gir temporalment a la còpia
            if (mov == 0)
            {
                figuraTemporal.giraFigura(GIR_HORARI);
            } else if (mov == 3)
            {
                figuraTemporal.giraFigura(GIR_ANTI_HORARI);
            }

            // Obtenir la matriu de la còpia temporal
            figuraTemporal.getMatriz(figuraMatriu);

            // Comprovar si el gir causa col·lisions
            for (int fila = 0; fila < MAX_ALCADA; fila++)
            {
                for (int col = 0; col < MAX_AMPLADA; col++)
                {
                    if (figuraMatriu[fila][col] == 'X')
                    {
                        int nuevaFila = filaInicial + fila - 1; // -1 pel punt de referencia que está en la fila [1] 
                        int nuevaColumna = columnaInicial + col - 2; // -2 pel punt de referencia que está en la columna [2]

                        if (nuevaFila >= MAX_FILA || nuevaFila < 0 || nuevaColumna >= MAX_AMPLADA || nuevaColumna < 0) // Verificar col·lisió amb els límits
                            return true;

                        if (m_tauler[nuevaFila][nuevaColumna] != NO_COLOR)// Col·lisió amb altres figures
                            return true;
                    }
                }
            }
            break;
    }
    return false;
}

int Tauler::eliminacioFiles()
{
    int count = 0; // Contador de files eliminadas

        // Recorremos cada fila del tauler
        for (int fila = 0; fila < MAX_FILA; fila++) {
            bool filaCompleta = true; // Asumim que la fila estè completa

            // Verificamos si la fila está plena
            for (int col = 0; col < MAX_COL; col++) {
                if (m_tauler[fila][col] == NO_COLOR) { // Si hi ha algun espai buit, no està completa
                    filaCompleta = false;
                    break;
                }
            }

            if (filaCompleta) { // Si la fila està completa, s'elimina
                count++; // Augmentem el comptador de files eliminades

                // Desplacem totes les files superiors cap avall
                for (int i = fila; i > 0; i--) {
                    for (int col = 0; col < MAX_COL; col++) {
                        m_tauler[i][col] = m_tauler[i - 1][col];
                    }
                }

                // La primera fila ha de quedar buida després del desplaçament
                for (int col = 0; col < MAX_COL; col++) {
                    m_tauler[0][col] = NO_COLOR;
                }
            }
        }

        return count;
}
