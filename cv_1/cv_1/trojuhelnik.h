#ifndef TROJUHELNIK_H
#define TROJUHELNIK_H

#include <iostream>
#include <exception>

using namespace std;

void SestrojTrojuhelnik()
{
	std::cout << "zadejte stranu A: ";
	float a;
	std::cin >> a;

	std::cout << "Zadejte stranu B: ";
	float b;
	std::cin >> b;

	std::cout << "Zadejte stranu C: ";
	float c;
	std::cin >> c;

	if ((a + b) > c && (b + c) > a && (a + c) > b) {
		float result = a+b+c;
		std::cout << "Trojuhelnik lze sestrojit a obvod je: " << result << std::endl;
	}
	else {
		std::cout << "Trojuhelnik nelze sestrojit" << std::endl;
	}
		

}


struct Trojuhelnik {
public:
	int a;
	int b;
	int c;


	Trojuhelnik() {
		cout << "Zadejte stranu A: ";
		cin >> a;
		cout << "\n";

		cout << "Zadejte stranu B: ";
		cin >> b;
		cout << "\n";

		cout << "Zadejte stranu C: ";
		cin >> c;
		cout << "\n";

		if (a + b > c && a + c > b && b + c > a) {
			cout << "Trojuhelnik lze sestrojit a obvod je: " << a + b + c << endl;
		}
	}
};

static bool lzeSestrojit(Trojuhelnik t) {

	if (t.a + t.b > t.c && t.a + t.c > t.b && t.b + t.c > t.a) {

		cout << "Trojuhelnik lze sestrojit a obvod je: " << t.a + t.b + t.c << endl;
		return true;
	}
	else {

		return false;
	}

}


static bool lzeSestrojit(Trojuhelnik *t) {

	if (t->a + t->b > t->c && t->a + t->c > t->b && t->b + t->c > t->a) {
		cout << "Trojuhelnik lze sestrojit a obvod je: " << t->a + t->b + t->c << endl;
		return true;
	}
	else {
		return false;
	}

}

#endif // TROJUHELNIK_H