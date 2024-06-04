#include "Joc.h"

// Libreries necessàries per a la generació de figures aleatories
#include <cstdlib> // Para srand y rand
#include <ctime>   // Para time
#include <chrono>  // Para high_resolution_clock

void Joc::inicialitza(const string& nomFitxer)
{
    ifstream fitxer;
    fitxer.open(nomFitxer);

    if (fitxer.is_open())
    {
        int tipus, fila, columna, gir; // Inicialitza la figura
        fitxer >> tipus >> fila >> columna >> gir;
        m_figura = Figura(TipusFigura(tipus), fila + 1, columna, gir);

        for (int i = 0; i < gir; i++) // Gira la figura
            m_figura.giraFigura(GIR_HORARI);

        m_tauler.inicialitza(fitxer);

        fitxer.close();
    }
}

void Joc::escriuTauler(const string& nomFitxer)
{
    ofstream fitxer;
    fitxer.open(nomFitxer);
    if (fitxer.is_open())
    {
        m_tauler.figuraToTauler(m_figura);
        m_tauler.escriuTauler(fitxer);

        fitxer.close();
    }
}

bool Joc::novaFigura()
{
    srand(time(nullptr) + chrono::high_resolution_clock::now().time_since_epoch().count()); // Inicialitzar la llavor aleatòriament

    // Generem una figura aleatoria
    TipusFigura tipus = TipusFigura((rand() % N_TIPUS_FIGURES) + 1);
    int nGir = (rand() % 4);
    int columna;

    switch (tipus)
    {
    case FIGURA_O:
        columna = (rand() % (N_COL_TAULER - 1)) + 1; // + 1 ja que la primera columna es la 1;
        break;
    case FIGURA_I:
        columna = (rand() % (N_COL_TAULER - 3)) + 1; // + 1 ja que la primera columna es la 1;
        break;
    default:
        columna = (rand() % (N_COL_TAULER - 2)) + 1; // + 1 ja que la primera columna es la 1;
    }

    m_figura = Figura(tipus, 2, columna, nGir);

    if (m_tauler.colisio(m_figura))
        return true;
    else
        return false;
}

void Joc::novaFigura(const Figura& fig)
{
    m_figura = fig;
    m_figura.decreasePosicioY(); // Per compensar
}

int Joc::baixaFigura()
{
    int filesCompletades = -1; // Numero de posicions que ha baixat

    m_figura.decreasePosicioY();

    if (m_tauler.colisio(m_figura))
    {
		m_figura.increasePosicioY();
		m_tauler.figuraToTauler(m_figura);
		filesCompletades = m_tauler.eliminacioFiles();
	}
    return filesCompletades;
}

bool Joc::mouFigura(int dirX)
{
    if (dirX == -1)
        m_figura.decreasePosicioX();
    else
        m_figura.increasePosicioX();

    if (m_tauler.colisio(m_figura))
    {
        if (dirX == -1)
            m_figura.increasePosicioX();
        else
            m_figura.decreasePosicioX();
		return false;
    }

    return true;
}

bool Joc::giraFigura(DireccioGir direccio)
{
	if (m_figura.getColor() == COLOR_GROC) // Si es el color groc, no es pot girar
		return true;
    m_figura.giraFigura(direccio);
	if (m_tauler.colisio(m_figura))
	{
        if (direccio == GIR_HORARI)
            direccio = GIR_ANTI_HORARI;
        else
            direccio = GIR_HORARI;
        m_figura.giraFigura(direccio);
		return false;
	}
    return true;
}

void Joc::dibuixa()
{
    m_tauler.dibuixa();
    m_figura.dibuixa();
}