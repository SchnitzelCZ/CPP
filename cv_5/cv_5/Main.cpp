#include "Osoba.h";
#include "TelefonniSeznam.h";
#include "Main.h"

int main()
{
	Entity::Osoba p0 = Entity::Osoba("Martin", "774993772", 1);
	Entity::Osoba p1 = Entity::Osoba("Olda", "774993776", 2);

	Model::TelefonniSeznam *list = new Model::TelefonniSeznam();
	list->pridejOsobu(p0);
	list->pridejOsobu(p1);


}