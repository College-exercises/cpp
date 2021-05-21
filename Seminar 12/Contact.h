#pragma once

#include <string>

enum ContactType
{
	TypeAcquaintance,
	TypeFriend,
	TypeColleague
};

class Contact
{
public:
	Contact () = delete;
	Contact (const std::string& name, const std::string& number, ContactType type) : name (name), number (number), type (type) {}

	virtual ContactType getType () const = 0;

	std::string getName () const { return name; };
	std::string getNumber () const { return number; };
protected:
	std::string name;
	std::string number;
	ContactType type;
};
