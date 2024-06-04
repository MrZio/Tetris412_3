#include "NodeFigura.h"

class LlistaFigura
{
public:
	LlistaFigura() { m_primer = nullptr; m_ultim = nullptr; }
	~LlistaFigura();

	void eliminar();
	NodeFigura* afegir(const Figura& fig);

	Figura getPrimer() const { return m_primer->getValor(); }

	int size() const;
private:
	NodeFigura* m_primer;
	NodeFigura* m_ultim;
};