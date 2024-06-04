#include "Partida.h"
#include "InfoJoc.h"

void Partida::inicialitza(int mode, const string& fitxerInicial, const string& fitxerFigures, const string& fitxerMoviments)
{
	if (mode == 0)
		m_gameOver = m_joc.novaFigura();
	else
	{
		m_joc.inicialitza(fitxerInicial);
		guardaLlistatFigures(fitxerFigures);
		guardaLlistatMoviments(fitxerMoviments);
	}

	m_gameOver = false;
}

void Partida::guardaLlistatFigures(const string& fitxerFigures)
{
	ifstream fitxer;
	fitxer.open(fitxerFigures);
	if (fitxer.is_open())
	{
		Figura figuratemp;
		int tipus, fila, columna, gir;
		fitxer >> tipus >> fila >> columna >> gir;
		figuratemp = Figura(TipusFigura(tipus), fila, columna, gir);

		while (!fitxer.eof())
		{
			m_figures.afegir(figuratemp);
			fitxer >> tipus >> fila >> columna >> gir;
			figuratemp = Figura(TipusFigura(tipus), fila, columna, gir);
		}
		fitxer.close();
	}
}

void Partida::guardaLlistatMoviments(const string& fitxerMoviments)
{
	ifstream fitxer;
	fitxer.open(fitxerMoviments);
	if (fitxer.is_open())
	{
		int tipus;
		fitxer >> tipus;
		while (!fitxer.eof())
		{
			m_moviments.afegir(TipusMoviment(tipus));
			fitxer >> tipus;
		}
		fitxer.close();
	}
}

void Partida::actualitza(int mode, double deltaTime)
{
	if (!m_gameOver)
	{
		if (mode == 0)
			actualitzaNormal(deltaTime);
		else
			actualitzaTest(deltaTime);
	}
	GraphicManager::getInstance()->drawSprite(GRAFIC_FONS, 0, 0, false); // Dibuixem tot negre
	m_joc.dibuixa();

	m_hud.actualitza(deltaTime, m_gameOver, m_punts, m_nivell, m_bonus); // Mostra nivell actual, puntuacio actual, pujada de nivell, num de files eliminades i pantalla game over
}

void Partida::actualitzaNormal(float deltaTime)
{
	int nFilesEliminades = -1;

	if (Keyboard_GetKeyTrg(KEYBOARD_RIGHT) || Keyboard_GetKeyTrg(KEYBOARD_D)) // Mou la figura
		m_joc.mouFigura(1);
	else
		if (Keyboard_GetKeyTrg(KEYBOARD_LEFT) || Keyboard_GetKeyTrg(KEYBOARD_A))
			m_joc.mouFigura(-1);

	if (Keyboard_GetKeyTrg(KEYBOARD_UP) || Keyboard_GetKeyTrg(KEYBOARD_W)) // Gira la figura
		m_joc.giraFigura(GIR_HORARI);
	else
		if (Keyboard_GetKeyTrg(KEYBOARD_DOWN) || Keyboard_GetKeyTrg(KEYBOARD_S))
			m_joc.giraFigura(GIR_ANTI_HORARI);

	if (Keyboard_GetKeyTrg(KEYBOARD_E)) // La figura va cap al costat fins que no pot més
		while (m_joc.mouFigura(1));
	else
		if (Keyboard_GetKeyTrg(KEYBOARD_Q))
			while (m_joc.mouFigura(-1));

	if (Keyboard_GetKeyTrg(KEYBOARD_SPACE)) // La figura baixa fins al final
	{
		while (nFilesEliminades == -1)
			nFilesEliminades = m_joc.baixaFigura();

		actualitzaPuntuacio(nFilesEliminades);
		m_gameOver = m_joc.novaFigura();
		m_temps = 0.0;
	}
	else // Si no es prem cap tecla, la figura baixa cada cert temps
	{
		m_temps += deltaTime;
		if (m_temps > m_velocitat)
		{
			m_temps = 0.0;
			nFilesEliminades = m_joc.baixaFigura();
			if (nFilesEliminades != -1)
			{
				actualitzaPuntuacio(nFilesEliminades);
				m_gameOver = m_joc.novaFigura();
			}
		}
	}
}

void Partida::actualitzaTest(float deltaTime)
{
	int nFilesEliminades = -1;

	m_temps += deltaTime;
	if (m_temps > m_velocitat)
	{
		m_temps = 0.0;
		if (m_moviments.size() > 0)
		{
			TipusMoviment moviment = m_moviments.getPrimer();
			switch (moviment)
			{
			case MOVIMENT_DRETA:
				m_joc.mouFigura(1);
				break;
			case MOVIMENT_ESQUERRA:
				m_joc.mouFigura(-1);
				break;
			case MOVIMENT_GIR_HORARI:
				m_joc.giraFigura(GIR_HORARI);
				break;
			case MOVIMENT_GIR_ANTI_HORARI:
				m_joc.giraFigura(GIR_ANTI_HORARI);
				break;
			case MOVIMENT_BAIXA_FINAL:
			{
				while (nFilesEliminades == -1)
					nFilesEliminades = m_joc.baixaFigura();

				actualitzaPuntuacio(nFilesEliminades);

				if (m_figures.size() > 0)
				{
					m_temps = 0.0;
					Figura figura = m_figures.getPrimer();
					m_figures.eliminar();
					m_joc.novaFigura(figura);
				}
				else
					m_gameOver = true;
				break;
			}
			case MOVIMENT_BAIXA:
			{
				int nFilesEliminades = m_joc.baixaFigura();
				if (nFilesEliminades > 0)
				{
					actualitzaPuntuacio(nFilesEliminades);
					if (m_figures.size() > 0)
					{
						Figura figura = m_figures.getPrimer();
						m_figures.eliminar();
						m_joc.novaFigura(figura);
					}
					else
						m_gameOver = true;
				}
				break;
			}
			}
			m_moviments.eliminar();
		}
		else
			m_gameOver = true;
	}
}

void Partida::actualitzaPuntuacio(int nFilesEliminades)
{
	if (nFilesEliminades == 0)
		m_punts += 10;
	else
	{
		m_hud.setFilaEliminada(true);
		switch (nFilesEliminades) // Hi ha bonificacio per eliminar més d'una fila
		{
		case 1:
			m_punts += 100;
			m_bonus = 1;
			break;
		case 2:
			m_punts += 200 + 50;
			m_bonus = 2;
			break;
		case 3:
			m_punts += 300 + 75;
			m_bonus = 3;
			break;
		case 4:
			m_punts += 400 + 100;
			m_bonus = 4;
			break;
		}
	}

	if (m_punts >= (m_nivell * 1000)) // Cada 1000 punts, augmentem el nivell
	{
		m_nivell++;
		m_velocitat -= 0.1;
		m_hud.setPujadaNivell(true);
	}
}