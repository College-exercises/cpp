#pragma once

#include "Contact.h"

class Colleague
	: public Contact
{
public:
	Colleague (const std::string& name, const std::string& number, const std::string& office, const std::string& address)
		: Contact (name, number, ContactType::TypeColleague), office (office), address (address) {}

	ContactType getType () const override { return type; }
private:
	std::string office;
	std::string address;
};

