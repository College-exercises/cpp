#include <iostream>

#include "Map.h"

int main ()
{
	Map<int, const char*> m;

	m[10] = "C++";
	m[20] = "test";
	m[30] = "Poo";
	for (auto [key, value, index] : m)
		printf ("Index: %d, Key = %d, Value = %s\n", index, key, value);

	m[20] = "result";
	for (auto [key, value, index] : m)
		printf ("Index: %d, Key = %d, Value = %s\n", index, key, value);

	m.del (30);
	for (auto [key, value, index] : m)
		printf ("Index: %d, Key = %d, Value = %s\n", index, key, value);


	Map<int, const char*>m2 = m;
	printf ("m includes m2: %d\n", m.includes (m2));

	m.set (20, "RESULT");
	for (auto [key, value, index] : m)
		printf ("Index: %d, Key = %d, Value = %s\n", index, key, value);

	m.clear ();
	for (auto [key, value, index] : m)
		printf ("Index: %d, Key = %d, Value = %s\n", index, key, value);
	printf ("m includes m2: %d\n", m.includes (m2));

	return 0;
}
