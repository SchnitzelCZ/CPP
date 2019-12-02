#ifndef MATICE_H
#define MATICE_H

#include <exception>
#include <iostream>

template <class T>
class Matice
{
public:
	Matice(int radky, int sloupce);
	Matice(const Matice<T>& m);
	~Matice();
	void Nastav(int radek, int sloupec, T hodnota);
	void NastavZ(T* pole);
	T& Dej(int radek, int sloupec);
	const T& Dej(int radek, int sloupec) const;
	template <class R>
	Matice<R> Pretypuj() const;
	Matice Transpozice() const;
	Matice Soucin(const Matice& m) const;
	Matice Soucin(T skalar) const;
	Matice Soucet(const Matice& m) const;
	Matice Soucet(T skalar) const;
	bool JeShodna(const Matice& m) const;
	int GetRadky() const { return this->radky;}
	void SetRadky(int radky) { this->radky = radky;}
	int GetSloupce() const { return this->sloupce;}
	void SetSloupce(int sloupce) { this->sloupce = sloupce;}

private:
	int radky, sloupce;
	T** pole;
};

template<class T>
Matice<T>::Matice(int radky, int sloupce)
{
	this->sloupce = sloupce;
	this->radky = radky;
	this->pole = new T*[radky];

	for (int i = 0; i < radky; i++)
		pole[i] = new T[sloupce];
}

template<class T>
Matice<T>::Matice(const Matice<T>& m)
{
	radky = m.GetRadky();
	sloupce = m.GetSloupce();
	pole = new T *[m.GetRadky()];
	for (int i = 0; i < m.GetSloupce(); i++) {
		pole[i] = new T[m.GetSloupce()];
	}

	for (int i = 0; i < m.GetRadky(); i++) {
		for (int j = 0; j < m.GetSloupce(); j++) {
			pole[i][j] = m.Dej(i, j);
		}
	}
}

template<class T>
Matice<T>::~Matice()
{
	for (int i = 0; i < radky; i++)
		delete[] pole[i];
	delete[] pole;
}

template<class T>
void Matice<T>::Nastav(int radek, int sloupec, T hodnota)
{
	if (radek < 0 || radek >= this->radky || sloupec < 0 || sloupec >= this->sloupce) {
		throw std::out_of_range("Neplatne souradnice");
	}else{
	pole[radek][sloupec] = hodnota;
	}
}

template<class T>
void Matice<T>::NastavZ(T* pole)
{
	for (int i = 0; i < radky; i++)
		for (int j = 0; j < sloupce; j++)
			this->pole[i][j] = pole[(sloupce * i) + j];
}

template<class T>
T& Matice<T>::Dej(int radek, int sloupec)
{
	if (radek < 0 || radek >= this->radky || sloupec < 0 || sloupec >= this->sloupce) {
		throw std::out_of_range("Neplatne souradnice");
	}
	else {
		return pole[radek][sloupec];
	}
}

template<class T>
const T& Matice<T>::Dej(int radek, int sloupec) const
{
	if (radek < 0 || radek >= this->radky || sloupec < 0 || sloupec >= this->sloupce) {
		throw std::out_of_range("Neplatne souradnice");
	}
	else {
		return pole[radek][sloupec];
	}
}

template <class T>
template <class R>
Matice<R> Matice<T>::Pretypuj() const
{
	Matice<R> vyslednaMatice(radky, sloupce);
	for (int i = 0; i < radky; i++) {
		for (int j = 0; j < sloupce; j++) {
			vyslednaMatice.Nastav(i,j,(R)pole[i][j]);
		}
	}
	return vyslednaMatice;
}

template<class T>
Matice<T> Matice<T>::Transpozice() const
{
	Matice
<T>* vyslednaMatice = new Matice{ GetRadky(), GetSloupce() };

	for (int i = 0; i < GetRadky(); ++i)
		for (int j = 0; j < GetSloupce(); ++j)
		{
			vyslednaMatice->Nastav(j, i, pole[i][j]);
		}
	return *vyslednaMatice;
}

template<class T>
Matice<T> Matice<T>::Soucin(const Matice& m) const
{
	if (sloupce != m.GetRadky())
		throw std::exception("Nelze nasobit");

	Matice<T> vyslednaMatice(radky, sloupce);
	for (int i = 0; i < radky; i++)
		for (int j = 0; j < m.GetSloupce(); j++)
		{
			T temp = T();
			for (int k = 0; k < sloupce; k++)
				temp += pole[i][k] * m.Dej(k,j);
			vyslednaMatice.Nastav(i, j, temp);
		}

	return vyslednaMatice;
}

template<class T>
Matice<T> Matice<T>::Soucin(T skalar) const
{
	Matice<T> vyslednaMatice;
	for (int i = 0; i < radky; i++) {
		for (int j = 0; j < sloupce; j++) {
			vyslednaMatice[i][j] = (vyslednaMatice[i][j] * skalar);
		}
	}
	return vyslednaMatice;
}

template<class T>
Matice<T> Matice<T>::Soucet(const Matice& m) const
{
	if (m.GetSloupce() != sloupce || m.GetRadky() != radky){
	throw std::logic_error("Ruzne velikosti matic");
		}

	Matice<T> vyslednaMatice(radky, sloupce);
	for (int i = 0; i < radky; i++) {
		for (int j = 0; j < sloupce; j++) {
			vyslednaMatice[i][j] = pole[i][j] + m.Dej(i, j);
		}
	}
	return vyslednaMatice;
}

template<class T>
Matice<T> Matice<T>::Soucet(T skalar) const
{
	Matice<T> vyslednaMatice(radky, sloupce);
	for (int i = 0; i < radky; i++) {
		for (int j = 0; j < sloupce; j++) {
			vyslednaMatice[i][j] = (pole[i][j] + skalar);
		}
	}
	return vyslednaMatice;
}

template<class T>
bool Matice<T>::JeShodna(const Matice& m) const
{
	if (m.GetSloupce() != sloupce || m.GetRadky() != radky)
		throw std::logic_error("Nemaji shodne velikosti");

	for (int i = 0; i < radky; i++) {
		for (int j = 0; j < sloupce; j++) {
			if (pole[i][j] != m.Dej(i, j))
				return false;
		}
	}
	return true;
}

#endif // !MATICE_H