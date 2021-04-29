#include <iostream>

#include "Array.h"

int main ()
{
	Array<std::string> arr;
	std::string str[] = { "lorem", "ipsum", "123", "-1", "/*o[", "test" };

	for (int i = 0; i < 6; i++)
		arr += str[i];

	std::cout << "arr is: ";
	for (const auto& i : arr)
		std::cout << i << " ";
	std::cout << '\n';

	try
	{
		std::cout << arr.binarySearch (std::string ("test"), [](const std::string& left, const std::string& right)->int { if (left < right) return -1; return left > right; });
	}
	catch (std::exception& e)
	{
		std::cout << e.what ();
	}

	std::cout << "arr is: ";
	for (const auto& i : arr)
		std::cout << i << " ";
	std::cout << '\n';

	arr.sort ();
	std::cout << "arr is: ";
	for (const auto& i : arr)
		std::cout << i << " ";
	std::cout << '\n';

	std::cout << "\"test\" is at position: "
		<< arr.binarySearch (std::string ("test"), [](const std::string& left, const std::string& right)->int { if (left < right) return -1; return left > right; })
		<< ", \"notInArray\" is at position: "
		<< arr.find ("notInArray", [](const std::string& left, const std::string& right)->int { return left != right; }) << '\n';

	return 0;
}
