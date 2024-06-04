#include "HUD.h"

void HUD::actualitza(double deltaTime, bool gameOver, int punts, int nivell, int bonus)
{
	if (gameOver)
		mostraGameOver(punts,deltaTime);
	else
	{
		mostraPuntuacioNivell(punts, nivell);
		if (m_pujadaNivell)
		{
			m_tempsPujadaNivell += deltaTime;
			mostraPujadaNivell(nivell);
		}
		if (m_FilaEliminada)
		{
			m_tempsFEliminada += deltaTime;
			mostraFilaEliminada(bonus);
		}
	}
}

void HUD::mostraPuntuacioNivell(int punts, int nivell)
{
	string puntuacioText = "Puntuacio: " + to_string(punts);
	string nivellText = "Nivell: " + to_string(nivell);

	GraphicManager::getInstance()->drawFont(FONT_WHITE_30, 120, 50, 0.8, puntuacioText);
	GraphicManager::getInstance()->drawFont(FONT_WHITE_30, 300, 50, 0.8, nivellText);
}

void HUD::mostraPujadaNivell(int nivell)
{
	if (m_tempsPujadaNivell > 2.0)
	{
		m_tempsPujadaNivell = 0;
		m_pujadaNivell = false;
		return;
	}

	GraphicManager::getInstance()->drawFont(FONT_WHITE_30, 62, 1, 1.5, "HAS PUJAT A NIVELL " + to_string(nivell));
}

void HUD::mostraFilaEliminada(int bonus)
{
	if (m_tempsFEliminada > 3.0)
	{
		m_movimentVertical = 0;
		m_tempsFEliminada = 0;
		m_FilaEliminada = false;

		srand(time(nullptr) + chrono::high_resolution_clock::now().time_since_epoch().count()); // Inicialitzar la llavor aleatòriament
		m_posY = rand() % 200; // Assignem una posició aleatòria per la pròxima vegada

		return;
	}

	switch (bonus)
	{
	case 1:
		GraphicManager::getInstance()->drawFont(FONT_WHITE_30, 480, m_posY + 100 + m_movimentVertical, 0.9, "-1 FILA");
		GraphicManager::getInstance()->drawFont(FONT_WHITE_30, 480, m_posY + 140 + m_movimentVertical, 0.8, "+100pts");
		break;
	case 2:
		GraphicManager::getInstance()->drawFont(FONT_GREEN_30, 470, m_posY + 100 + m_movimentVertical, 0.9, "-2 FILES");
		GraphicManager::getInstance()->drawFont(FONT_GREEN_30, 485, m_posY + 140 + m_movimentVertical, 0.8, "+200pts");
		GraphicManager::getInstance()->drawFont(FONT_GREEN_30, 465, m_posY + 180 + m_movimentVertical, 0.6, "BONUS +50pts");
		break;
	case 3:
		GraphicManager::getInstance()->drawFont(FONT_GREEN_30, 470, m_posY + 100 + m_movimentVertical, 0.9, "-3 FILES");
		GraphicManager::getInstance()->drawFont(FONT_GREEN_30, 485, m_posY + 140 + m_movimentVertical, 0.8, "+300pts");
		GraphicManager::getInstance()->drawFont(FONT_GREEN_30, 465, m_posY + 170 + m_movimentVertical, 0.6, "BONUS +75pts");
		break;
	case 4:
		GraphicManager::getInstance()->drawFont(FONT_RED_30, 470, m_posY + 100 + m_movimentVertical, 0.9, "-4 FILES");
		GraphicManager::getInstance()->drawFont(FONT_RED_30, 485, m_posY + 140 + m_movimentVertical, 0.8, "+400pts");
		GraphicManager::getInstance()->drawFont(FONT_RED_30, 461, m_posY + 170 + m_movimentVertical, 0.6, "BONUS +100pts");
		break;
	default:
		break;
	}

	m_movimentVertical += 0.05;
}

void HUD::mostraGameOver(int punts, double deltaTime)
{
	GraphicManager::getInstance()->drawFont(FONT_RED_30, 62, 100, 2.5, "GAME OVER");
	GraphicManager::getInstance()->drawFont(FONT_WHITE_30, 155, 350, 1, "Puntuacio total: " + to_string(punts));

	m_tempsParpadeig += deltaTime;
	if (m_tempsParpadeig > 0.7) // Efecte parpadeig "tornar al menu"
	{
		GraphicManager::getInstance()->drawFont(FONT_WHITE_30, 20, 550, 1, " PREM [ESC] PER TORNAR AL MENU");

		if (m_tempsParpadeig > 1.4) // Quan porti 0.7 segons, torna a apagarse
			m_tempsParpadeig = 0.0;
	}
}