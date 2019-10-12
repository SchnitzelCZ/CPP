#include "Uctenka.h"

Uctenka::Uctenka(int receiptNumber, double dph, double amount)
{
	Uctenka::castka = amount;
	Uctenka::cisloUctenky = receiptNumber;
	Uctenka::dph = dph;
}

void Uctenka::setCisloUctenky(int a)
{
	cisloUctenky = a;
}

void Uctenka::setCastka(double a)
{
	castka = a;
}

void Uctenka::setDph(double a)
{
	dph = a;
}

int Uctenka::getCisloUctenky()
{
	return cisloUctenky;
}

double Uctenka::getCastka()
{
	return castka;
}

double Uctenka::getDph()
{
	return dph;
}