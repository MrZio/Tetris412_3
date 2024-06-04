#ifndef PARTIDA_H
#define PARTIDA_H

#include "Joc.h"
#include "LlistaFigura.h"
#include "LlistaMoviment.h"
#include "InfoJoc.h"
#include "HUD.h"

class Partida
{
public:
	Partida() : m_gameOver(false), m_punts(0), m_nivell(1), m_temps(0), m_velocitat(1), m_bonus(0) {}

    void inicialitza(int mode, const string& fitxerInicial, const string& fitxerFigures, const string& fitxerMoviments);
    void guardaLlistatFigures(const string& fitxerFigures);
    void guardaLlistatMoviments(const string& fitxerMoviments);

    void actualitza(int mode, double deltaTime);
    void actualitzaNormal(float deltaTime);
    void actualitzaTest(float deltaTime);
    void actualitzaPuntuacio(int nFilesEliminades);

    int getPuntuacio() const { return m_punts; }
private:
    Joc m_joc;
    bool m_gameOver;

    int m_punts;
    int m_nivell;

    double m_temps;
    double m_velocitat;

    // Atributs pel mode test
    LlistaFigura m_figures;
    LlistaMoviment m_moviments;

	HUD m_hud; // Objecte per mostrar el text de la pantalla
    int m_bonus;
};

#endif 