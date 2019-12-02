#include "Hra.h"
#include "StatickyObjekt.h"
#include "PohyblivyObjekt.h"
#include <math.h>


Hra::Hra()
{
	this->objekty = new Objekt*[0];
	this->pocetObjektu = 0;
}


Hra::~Hra()
{
	for (int i = 0; i <= pocetObjektu; i++) {
		delete objekty[i];
	}
	delete[] objekty;
}

void Hra::vlozObjekt(Objekt * o)
{
	Objekt** tempObject = new Objekt *[pocetObjektu + 1];
	for (int idx = 0; idx < pocetObjektu; idx++) {
		tempObject[idx] = objekty[idx];
	}
	tempObject[pocetObjektu++] = o;

	if (objekty != nullptr)
		delete[] objekty;
	objekty = tempObject;
}

int * Hra::najdiIdStatickychObjektu(double xmin, double xmax, double ymin, double ymax)
{
	int foundObjectCount = 0;
	for (int i = 0; i <= pocetObjektu; i++) {
		if (dynamic_cast<StatickyObjekt*>(objekty[i]) != nullptr)
			foundObjectCount++;
	}
	if (foundObjectCount == 0)
		return nullptr;

	int* poleID = new int[foundObjectCount];
	int pocetIDulozeno = 0;
	for (int i = 0; i < pocetObjektu; i++) {
		if (objekty[i]->GetX >= xmin && objekty[i]->GetX <= xmax && objekty[i]->GetY >= ymin && objekty[i]->GetY <= ymax) {
			if (dynamic_cast<StatickyObjekt*>(objekty[i]) != nullptr) {
				poleID[pocetIDulozeno] = objekty[i]->GetId; 
				pocetIDulozeno++;
			}
			
		}
	}
	return poleID;
}

PohyblivyObjekt ** Hra::najdiPohybliveObjektyVOblasti(double x, double y, double r)
{


	int foundObjectCount = 0;
	for (int i = 0; i <= pocetObjektu; i++) {
		if (dynamic_cast<PohyblivyObjekt*>(objekty[i]) != nullptr)
			foundObjectCount++;
	}
	if (foundObjectCount == 0)
		return nullptr;

	Objekt** pole = new Objekt*[foundObjectCount];
	int pocetIDulozeno = 0;
	for (int i = 0; i <= pocetObjektu; i++) {
		if (objekty[i]->GetX() >= (x-r) && objekty[i]->GetX() <= (x+r) && objekty[i]->GetY() >= (y-r) && objekty[i]->GetY() <= (y+r)) {
			if (dynamic_cast<PohyblivyObjekt*>(objekty[i]) != nullptr) {
				pole[pocetIDulozeno] = objekty[i];
				pocetIDulozeno++;
			}

		}
	}
	return (PohyblivyObjekt**)pole;
}

PohyblivyObjekt ** Hra::najdiPohybliveObjektyVOblasti(double x, double y, double r, double umin, double umax)
{/**
	Objekt** pole = new Objekt*[pocetObjektu];
	int pocetIDulozeno = 0;
	for (int i = 0; i <= pocetObjektu; i++) {
		if (objekty[i]->GetX >= (x - r) && objekty[i]->GetX <= (x + r) && objekty[i]->GetY >= (y - r) && objekty[i]->GetY <= (y + r)) {
			if (dynamic_cast<PohyblivyObjekt*>(objekty[i]) != nullptr && dynamic_cast<PohyblivyObjekt*>(objekty[i])->GetUhelNatoceni() >= umin && dynamic_cast<PohyblivyObjekt*>(objekty[i])->GetUhelNatoceni() <= umax) {
				pole[pocetIDulozeno] = objekty[i];
				pocetIDulozeno++;
			}

		}
		return (PohyblivyObjekt**)pole;*/
}
