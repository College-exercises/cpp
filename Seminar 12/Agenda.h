#pragma once

#include <vector>

#include "Contact.h"
#include "Colleague.h"
#include "Acquaintance.h"
#include "Friend.h"

class Agenda
{
public:
	Contact* find (const std::string& name) const;

	void del (const std::string& name);
	void add (Contact* contact);

	std::vector<Contact*> getAll () const;
	std::vector<Contact*> getAll (ContactType type) const;
private:
	std::vector<Contact*> agenda;
};
