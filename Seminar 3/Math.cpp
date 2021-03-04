#include <cstring>
#include <iostream>
#include <stdarg.h>

#include "Math.h"

int Math::add (int x, int y)
{
	return x + y;
}
int Math::add (int x, int y, int z)
{
	return x + y + z;
}
int Math::add (double x, double y)
{
	return x + y;
}

int Math::mul (int x, int y)
{
	return x * y;
}
int Math::mul (int x, int y, int z)
{
	return x * y * z;
}
int Math::mul (double x, double y)
{
	return x * y;
}
int Math::mul (double x, double y, double z)
{
	return x * y * z;
}

int Math::add (int count, ...)
{
	va_list arg;
	va_start (arg, count);
	int sum = 0;

	for (int i = 0; i < count; i++)
		sum += va_arg (arg, int);
	
	va_end (arg);
	return sum;
}
char* Math::add (const char* x, const char* y)
{
	if (x == nullptr || y == nullptr)
		return nullptr;
	if (x == "")
		return (char*)y;
	if (y == "")
		return (char*)x;

	int len = std::max (strlen (x), strlen (y)) + 1;
	char* result = new char[len + 2]{};
	char* a = new char[strlen(x) + 1], * b = new char[strlen(y) + 1];

	// copy the strings and reverse them
	strcpy (a, x);
	strcpy (b, y);
	_strrev (a);
	_strrev (b);

	// similar to memset
	for (int i = strlen (a); i < len; i++)
		a[i] = '0';
	for (int i = strlen (b); i < len; i++)
		b[i] = '0';

	// adds the values
	for (int i = 0; i <= len; i++)
	{
		result[i] += a[i] + b[i] - '0';
		if (result[i] > 9 + '0')
		{
			result[i] -= 10;
			result[i + 1]++;
		}
	}
	// removes unnecessary characters
	result[len] = 0;
	if (result[len - 1] == '0')
		result[len - 1] = 0;

	_strrev (result);

	// it should work, but it doesn't
	//delete[] a;
	//delete[] b;
	return result;
}
