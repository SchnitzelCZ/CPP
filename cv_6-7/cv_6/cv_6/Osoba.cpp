#include "Osoba.h"
using namespace std;
ostream & operator<<(ostream & output, const Datum & aDatum)
{
	output << aDatum._den << "\n" << aDatum._mesic << "\n" << aDatum._rok << endl;
	return output;
}

istream & operator>>(istream & input, Datum & aDatum)
{
	input >> aDatum._den;
	input >> aDatum._mesic;
	input >> aDatum._rok;
	return input;

}

void saveBinary(ofstream & output, const Datum & aDatum)
{
	output.write((const char*)&aDatum._den, sizeof(int));
	output.write((const char*)&aDatum._mesic, sizeof(int));
	output.write((const char*)&aDatum._rok, sizeof(int));
}

void loadBinary(ifstream & input, Datum & aDatum)
{
	input.read((char*)&aDatum._den, sizeof(int));
	input.read((char*)&aDatum._mesic, sizeof(int));
	input.read((char*)&aDatum._rok, sizeof(int));
}

ostream & operator<<(ostream & output, const Adresa & aAdresa)
{
	output << aAdresa._ulice << "\n" << aAdresa._mesto << "\n" << aAdresa._psc << endl;
	return output;
}

istream & operator>>(istream & input, Adresa & aAdresa)
{
	input >> aAdresa._ulice;
	input >> aAdresa._mesto;
	input >> aAdresa._psc;
	return input;

}

void saveBinary(ofstream & output, const Adresa & aAdresa)
{
	size_t size = aAdresa._mesto.size();

	output.write((const char*)&size, sizeof(size));
	output.write(&aAdresa._mesto[0], size);


	size = aAdresa._ulice.size();
	output.write((const char*)&size, sizeof(int));
	output.write((const char*)aAdresa._ulice[0], size);

	output.write((const char*)&aAdresa._psc, sizeof(int));
}

void loadBinary(ifstream & input, Adresa & aAdresa)
{
	std::string str;
	size_t size;

	input.read((char*)&size, sizeof(size));
	str.resize(size);
	input.read(&str[0], size);
	aAdresa._mesto.append(&str[0], size);

	input.read((char*)&size, sizeof(size));
	str.resize(size);
	input.read(&str[0], size);
	aAdresa._mesto.append(&str[0], size);

	input.read((char*) & (aAdresa._psc), sizeof(int));
}

ostream & operator<<(ostream & output, const Osoba & aOsoba)
{
	output << aOsoba._jmeno << "\n" << aOsoba._prijmeni << "\n" << aOsoba._adresa << "\n" << aOsoba._datumNarozeni << "\n" << endl;
	return output;

}

istream & operator>>(istream & input, Osoba & aOsoba)
{
	input >> aOsoba._jmeno;
	input >> aOsoba._prijmeni;
	input >> aOsoba._adresa;
	input >> aOsoba._datumNarozeni;
	return input;

}

void saveBinary(ofstream & output, const Osoba & aOsoba)
{
	size_t size = aOsoba._jmeno.size();
	output.write((const char*)&size, sizeof(size));
	output.write(&aOsoba._jmeno[0], size);

	size = aOsoba._prijmeni.size();
	output.write((const char*)&size, sizeof(size));
	output.write(&aOsoba._prijmeni[0], size);

	output << aOsoba._adresa;
	output << aOsoba._datumNarozeni;
}

void loadBinary(ifstream & input, Osoba & aOsoba)
{
	std::string str;
	size_t size;

	input.read((char*)&size, sizeof(size));
	str.resize(size);
	input.read(&str[0], size);
	aOsoba._jmeno.append(&str[0], size);

	input.read((char*)&size, sizeof(size));
	str.resize(size);
	input.read(&str[0], size);
	aOsoba._prijmeni.append(&str[0], size);

	input >> aOsoba._adresa;
	input >> aOsoba._datumNarozeni;
}
