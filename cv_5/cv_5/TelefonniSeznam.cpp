#include "TelefonniSeznam.h"

int pocetZaznamu = 0;


Model::TelefonniSeznam::TelefonniSeznam()
{
	this->_prvni = nullptr;
	this->_posledni = nullptr;
}

Model::TelefonniSeznam::~TelefonniSeznam()
{
	PrvekSeznam* keSmazani = _prvni;
	PrvekSeznam* aktualni = _prvni->dalsi;
	while (aktualni != nullptr) {
		delete keSmazani;
		keSmazani = aktualni;
		aktualni = aktualni->dalsi;
	}
	delete _prvni;
	delete _posledni;
}

void Model::TelefonniSeznam::pridejOsobu(Entity::Osoba o)
{
	if (_prvni == nullptr)
	{
		_prvni->data = o;
		_posledni = _prvni;

	}
	else {
		_posledni->dalsi->data = o;
		_posledni = _posledni->dalsi;
	}
}

std::string Model::TelefonniSeznam::najdiTelefon(std::string jmeno) const
{
	if (_prvni == nullptr) {
		throw std::out_of_range("Seznam je prazdny");
	}

	PrvekSeznam* _aktualni = _prvni;
	while (_aktualni != nullptr) {
		if (_aktualni->data.getJmeno() == jmeno) {
			return _aktualni->data.getTelefon();
		}
		_aktualni = _aktualni->dalsi;
	}
	throw std::logic_error("Nic nenalezeno");
}

std::string Model::TelefonniSeznam::najdiTelefon(int id) const
{
	if (_prvni == nullptr) {
		throw std::out_of_range("Seznam je prazdny");
	}

	PrvekSeznam* _aktualni = _prvni;
	while (_aktualni != nullptr) {
		if (_aktualni->data.getID() == id) {
			return _aktualni->data.getTelefon();
		}
		_aktualni = _aktualni->dalsi;
	}
	throw std::logic_error("Nic nenalezeno");
}
