#include "PohyblivyObjekt.h"



PohyblivyObjekt::PohyblivyObjekt(int id) : Objekt(id)
{
}


PohyblivyObjekt::~PohyblivyObjekt()
{
}

double PohyblivyObjekt::GetUhelNatoceni()
{
	return this->uhelNatoceni;
}

void PohyblivyObjekt::SetUhelNatoceni(double k)
{
	double pi = 3.14;
	if (k >= 0 && k <= 2)
	{
		this->uhelNatoceni = (pi * k);
	}
	else
	{
		throw("Nepplatny uhel");
	}
}
