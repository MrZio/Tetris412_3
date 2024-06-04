#ifndef JOC_H
#define JOC_H

#include "Figura.h"
#include "Tauler.h"
#include "InfoJoc.h"

class Joc
{
public:
	Joc() : m_tauler(), m_figura() {}

	void inicialitza(const string& nomFitxer);
	void escriuTauler(const string& nomFitxer);

	bool novaFigura(); // Si hi ha colisio (true), partida acabada
	void novaFigura(const Figura& fig); // Pel mode test

	int baixaFigura(); //mov = 2
	bool mouFigura(int dirX); //mov = +1 o -1
	bool giraFigura(DireccioGir direccio); //mov = 0 (horari) o 3 (antihorari)

	void dibuixa();
private:
	Tauler m_tauler;
	Figura m_figura;
};

#endif