#include "Osoba.h"


Entity::Osoba::Osoba(std::string jmeno, std::string telefon, int id)
{
	this->jmeno = jmeno;
	this->telefon = telefon;
	this->id = id;
}

Entity::Osoba::~Osoba()
{
}

int Entity::Osoba::getID()
{
	return this->id;
}

std::string Entity::Osoba::getJmeno()
{
	return this->jmeno;
}

std::string Entity::Osoba::getTelefon()
{
	return this->telefon;
}

