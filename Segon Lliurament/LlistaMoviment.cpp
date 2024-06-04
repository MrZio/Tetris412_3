#include "LlistaMoviment.h"

LlistaMoviment::~LlistaMoviment()
{
	while (m_primer != nullptr)
		eliminar();
}

void LlistaMoviment::eliminar()
{
	NodeMoviment* aux;
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

NodeMoviment* LlistaMoviment::afegir(const TipusMoviment& mov)
{
	NodeMoviment* aux = new NodeMoviment;
	if (aux != nullptr)
	{
		aux->setValor(mov);
		aux->setNext(nullptr);
		if (m_primer == nullptr)
		{
			m_primer = aux;
		}
		else
		{
			m_ultim->setNext(aux);
		}
		m_ultim = aux;
	}

	return aux;
}

int LlistaMoviment::size() const
{
	int n = 0;
	NodeMoviment* aux = m_primer;
	while (aux != nullptr)
	{
		n++;
		aux = aux->getNext();
	}
	return n;
}