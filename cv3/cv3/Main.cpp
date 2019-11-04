#include "Hra.h"
#include "Monstrum.h"
#include "Objekt.h"
#include "PohyblivyObjekt.h"
#include "StatickyObjekt.h"
#include "TypPrekazky.h"
#include <random>
#include <iostream>

int main()
{
	Hra *hra = new Hra();
	int x; 
	int y;


	std::random_device dev;
	std::mt19937 rng(dev());
	std::uniform_int_distribution<std::mt19937::result_type> dist6(1, 6);

	for (int i = 0; i < 4; i++)
	{
		x = dist6(rng);
		y = dist6(rng);
		PohyblivyObjekt * tmpObj = new PohyblivyObjekt(i);
		tmpObj->SetX(x);
		tmpObj->SetY(y);
		hra->vlozObjekt(tmpObj);
	}
	for (int i = 0; i < 4; i++)
	{
		x = dist6(rng);
		y = dist6(rng);
		StatickyObjekt * tmpObj = new StatickyObjekt(i, TypPrekazky::VelkaRostlina);
		tmpObj->SetX(x);
		tmpObj->SetY(y);
		hra->vlozObjekt(tmpObj);
	}
	for (int i = 0; i < 4; i++)
	{
		x = dist6(rng);
		y = dist6(rng);
		Objekt * tmpObj = new Objekt(i);
		tmpObj->SetX(x);
		tmpObj->SetY(y);
		hra->vlozObjekt(tmpObj);
	}
	
	system("pause");
}