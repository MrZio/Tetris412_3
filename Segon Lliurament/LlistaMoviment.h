#include "NodeMoviment.h"

class LlistaMoviment
{
public:
	LlistaMoviment() { m_primer = nullptr; m_ultim = nullptr; }
	~LlistaMoviment();

	void eliminar();
	NodeMoviment* afegir(const TipusMoviment& mov);

	TipusMoviment getPrimer() const { return m_primer->getValor(); }

	int size() const;
private:
	NodeMoviment* m_primer;
	NodeMoviment* m_ultim;
};