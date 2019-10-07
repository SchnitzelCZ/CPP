#include "trojuhelnik.h"

int main()
{

	int pocet = 0;
	Trojuhelnik * pole;

	cout << "Pocet trojuhelniku: " << endl;
	cin >> pocet;

	pole = new Trojuhelnik[pocet];

	/*for (size_t i = 0; i < pocet; i++)
	{
		pole[i] = Trojuhelnik();
	}*/



	system("pause");

	delete[] pole;

}