#include "Tauler.h"


Tauler::Tauler()
{
    for (int i = 0; i < MAX_FILA; i++)
    {
        for (int j = 0; j < MAX_COL; j++)
            m_tauler[i][j] = NO_COLOR;
    }
    m_figuraColocada = false;
}

void Tauler::inicialitza(ifstream& fitxer)
{
	int fila = 0;

	while (fitxer && fila < MAX_FILA)
	{
		for (int col = 0; col < MAX_COL; col++)
		{
			int valor;
			fitxer >> valor; // Llegeix el valor del fitxer
				m_tauler[fila][col] = ColorFigura(valor);
		}
		fila++; // Incrementa la fila
	}
	m_figuraColocada = false;
}

void Tauler::escriuTauler(ofstream& fitxer) const
{
    for (int fila = 0; fila < MAX_FILA; fila++) 
    {
        for (int col = 0; col < MAX_COL; col++) 
            fitxer << static_cast<int>(m_tauler[fila][col]) << " "; // Escriu el valor del taulell (representant el color) en el archiu
        fitxer << endl; // Salt de línia
    }
}

void Tauler::figuraToTauler(Figura& figura)
{
	if (!m_figuraColocada){
		char figuraMatriu[MAX_ALCADA][MAX_AMPLADA];
		figura.getMatriz(figuraMatriu);

		int filaInicial = figura.getFila();
		int columnaInicial = figura.getColumna();
		ColorFigura color = figura.getColor(); // Obtenir el color de la figura

		for (int fila = 0; fila < MAX_ALCADA; fila++)
		{
			for (int col = 0; col < MAX_AMPLADA; col++)
			{
				if (figuraMatriu[fila][col] == 'X')
				{
					int posFila = filaInicial + fila;
					int posColumna = columnaInicial + col;
					m_tauler[posFila][posColumna] = color; // Colocar el color de la figura en el tauler
				}
			}
		}
	}
}

bool Tauler::colisio(const Figura& figura, int mode) {
    char figuraMatriu[MAX_ALCADA][MAX_AMPLADA];
    figura.getMatriz(figuraMatriu);

    int filaInicial = figura.getFila();
    int columnaInicial = figura.getColumna();
    int movY = 0;
    int movX = 0;

    switch (mode)
    {
        case 2: // Moviment cap avall
            movY = 1;
            break;
        case 1: // Moviment cap a la dreta
            movX = 1;
            break;
        case -1: // Moviment cap a l'esquerra
            movX = -1;
            break;
        case 0: // Girar la figura (horari)
        case 3: // Girar la figura (antihorari)
            Figura figuraTemporal = figura; // Còpia de la figura per girar temporalment

            if (mode == 0)
                figuraTemporal.giraFigura(GIR_HORARI); // Girar horari
            else
                figuraTemporal.giraFigura(GIR_ANTI_HORARI); // Girar antihorari
            figuraTemporal.getMatriz(figuraMatriu);
            break;
    }

    for (int fila = 0; fila < MAX_ALCADA; fila++) // Comprovar col·lisions després del desplaçament o gir
    { 
        for (int col = 0; col < MAX_AMPLADA; col++)
        {
            if (figuraMatriu[fila][col] == 'X')
            {
                int novaFila = filaInicial + fila + movY;
                int novaColumna = columnaInicial + col + movX;

                if (novaFila >= MAX_FILA || novaFila < 0 || novaColumna >= MAX_COL || novaColumna < 0) // Comprovar col·lisions amb els límits del tauler
                    return true;
                if (m_tauler[novaFila][novaColumna] != COLOR_NEGRE) // Comprovar col·lisions amb altres figures
                    return true;
            }
        }
    }
    return false;
}

int Tauler::eliminacioFiles()
{
    int count = 0; // Contador de files eliminadas

	for (int fila = 0; fila < MAX_FILA; fila++) // Recorrem totes les files del tauler
	{
		bool filaCompleta = true; // Asumim que la fila estè completa

		for (int col = 0; col < MAX_COL; col++) // Verifica si la fila está plena
        {
			if (m_tauler[fila][col] == COLOR_NEGRE)
            { 
				filaCompleta = false;
				break;
			}
		}

		if (filaCompleta) // Si la fila està completa, s'elimina
        {
			count++; // Augmentem el comptador de files eliminades
			for (int i = fila; i > 0; --i) // Desplacem totes les files superiors cap avall
            {
                for (int j = 0; j < MAX_COL; ++j) // Copiar la fila superior a la fila actual
                    m_tauler[i][j] = m_tauler[i - 1][j];
            }
			for (int j = 0; j < MAX_COL; ++j) // Omplir la fila superior amb ceros
				m_tauler[0][j] = COLOR_NEGRE;
		}
	}
	return count;
}