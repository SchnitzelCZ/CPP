#pragma once
#ifndef MONSTRUM_H
#define MONSTRUM_H


#include "PohyblivyObjekt.h"
class Monstrum:public PohyblivyObjekt
{
private:
	int hp;
	int maxHp;
public:
	Monstrum(int id);
	~Monstrum();

	void setHp(int hp);
	void setMaxHp(int);

	int getHp();
	int getMaxHp();
};
#endif
