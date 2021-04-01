#include <iostream>
#include <Windows.h>

#include "Degrees.h"
#include "Vector.h"

int main ()
{
	float a = 300.0_Kelvin;
	float b = 120.0_Fahrenheit;
	std::cout << a << " " << b << '\n';

	VectorIn vec (20);
	srand (time (0));

	for (int i = 0; i < 20; i++)
		vec.push (rand () % 100);
	std::cout << vec;

	for (int i = 0; i < 5; i++)
		vec.remove (i * 3);
	std::cout << vec;

	vec.insert (2, 999);
	std::cout << vec;

	vec.sort ([](int a, int b)->bool { return a < b; });
	std::cout << vec;

	std::cout << vec.firstIndexOf (5) << " " << vec.firstIndexOf (10, [](int a)->bool { return a % 10 == 0; }) << '\n';
	
	VectorIn vec2{ 10, 20, 30, 40, 80 };
	vec2.suitch (vec);
	std::cout << vec2;
	std::cout << vec;

	return 0;
}
