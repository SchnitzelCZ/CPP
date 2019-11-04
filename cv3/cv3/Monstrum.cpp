#include "Monstrum.h"



Monstrum::Monstrum(int id) : PohyblivyObjekt(id)
{
}


Monstrum::~Monstrum()
{
}

void Monstrum::setHp(int)
{
	this->hp = hp;
}

void Monstrum::setMaxHp(int maxHP)
{
	this->maxHp = maxHP;
}

int Monstrum::getHp()
{
	return this->hp;
}

int Monstrum::getMaxHp()
{
	return this->maxHp;
}
