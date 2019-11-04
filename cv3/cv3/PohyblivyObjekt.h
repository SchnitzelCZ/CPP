#pragma once
#ifndef POHYBLIVY_OBJEKT_H
#define POHYBLIVY_OBJEKT_H


#include "Objekt.h"

class PohyblivyObjekt:public Objekt
{
private: 
	double uhelNatoceni;

public:
	PohyblivyObjekt(int id);
	~PohyblivyObjekt();

	double GetUhelNatoceni();
	void SetUhelNatoceni(double uhel);
};

#endif