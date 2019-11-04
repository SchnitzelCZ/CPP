#include "Cas.h"
#include <iostream>

Cas::Cas(int hodiny, int minuty, int sekundy)
{
	this->_hodiny = hodiny;
	this->_minuty = minuty;
	this->_sekundy = sekundy;
}


Cas::~Cas()
{
}

int Cas::compareTo(IComparable * obj) const
{

	int casL = this->_hodiny * 3600 + this->_minuty * 60 + this->_sekundy;
	int casP = ((Cas*)obj)->_hodiny * 3600 + ((Cas*)obj)->_minuty * 60 + ((Cas*)obj)->_sekundy;
	int cislo = -2;
	if (casL == casP) {
		cislo = 0;
	}
	else if (casL < casP) {
		cislo = -1;
	}
	else if (casL > casP) {
		cislo = 1;
	}
	return cislo;
}

std::string Cas::ToString() const
{
	std::cout << _hodiny << " hours " << _minuty << " minutes " << _sekundy << " seconds " << std::endl;
	return "toString Cas";
}

void Cas::SeraditPole(IComparable ** arr, int arraySize)
{
}
