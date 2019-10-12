#include "Pokladna.h"
#include <iostream>
#include <exception>

Pokladna::Pokladna()
{
	citacId = CITAC_ID;
	poleUctenek = new Uctenka[10];
}

Uctenka& Pokladna::vystavUctenku(double castka, double dph)
{
	try {
		if (pocetVydanychUctenek < 10) {
			poleUctenek[pocetVydanychUctenek].setCastka(castka);
			poleUctenek[pocetVydanychUctenek].setCisloUctenky(citacId);
			poleUctenek[pocetVydanychUctenek].setDph(dph);
			pocetVydanychUctenek++;
			citacId++;
			return poleUctenek[pocetVydanychUctenek - 1];
		}
		throw pocetVydanychUctenek;
	}
	catch (int pocetVydanychUctenek) {
		std::cout << "Maximum uctenek dosazeno" << std::endl;
	}
}

void Pokladna::vypisUctenku(int x)
{
	std::cout << "ID: " << poleUctenek[x].getCisloUctenky()
		<< ", Castka: " << poleUctenek[x].getCastka()
		<< ", DPH: " << poleUctenek[x].getDph() << std::endl;
}

Uctenka& Pokladna::dejUctenku(int x) {
	for (size_t i = 0; i < pocetVydanychUctenek; i++)
	{
		int tmp = poleUctenek[i].getCisloUctenky();
		if (tmp == x) {
			return poleUctenek[i];
		}
		else {
			return poleUctenek[0];
		}
	}
	throw std::out_of_range("Neexistuje");
}

double Pokladna::dejCastku() const
{
	double sum = 0.0;
	for (size_t i = 0; i < sizeof(Pokladna::poleUctenek) / sizeof(Pokladna::poleUctenek[0]); i++)
	{
		if (poleUctenek[i].getCastka() != 0) {
			sum += poleUctenek[i].getCastka();
		}

	}
	return sum;

}

double Pokladna::dejCastkuVcDph() const
{
	double sum = 0.0;
	for (size_t i = 0; i < sizeof(Pokladna::poleUctenek) / sizeof(Pokladna::poleUctenek[0]); i++)
	{
		if (poleUctenek[i].getCastka() != 0) {
			sum += poleUctenek[i].getCastka() * (1 + poleUctenek[i].getDph());
		}

	}
	return sum;

}