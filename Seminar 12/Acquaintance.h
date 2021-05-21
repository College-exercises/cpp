#pragma once

#include "Contact.h"

class Acquaintance
	: public Contact
{
public:
	Acquaintance (const std::string& name, const std::string& number) : Contact (name, number, ContactType::TypeAcquaintance) {}

	ContactType getType () const override { return type; }
};
