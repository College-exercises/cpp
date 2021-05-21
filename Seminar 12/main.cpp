#include <iostream>

#include "Agenda.h"

int main ()
{
	Agenda agenda;
	agenda.add (new Friend ("Marta Isabella Adam", "+40 775 622 386", { 22, 2, 2012 }, "Iasi"));
	agenda.add (new Friend ("Catina Valerian Adam", "+40 712 014 471", { 13, 9, 2009 }, "Braila"));
	agenda.add (new Colleague ("Natalia Isabela Vasilescu", "+40 702 082 058", "Kaufland", "Galati"));
	agenda.add (new Acquaintance ("Adrian Grigore Ardelean", "+40 737 331 122"));

	for (auto i : agenda.getAll ())
		std::cout << "Type: " << i->getType () << " Number: " << i->getNumber () << " Name: " << i->getName () << "\n";
	std::cout << "-----\n";

	agenda.del ("Marta Isabella Adam");
	for (auto i : agenda.getAll ())
		std::cout << "Type: " << i->getType () << " Number: " << i->getNumber () << " Name: " << i->getName () << "\n";
	std::cout << "-----\n";

	auto friends = agenda.getAll (ContactType::TypeFriend);
	for (auto i : friends)
		std::cout << "Type: " << i->getType () << " Number: " << i->getNumber () << " Name: " << i->getName () << "\n";

	return 0;
}
