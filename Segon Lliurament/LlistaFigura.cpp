#include "LlistaFigura.h"

LlistaFigura::~LlistaFigura()
{
	while (m_primer != nullptr)
		eliminar();
}

void LlistaFigura::eliminar()
{
	NodeFigura* aux;
	if (m_primer == m_ultim)
	{
		delete m_primer;
		m_primer = nullptr;
		m_ultim = nullptr;
	}
	else
	{
		aux = m_primer->getNext();
		delete m_primer;
		m_primer = aux;
	}
}

NodeFigura* LlistaFigura::afegir(const Figura& fig)
{
	NodeFigura* aux = new NodeFigura;
	if (aux != nullptr)
	{
		aux->setValor(fig);
		aux->setNext(nullptr);
		if (m_primer == nullptr)
			m_primer = aux;
		else
			m_ultim->setNext(aux);
		m_ultim = aux;
	}
	return aux;
}

int LlistaFigura::size() const
{
	int n = 0;
	NodeFigura* aux = m_primer;
	while (aux != nullptr)
	{
		n++;
		aux = aux->getNext();
	}
	return n;
}