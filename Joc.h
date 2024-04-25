#ifndef JOC_H
#define JOC_H
#include "Tauler.h"
#include "Figura.h"
#include <string>
using namespace std;

const int MAX_FIGURES = 100;

class Joc
{
public:
	Joc() {}
	void inicialitza(const string& nomFitxer);
	bool giraFigura(DireccioGir direccio);
	bool mouFigura(int dirX);
	int baixaFigura();
	void escriuTauler(const string& nomFitxer);

private:
    Tauler m_tauler;
    Figura m_figura[MAX_FIGURES];
	int m_seguentsFigures[MAX_FIGURES];
};

#endif