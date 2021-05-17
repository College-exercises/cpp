#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

class myVec
	: public std::vector<std::string>
{
public:
	void sort (bool(*compare) (const std::string& left, const std::string& right))
	{
		std::sort (this->begin (), this->end (), compare);
	}
	void filter (bool(*filterer)(const std::string& str))
	{
		auto it = std::remove_if (this->begin (), this->end (), filterer);
		if (it != this->end ())
			this->erase (it, this->end ());
	}
	void iterate (void (*fun)(std::string& str))
	{
		std::for_each (this->begin (), this->end (), fun);
	}
	void print ()
	{
		std::cout << "[ ";
		for (const auto& ele : *this)
			std::cout << ele << ", ";
		std::cout << "\b\b ]\n";
	}
};
myVec parseText (char* text)
{
	myVec result;

	const char* delim = " ,.!?;:'\"";
	char* p = strtok (text, delim);
	while (p)
	{
		result.push_back (p);
		p = strtok (NULL, delim);
	}

	return result;
}
int main ()
{
	char text[] = "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat.";

	myVec vec = parseText (text);
	std::cout << "Original: ";
	vec.print ();

	vec.sort ([](const std::string& a, const std::string& b)->bool { if (a.size () == b.size ()) return a < b;  return a.size () < b.size (); });
	std::cout << "\nSorted:   ";
	vec.print ();

	vec.filter ([](const std::string& str)->bool { return str.size () % 2; });
	std::cout << "\nFiltered: ";
	vec.print ();

	vec.iterate ([](std::string& str) { if (str.size () < 6) str += "^o^"; else str += "\\o/"; });
	std::cout << "\nIterated: ";
	vec.print ();

	return 0;
}
