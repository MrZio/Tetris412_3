#include "Joc.h"


void Joc::inicialitza(const string& nomFitxer)
{
    ifstream fitxer;
    fitxer.open(nomFitxer);
 
    if (fitxer.is_open()) 
    {   
        int tipus, fila, columna, gir; // Inicialitza la figura
        fitxer >> tipus >> fila >> columna >> gir;
        m_figura = Figura(TipusFigura(tipus), fila, columna, gir);

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

int Joc::baixaFigura()
{
    int filesCompletades; // Numero de posicions que ha baixat
    for (int pos = 0; pos < MAX_COL; pos++)
    {
        if (m_tauler.colisio(m_figura, 2))
            break;
        else
        	m_figura.decreasePosicioY();
    }
    m_tauler.figuraToTauler(m_figura);
    filesCompletades = m_tauler.eliminacioFiles();

    if (filesCompletades > 0)
    	m_tauler.setFiguraColocada(true);

    return filesCompletades;
}

bool Joc::mouFigura(int dirX)
{
    if (!m_tauler.colisio(m_figura, dirX))
    {
        if (dirX == -1)
            m_figura.decreasePosicioX();
        else   
            m_figura.increasePosicioX();
        return true;
    }
    return false;
}

bool Joc::giraFigura(DireccioGir direccio)
{
    int mov;
    if (direccio == GIR_HORARI)
        mov = 0;
    else if (direccio == GIR_ANTI_HORARI)
        mov = 3;

    if (!m_tauler.colisio(m_figura, mov))
    {
        m_figura.giraFigura(direccio);
        return true;
    }else
        return false;
}
