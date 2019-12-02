#ifndef OSOBA_H
#define OSOBA_H

#include <string>

namespace Entity {

	class Osoba
	{
	public:
		Osoba(std::string jmeno, std::string telefon, int id);
		~Osoba();
		int getID();
		std::string getJmeno();
		std::string getTelefon();
	private:
		std::string jmeno;
		std::string telefon;
		int id;

	};
}
#endif