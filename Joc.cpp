#include "Joc.h"


void Joc::inicialitza(const string& nomFitxer)
{
    for (int i = 0; i < MAX_FIGURES; i++) 
    {
        m_seguentsFigures[i] = -1;
    }
    ifstream fitxer;
    fitxer.open(nomFitxer);
 
    if (fitxer.is_open()) 
    {   
        //Inicialitza la figura
        int tipus, fila, columna, gir;
        fitxer >> tipus >> fila >> columna >> gir;
        m_figura[0] = Figura(TipusFigura(tipus), fila, columna, gir);


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

        //escriure figura
        m_tauler.escriuTauler(fitxer);
        
        fitxer.close();
    }
}

int arraySize(int array[MAX_FIGURES]) 
{
    bool acabar = false;
    int i = 0;
    while(!acabar) 
    {
        if (array[i]== -1) 
            acabar = true;
        else
            i++;
    }
    return i;
}