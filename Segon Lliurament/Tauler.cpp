#include "Tauler.h"

Tauler::Tauler()
{
    for (int i = 0; i < N_FILES_TAULER; i++)
        for (int j = 0; j < N_COL_TAULER; j++)
            m_tauler[i][j] = COLOR_NEGRE;
}

void Tauler::inicialitza(ifstream& fitxer)
{
    int fila = 0;

    while (fitxer && fila < N_FILES_TAULER)
    {
        for (int col = 0; col < N_COL_TAULER; col++)
        {
            int valor;
            fitxer >> valor; // Llegeix el valor del fitxer
            m_tauler[fila][col] = ColorFigura(valor);
        }
        fila++; // Incrementa la fila
    }
}

void Tauler::escriuTauler(ofstream& fitxer) const
{
    for (int fila = 0; fila < N_FILES_TAULER; fila++)
    {
        for (int col = 0; col < N_COL_TAULER; col++)
            fitxer << static_cast<int>(m_tauler[fila][col]) << " "; // Escriu el valor del taulell (representant el color) en el archiu
        fitxer << endl; // Salt de línia
    }
}

void Tauler::figuraToTauler(Figura& figura)
{
    char figuraMatriu[MAX_ALCADA][MAX_AMPLADA];
    figura.getMatriz(figuraMatriu);

    int filaInicial = figura.getFila();
    int columnaInicial = figura.getColumna();
    ColorFigura color = figura.getColor(); // Obtenir el color de la figura

    for (int fila = 0; fila < MAX_ALCADA; fila++)
        for (int col = 0; col < MAX_AMPLADA; col++)
            if (figuraMatriu[fila][col] == 'X')
            {
                int posFila = filaInicial + fila;
                int posColumna = columnaInicial + col;

                m_tauler[posFila][posColumna] = color; // Colocar el color de la figura en el tauler
            }
}


bool Tauler::colisio(const Figura& figura)
{
    char figuraMatriu[MAX_ALCADA][MAX_AMPLADA];

    int filaInicial = figura.getFila();
    int columnaInicial = figura.getColumna();

    figura.getMatriz(figuraMatriu);

    for (int fila = 0; fila < MAX_ALCADA; fila++) // Comprovar col·lisions després del desplaçament o gir
        for (int col = 0; col < MAX_AMPLADA; col++)
            if (figuraMatriu[fila][col] == 'X')
            {
                int novaFila = filaInicial + fila;
                int novaColumna = columnaInicial + col;

                if (novaFila >= N_FILES_TAULER || novaFila < 0 || novaColumna >= N_COL_TAULER || novaColumna < 0) // Comprovar col·lisions amb els lÃ­mits del tauler
                    return true;
                if (m_tauler[novaFila][novaColumna] != COLOR_NEGRE) // Comprovar col·lisions amb altres figures
                    return true;
            }
    return false;
}

int Tauler::eliminacioFiles()
{
    int count = 0; // Contador de files eliminadas

    for (int fila = 0; fila < N_FILES_TAULER; fila++) // Recorrem totes les files del tauler
    {
        bool filaCompleta = true; // Asumim que la fila estÃ¨ completa

        for (int col = 0; col < N_COL_TAULER; col++) // Verifica si la fila està plena
            if (m_tauler[fila][col] == COLOR_NEGRE)
            {
                filaCompleta = false;
                break;
            }

        if (filaCompleta) // Si la fila està  completa, s'elimina
        {
            count++; // Augmentem el comptador de files eliminades
            for (int i = fila; i > 0; --i) // Desplacem totes les files superiors cap avall
                for (int j = 0; j < N_COL_TAULER; ++j) // Copiar la fila superior a la fila actual
                    m_tauler[i][j] = m_tauler[i - 1][j];

            for (int j = 0; j < N_COL_TAULER; ++j) // Omplir la fila superior amb ceros
                m_tauler[0][j] = COLOR_NEGRE;
        }
    }
    return count;
}

void Tauler::dibuixa()
{
    GraphicManager::getInstance()->drawSprite(GRAFIC_TAULER, POS_X_TAULER, POS_Y_TAULER, false); // Dibuixar el tauler buit

    for (int i = 0; i < N_FILES_TAULER; i++)
        for (int j = 0; j < N_COL_TAULER; j++)
            if ((m_tauler[i][j] != NO_COLOR) && (m_tauler[i][j] != COLOR_NEGRE))
                dibuixaQuadrat(m_tauler[i][j], POS_X_TAULER + ((j + 1) * MIDA_QUADRAT), POS_Y_TAULER + (i * MIDA_QUADRAT));
}