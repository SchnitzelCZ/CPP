#ifndef OSOBA_H
#define OSOBA_H

#include <string>
#include <iostream>
#include <fstream>

using namespace std;

struct Datum {
	int _den;
	int _mesic;;
	int _rok;
};
struct Adresa {
	string _ulice;
	string _mesto;
	int _psc;
};
struct Osoba {
	string _jmeno;
	string _prijmeni;
	Adresa _adresa;
	Datum _datumNarozeni;
};

ostream& operator<<(ostream& output, const Datum& aDatum);
istream& operator>>(istream& input, Datum& aDatum);
void saveBinary(ofstream& output, const Datum& aDatum);
void loadBinary(ifstream& input, Datum& aDatum);

ostream& operator<<(ostream& output, const Adresa& aAdresa);
istream& operator>>(istream& input, Adresa& aAdresa);
void saveBinary(ofstream& output, const Adresa& aAdresa);
void loadBinary(ifstream& input, Adresa& aAdresa);

ostream& operator<<(ostream& output, const Osoba& aOsoba);
istream& operator>>(istream& input, Osoba& aOsoba);
void saveBinary(ofstream& output, const Osoba& aOsoba);
void loadBinary(ifstream& input, Osoba& aOsoba);

#endif
