#ifndef UCTENKA_H
#define UCTENKA_H

class Uctenka {
private:
	int cisloUctenky;
	double castka;
	double dph;
public:
	Uctenka() {};
	Uctenka(int isloUctenky, double dph, double castka);

	int getCisloUctenky();
	void setCisloUctenky(int a);
	double getCastka();
	void setCastka(double a);
	double getDph();
	void setDph(double a);

};


#endif