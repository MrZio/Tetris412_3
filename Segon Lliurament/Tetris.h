#ifndef TETRIS_H
#define TETRIS_H

#include <list> // Per gestionar la llista de puntuacions
#include <iostream> // Per a cout de mostraPuntuacions

#include "Partida.h"
#include "InfoJoc.h"

typedef struct
{
	string jugador;
	int punts;
} Puntuacio;

class Tetris
{
public:

	Tetris() : m_partida() {}

	void inicialitza();
	int juga(Screen& pantalla, int mode, const string& fitxerInicial, const string& fitxerFigures, const string& fitxerMoviments);

	void guardaPuntuacio(const string& jugador, int punts);
	void mostraPuntuacions();
private:
	Partida m_partida;
	list<Puntuacio> m_puntuacions;
};

#endif 