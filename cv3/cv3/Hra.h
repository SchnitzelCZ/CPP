#pragma once

#ifndef HRA_H
#define HRA_H

#include "Objekt.h"
#include "PohyblivyObjekt.h"



class Hra
{
public:
	Hra();
	~Hra();

	void vlozObjekt(Objekt* o);
	int* najdiIdStatickychObjektu(double xmin, double xmax, double	ymin, double ymax);
	PohyblivyObjekt** najdiPohybliveObjektyVOblasti(double x, double y, double r);
	PohyblivyObjekt** najdiPohybliveObjektyVOblasti(double x, double y, double r, double umin, double umax);

private:
	Objekt** objekty;
	int pocetObjektu;

};


#endif