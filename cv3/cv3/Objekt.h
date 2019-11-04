#pragma once
#ifndef OBJEKT_H
#define OBJEKT_H


class Objekt
{
private: 
	int id;
	double x;
	double y;

public:
	Objekt(int id);
	virtual ~Objekt();

	double GetX() const;
	double GetY() const;
	int GetId() const;

	void SetX(double x);
	void SetY(double y);
};

#endif