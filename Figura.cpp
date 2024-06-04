#include "Figura.h"

Figura::Figura()
{
    m_tipus = NO_FIGURA;
    m_posicio[0] = 0;
    m_posicio[1] = 0;  
    m_gir = 0;
    m_color = NO_COLOR;

    for (int i = 0; i < MAX_ALCADA; i++) {
        for (int j = 0; j < MAX_AMPLADA; j++) {
            m_matriz[i][j] = ' ';
        }
    }
}

void Figura::figuraToMatriz()
{
    for (int i = 0; i < MAX_ALCADA; i++) // Inicialitzar la matriu a buida
    {
        for (int j = 0; j < MAX_AMPLADA; j++)
            m_matriz[i][j] = ' ';
    }

    switch (m_tipus)
        {
            case FIGURA_J:
                m_matriz[0][0] = 'X';
                m_matriz[1][0] = 'X';
                m_matriz[1][1] = 'X';
                m_matriz[1][2] = 'X';
                break;
            case FIGURA_L:
                m_matriz[0][2] = 'X';
                m_matriz[1][0] = 'X';
                m_matriz[1][1] = 'X';
                m_matriz[1][2] = 'X';
                break;
            case FIGURA_T:
                m_matriz[0][1] = 'X';
                m_matriz[1][2] = 'X';
                m_matriz[1][0] = 'X';
                m_matriz[1][1] = 'X';
                break;
            case FIGURA_S:
                m_matriz[0][1] = 'X';
                m_matriz[0][2] = 'X';
                m_matriz[1][0] = 'X';
                m_matriz[1][1] = 'X';
                break;
            case FIGURA_Z:
                m_matriz[0][0] = 'X';
                m_matriz[0][1] = 'X';
                m_matriz[1][1] = 'X';
                m_matriz[1][2] = 'X';
                break;
            case FIGURA_I:
                m_matriz[1][0] = 'X';
                m_matriz[1][1] = 'X';
                m_matriz[1][2] = 'X';
                m_matriz[1][3] = 'X';
                break;
            case FIGURA_O:
                m_matriz[0][0] = 'X';
                m_matriz[0][1] = 'X';
                m_matriz[1][0] = 'X';
                m_matriz[1][1] = 'X';
                break;
            default: // Si no és una figura coneguda, la matriu segueix buida
                break;
        }
}

ColorFigura Figura::asignarColor(TipusFigura tipus)
{
        switch (tipus) {
            case FIGURA_O:
                return COLOR_GROC;
            case FIGURA_I:
                return COLOR_BLAUCEL;
            case FIGURA_T:
                return COLOR_MAGENTA;
            case FIGURA_L:
                return COLOR_TARONJA;
            case FIGURA_J:
                return COLOR_BLAUFOSC;
            case FIGURA_Z:
                return COLOR_VERMELL;
            case FIGURA_S:
                return COLOR_VERD;
            default:
                return NO_COLOR;
        }
    }

void Figura::getMatriz(char matriz[MAX_ALCADA][MAX_AMPLADA]) const 
{
    for (int i = 0; i < MAX_ALCADA; i++) // Copiar la matriu interna a la matriu passada per paràmetre
    {
        for (int j = 0; j < MAX_AMPLADA; j++)
            matriz[i][j] = m_matriz[i][j];
    }
}

bool Figura::detectarI()
{
	int num = 0;
	for (int i = 0; i < MAX_ALCADA; i++) // Si la figura te tota la fila plena, es una I
	{
		num = 0;
		for (int j = 0; j < MAX_AMPLADA; j++)
		{
			if (m_matriz[i][j] == 'X')
				num++;
		}
		if (num == 4)
			return true;
	}
	for (int i = 0; i < MAX_ALCADA; i++) // Si la figura te tota la columna plena, es una I
	{
		num = 0;
		for (int j = 0; j < MAX_AMPLADA; j++)
		{
			if (m_matriz[j][i] == 'X')
				num++;
		}
		if (num == 4)
			return true;
	}
	return false;
}

void Figura::giraFigura(const DireccioGir dgir)
{
	bool formaI = detectarI();

    for (int x = 0; x < 3; x++)
    {
    	char temp[MAX_ALCADA][MAX_AMPLADA];

        for (int i = 0; i < MAX_ALCADA; i++) // Transposar la matriu (intercanviar files i columnes)
        {
            for (int j = 0; j < MAX_AMPLADA; j++)
                temp[j][i] = m_matriz[i][j];
        }

        for (int fila = 0; fila < MAX_ALCADA; fila++) { // Invertir columnes per girar cap a la dreta
			int start = 0; // 0 o 1
			int end = MAX_AMPLADA - 1; // 3 o 2
			while (start < end) // Intercambi de columna
            {
				char tempValor = temp[fila][start];
				temp[fila][start] = temp[fila][end];
				temp[fila][end] = tempValor;
				start++;
				end--;
			}
		}

        if (!formaI) // Movemm la matriu ja que ha quedat a la dreta:
        {
        	char final[MAX_ALCADA][MAX_AMPLADA];
			for (int i = 0; i < MAX_ALCADA; i++)
            {
				final[i][3] = temp[i][0];
				final[i][0] = temp[i][1];
				final[i][1] = temp[i][2];
				final[i][2] = temp[i][3];
			}

			for (int i = 0; i < MAX_ALCADA; i++) // Copiar la matriu temporal de tornada a la matriu original
			{
				for (int j = 0; j < MAX_AMPLADA; j++)
					m_matriz[i][j] = final[i][j];
			}
        }
        else // Si es una I, no s'ha de moure
        {
        	for (int i = 0; i < MAX_ALCADA; i++)
			{
				for (int j = 0; j < MAX_AMPLADA; j++)
					m_matriz[i][j] = temp[i][j];
			}
        }
        if (dgir == GIR_HORARI)
            	break;
    }
}

Figura& Figura::operator=(const Figura& f)
{
    if (&f != this)
	{
	
        for (int i = 0; i < MAX_ALCADA; i++)
        {
            for (int j = 0; j < MAX_AMPLADA; j++)
                m_matriz[i][j] = f.m_matriz[i][j];
        }
        m_posicio[0] = f.m_posicio[0];
        m_posicio[1] = f.m_posicio[1];
        m_gir = f.m_gir;
        m_color = f.m_color;
    }
    return *this;
}
