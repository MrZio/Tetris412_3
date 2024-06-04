#include <stdlib.h>
#include "InfoJoc.h"


class NodeMoviment
{
public:
    NodeMoviment() : m_next(nullptr) {}
	~NodeMoviment() {};
    NodeMoviment(const TipusMoviment& valor) {m_valor = valor; m_next = nullptr;}
    
    NodeMoviment* getNext() { return m_next; }
    void setNext(NodeMoviment* next) { m_next = next; }

    TipusMoviment getValor() { return m_valor; }
    void setValor(const TipusMoviment& valor) { m_valor = valor; }
private:
    TipusMoviment m_valor;
    NodeMoviment* m_next;
};


