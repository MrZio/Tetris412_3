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
	Joc() : m_tauler(), m_figura() {}

	void inicialitza(const string& nomFitxer);
	void escriuTauler(const string& nomFitxer);

	int baixaFigura(); //mov = 2
	bool mouFigura(int dirX); //mov = +1 o -1
	bool giraFigura(DireccioGir direccio); //mov = 0 (horari) o 3 (antihorari)

private:
    Tauler m_tauler;
    Figura m_figura;
};

#endif