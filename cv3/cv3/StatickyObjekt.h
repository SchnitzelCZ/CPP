#pragma once
#ifndef STATICKY_OBJEKT_H
#define STATICKY_OBJEKT_H


#include "Objekt.h"
#include "TypPrekazky.h"
class StatickyObjekt:public Objekt
{
private:
	TypPrekazky typPrekazky;

public:
	StatickyObjekt(int id, TypPrekazky typPrekazky);
	TypPrekazky GetTypPrekazky();

};

#endif