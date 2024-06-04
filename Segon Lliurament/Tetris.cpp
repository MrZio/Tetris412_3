#include "Tetris.h"
#include "InfoJoc.h"
#include "GraphicManager.h"

void Tetris::inicialitza()
{
	ifstream fitxer;
	fitxer.open("puntuacions.txt");

	if (fitxer.is_open())
	{
		Puntuacio p;
		for (; fitxer >> p.jugador >> p.punts; )
			m_puntuacions.push_back(p);
		
		fitxer.close();
	}
}

int Tetris::juga(Screen& pantalla, int mode, const string& fitxerInicial, const string& fitxerFigures, const string& fitxerMoviments)
{
	pantalla.show(); //Mostrem la finestra grafica

	Partida m_partida;

	m_partida.inicialitza(mode, fitxerInicial, fitxerFigures, fitxerMoviments);

	Uint64 NOW = SDL_GetPerformanceCounter();
	Uint64 LAST;
	double deltaTime = 0;

	do
	{
		LAST = NOW;
		NOW = SDL_GetPerformanceCounter();
		deltaTime = (double)((NOW - LAST) / (double)SDL_GetPerformanceFrequency());

		pantalla.processEvents(); // Captura tots els events de ratolí i teclat de l'ultim cicle

		m_partida.actualitza(mode, deltaTime);

		pantalla.update(); // Actualitza la pantalla

	} while (!Keyboard_GetKeyTrg(KEYBOARD_ESCAPE));
	// Sortim del bucle si pressionem ESC
	int punts = m_partida.getPuntuacio();

	return punts;
}

void Tetris::guardaPuntuacio(const string& jugador, int punts)
{
	bool trobat = false;
	list<Puntuacio>::iterator it;
	for (it = m_puntuacions.begin(); it != m_puntuacions.end(); ++it)
		if (it->punts < punts) // Si la puntuacio es mes gran, l'insertem a la llista
		{ 
			trobat = true;
			break;
		}

	Puntuacio p;
	p.jugador = jugador;
	p.punts = punts;
	m_puntuacions.insert(it, p);
	ofstream fitxer;
	fitxer.open("puntuacions.txt");

	for (auto it = m_puntuacions.begin(); it != m_puntuacions.end(); ++it)
		fitxer << it->jugador << " " << it->punts << endl;

	fitxer.close();
}

void Tetris::mostraPuntuacions()
{
	cout << "----------------------------------" << endl;
	cout << "-\t\t\t\t -" << endl;
	cout << "-\tPUNTUACIONS\t\t -" << endl;
	cout << "-\t\t\t\t -" << endl;
	cout << "----------------------------------" << endl;
	cout << endl;

	for (list<Puntuacio>::iterator i = m_puntuacions.begin(); i != m_puntuacions.end(); i++)
		cout << i->jugador << " " << i->punts << endl;
}