#include "Figura.h"

void Figura::figuraToMatriz()
{
     // Limpia la matriz manualmente
    for (int i = 0; i < MAX_ALCADA; i++)
    {
        for (int j = 0; j < MAX_AMPLADA; j++)
        {
            m_matriz[i][j] = ' ';
        }
    }

    switch (m_tipus)
    {
        case FIGURA_J:
            m_matriz[0][1] = 'X';
            m_matriz[1][1] = 'X';
            m_matriz[1][2] = 'X';
            m_matriz[1][3] = 'X';
            break;

        case FIGURA_L:
            m_matriz[0][3] = 'X';
            m_matriz[1][1] = 'X';
            m_matriz[1][2] = 'X';
            m_matriz[1][3] = 'X';
            break;

        case FIGURA_T:
            m_matriz[0][2] = 'X';
            m_matriz[1][1] = 'X';
            m_matriz[1][2] = 'X';
            m_matriz[1][3] = 'X';
            break;

        case FIGURA_S:
            m_matriz[0][2] = 'X';
            m_matriz[0][3] = 'X';
            m_matriz[1][1] = 'X';
            m_matriz[1][2] = 'X';
            break;

        case FIGURA_Z:
            m_matriz[0][1] = 'X';
            m_matriz[0][2] = 'X';
            m_matriz[1][2] = 'X';
            m_matriz[1][3] = 'X';
            break;

        case FIGURA_I:
            m_matriz[1][0] = 'X';
            m_matriz[1][1] = 'X';
            m_matriz[1][2] = 'X';
            m_matriz[1][3] = 'X';
            break;

        case FIGURA_O:
            m_matriz[0][2] = 'X';
            m_matriz[0][3] = 'X';
            m_matriz[1][2] = 'X';
            m_matriz[1][3] = 'X';
            break;

        default:
            // Si no és una figura coneguda, la matriu segueix buida
            break;
    }
}

void Figura::getMatriz(char matriz[MAX_ALCADA][MAX_AMPLADA]) const 
{
    // Copia la matriz interna en el parámetro proporcionado
    for (int i = 0; i < MAX_ALCADA; i++)
    {
        for (int j = 0; j < MAX_AMPLADA; j++)
        {
            matriz[i][j] = m_matriz[i][j];
        }
    }
}

void Figura::giraFigura()
{
    if (m_tipus == FIGURA_O) // La figura quadrada no gira
        return;

    char temp[MAX_ALCADA][MAX_AMPLADA];

    // Transposar la matriu (intercanviar files i columnes)
    for (int i = 0; i < MAX_ALCADA; i++)
    {
        for (int j = 0; j < MAX_AMPLADA; j++)
        {
            temp[j][i] = m_matriz[i][j];
        }
    }

    // Invertir columnes per girar cap a la dreta
    for (int i = 0; i < MAX_ALCADA; i++) {
        int start = 0; // 0 o 1
        int end = MAX_AMPLADA - 1; // 3 o 2
        while (start < end) {
            char temporal = temp[i][start];  // Guarda el valor inicial
            temp[i][start] = temp[i][end];  // Asigna el valor final a l'inicial
            temp[i][end] = temporal;  // Asigna el valor temporal al final
            start++;
            end--;
        }
    }

    // Puixem la matriu ja que ha quedat baixada:

    // Creem un array temporal per desar la fila 0
    char tempFila[4];
    // Copiem la fila 0 a la matriu temporal
    for (int i = 0; i < 4; ++i) {
        tempFila[i] = temp[0][i];
    }

    // Realitzem els moviments de fila
    // Fila 1 a la fila 0
    for (int i = 0; i < 4; ++i) {
        temp[0][i] = temp[1][i];
    }
    // Fila 2 a la fila 1
    for (int i = 0; i < 4; ++i) {
        temp[1][i] = temp[2][i];
    }
    // Fila 3 a la fila 2
    for (int i = 0; i < 4; ++i) {
        temp[2][i] = temp[3][i];
    }
    // Fila temporal a la fila 3
    for (int i = 0; i < 4; ++i) {
        temp[3][i] = tempFila[i];
    }

    // Copiar la matriu temporal de tornada a la matriu original
    for (int i = 0; i < MAX_ALCADA; i++) {
        for (int j = 0; j < MAX_AMPLADA; j++) {
            m_matriz[i][j] = temp[i][j];
        }
    }

}