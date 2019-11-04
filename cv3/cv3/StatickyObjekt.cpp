#include "StatickyObjekt.h"



StatickyObjekt::StatickyObjekt(int id, TypPrekazky prekazka) :Objekt(id)
{
	this->typPrekazky = prekazka;
}

TypPrekazky StatickyObjekt::GetTypPrekazky()
{
	return this->typPrekazky;
}



