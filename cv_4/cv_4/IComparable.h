#ifndef I_COMPARABLE_H
#define I_COMPARABLE_H

#include "IObject.h"

class IComparable : public IObject
{
public:
	virtual int compareTo(IComparable* obj) const;

};
#endif
