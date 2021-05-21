#include <exception>

#include "Agenda.h"
#include <iostream>

Contact* Agenda::find (const std::string& name) const
{
	for (auto person : agenda)
		if (person->getName () == name)
			return person;

	throw std::exception ("Could not find the contact");
}

void Agenda::del (const std::string& name)
{
	for (int i = 0; i < agenda.size (); i++)
		if (agenda[i]->getName () == name)
		{
			agenda.erase (agenda.begin () + i);
			return;
		}
}

void Agenda::add (Contact* contact)
{
	agenda.push_back (contact);
}

std::vector<Contact*> Agenda::getAll () const
{
	return agenda;
}

std::vector<Contact*> Agenda::getAll (ContactType type) const
{
	std::vector<Contact*> temp;

	for (auto person : agenda)
		if (person->getType () == type)
			temp.push_back (person);

	return temp;
}
