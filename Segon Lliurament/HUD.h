#ifndef HUD_H
#define HUD_H

#include "InfoJoc.h"

#include <cstdlib> // Para srand y rand
#include <ctime>   // Para time
#include <chrono>  // Para high_resolution_clock

class HUD
{
public:
	HUD() : m_movimentVertical(0), m_tempsFEliminada(0), m_tempsPujadaNivell(0), m_FilaEliminada(false), m_pujadaNivell(false), m_tempsParpadeig(0)
	{
		srand(time(nullptr) + chrono::high_resolution_clock::now().time_since_epoch().count()); // Inicialitzar la llavor aleatòriament
		m_posY = rand() % 300;
	}
	void actualitza(double deltaTime, bool gameOver, int punts, int nivell, int bonus);

	void mostraPuntuacioNivell(int punts, int nivell);
	void mostraGameOver(int punts, double deltaTime);
	void mostraPujadaNivell(int nivell);
	void mostraFilaEliminada(int bonus);

	void setFilaEliminada(bool filaEliminada) { m_FilaEliminada = filaEliminada; }
	void setPujadaNivell(bool pujadaNivell) { m_pujadaNivell = pujadaNivell; }

private:
	// Atributs per mostrar pujada de nivell
	bool m_pujadaNivell;
	double m_tempsPujadaNivell;

	// Atributs per mostrar text de fila eliminada
	bool m_FilaEliminada;
	double m_tempsFEliminada;
	double m_movimentVertical;
	int m_posY;

	// Atributs per mostrar text de Game Over
	double m_tempsParpadeig;
};

#endif