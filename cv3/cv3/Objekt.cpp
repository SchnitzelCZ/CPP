#include "Objekt.h"



Objekt::Objekt(int id)
{
	this->id = id;
}

double Objekt::GetX() const
{
	return this->x;
}

double Objekt::GetY() const
{
	return this->y;
}

int Objekt::GetId() const
{
	return this->id;
}

void Objekt::SetX(double x)
{
	this->x = x;
}

void Objekt::SetY(double y)
{
	this->y = y;
}
