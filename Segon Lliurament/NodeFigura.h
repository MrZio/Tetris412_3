#include <stdlib.h>
#include "InfoJoc.h"
#include "Figura.h"


class NodeFigura
{
public:
    NodeFigura() { m_next = nullptr; };
    ~NodeFigura() {};
    NodeFigura(const Figura& valor) { m_valor = valor; m_next = nullptr; }

    NodeFigura* getNext() { return m_next; }
    void setNext(NodeFigura* next) { m_next = next; }

    Figura getValor() { return m_valor; }
    void setValor(const Figura& valor) { m_valor = valor; }
private:
    Figura m_valor;
    NodeFigura* m_next;
};
