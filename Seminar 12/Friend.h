#pragma once

#include <string>

#include "Contact.h"


class Friend
	: public Contact
{
private:
	struct Data
	{
		int day, month, year;
	};
public:
	Friend (const std::string& name, const std::string& number, const Data& birth, const std::string& address)
		: Contact (name, number, ContactType::TypeFriend), birth (birth), address (address) {}

	ContactType getType () const override { return type; }
private:
	Data birth;
	std::string address;
};
