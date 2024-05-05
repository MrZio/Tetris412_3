#ifndef TAULER_H
#define TAULER_H
#include "Figura.h"

const int MAX_FILA = 8;
const int MAX_COL = 8;

class Tauler {
public:
    Tauler() { crearTauler(); }
    ~Tauler() {}
    void crearTauler(const int &fila = -1, const string &linia = "");
    bool movientValid_H(const Figura *figura, bool dreta = true);
    bool movientValid_V(const Figura *figura);
    bool girValid(const Figura *figura, DireccioGir &direccio);
    int setTauler(Figura *figura);
    void mostraTauler();
    int getCurrentFila() const { return m_currentFila; }
    void setCurrentFila(const int &currentFila) { m_currentFila = currentFila; }
    int getCelaTauler(const int &fila, const int &columna) const { return m_tauler[fila][columna]; }
    void setCelaTauler(const int &fila, const int &columna, const int &color) { m_tauler[fila][columna] = color; }
private:
    vector<int> filesCompletes();
    int borrarFilesCompletes();
    int m_currentFila = -1;
    int m_tauler[MAX_FILA][MAX_COL];
};
#endif // TAULER_H
