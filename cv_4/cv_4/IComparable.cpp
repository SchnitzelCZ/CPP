#include "IComparable.h"

int IComparable::compareTo(IComparable * obj) const
{
	if (this->ToString == obj) {
		return 0;
	}else if (this->ToString < obj) {
		return -1;
		}
	else {
		return 1;
		}
}
