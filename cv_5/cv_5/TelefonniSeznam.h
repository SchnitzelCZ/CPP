#ifndef TELEFONNI_SEZNAM_H
#define TELEFONNI_SEZNAM_H
#include <string>
#include "Osoba.h"
#include <exception>

namespace Model {

	class TelefonniSeznam
	{
		struct PrvekSeznam
		{
			Entity::Osoba data;
			PrvekSeznam* dalsi;
		};
	public:
		TelefonniSeznam();
		~TelefonniSeznam();

		PrvekSeznam* _prvni;
		PrvekSeznam* _posledni;

		void pridejOsobu(Entity::Osoba o);

		std::string najdiTelefon(std::string jmeno) const;
		std::string najdiTelefon(int id) const;
	private:
		int pocetZaznamu;

	};
}
#endif // !