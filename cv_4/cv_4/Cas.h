#ifndef CAS_H
#define CAS_H

#include "IComparable.h"
class Cas : public IComparable
{
public:
	Cas(int _h, int _m, int _s);
	~Cas();

	int compareTo(IComparable* obj) const override;

	std::string ToString() const override;

	void SeraditPole(IComparable** pole, int velikostPole);


private:
	int _hodiny;
	int _minuty;
	int _sekundy;

};


#endif