#ifndef POKLADNA_H
#define POKLADNA_H

#include "Uctenka.h"

#define CITAC_ID 1000

class Pokladna {
public:
	Pokladna();

	Uctenka& vystavUctenku(double, double);
	void vypisUctenku(int);
	Uctenka& dejUctenku(int);
	double dejCastku() const;
	double dejCastkuVcDph() const;

private:
	int  citacId;
	Uctenka *poleUctenek;
	int pocetVydanychUctenek = 0;



};

#endif