#include <iostream>

#include "Uctenka.h"
#include "Pokladna.h"

using namespace std;


int main()
{
	Pokladna* tmp = new Pokladna();

	tmp->vystavUctenku(532, 21);
	tmp->vystavUctenku(88, 44);
	tmp->vystavUctenku(42, 10);
	tmp->vystavUctenku(87, 15);
	tmp->vystavUctenku(1002, 12);
	tmp->vystavUctenku(666, 13);

	Uctenka& temp = tmp->dejUctenku(1001);

	tmp->vypisUctenku(0);
	tmp->vypisUctenku(1);
	tmp->vypisUctenku(2);
	tmp->vypisUctenku(3);
	tmp->vypisUctenku(4);
	tmp->vypisUctenku(5);

	system("pause");

}