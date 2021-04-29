#pragma once

#include <exception>

class NotSorted
	: public std::exception
{
public:
	const char* what () const throw()
	{
		return "The list is not sorted\n";
	}
};
