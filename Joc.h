#ifndef JOC_H
#define JOC_H
#include "Tauler.h"
#include "Figura.h"
#include <string>
#include <fstream>
#include <iostream>
using namespace std;

const int MAX_FIGURES = 100;

class Joc
{
public:
	Joc() {}

	void inicialitza(const string& nomFitxer);
	void escriuTauler(const string& nomFitxer);

	int baixaFigura(); //mov = 2
	bool giraFigura(DireccioGir direccio); //mov = 0 o 3
	bool mouFigura(int dirX); //mov = +1 o -1

private:
    Tauler m_tauler;
    Figura m_figura;
	int m_seguentsFigures[MAX_FIGURES];
};

#endif