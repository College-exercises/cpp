#include <cstring>
#include <cmath>
#include <iostream>

#include "Number.h"

Number::Number (const char* value, int base) : base (base), value (nullptr)
{
	int flag = false;
	if (value)
	{
		for (int i = 0; i < strlen (value) && !flag; i++)
			if (!(isdigit (value[i]) && value[i] - '0' < base ||
				islower (value[i]) && value[i] < 'a' + base - 10 ||
				isupper (value[i]) && value[i] < 'A' + base - 10))
			{
				printf ("Not a valid string\n");
				flag = true;
			}
		if (!flag)
		{
			this->value = new char[strlen (value) + 1];
			strcpy (this->value, value);
		}
	}
}
Number::Number (const Number& other) : base (other.base)
{
	value = new char[strlen (other.value) + 1];
	strcpy (value, other.value);
}
Number::Number (Number&& other) noexcept : base (other.base)
{
	value = other.value;
	other.value = nullptr;
}
Number::Number (const int value) : base (10)
{
	this->value = new char[log10 (value) + 2];
	_itoa (value, this->value, 10);
}
Number::~Number ()
{
	delete[] value;
}

Number& Number::operator= (const Number& other)
{
	if (this != &other)
	{
		char* temp = new char[strlen (other.value) + 1];
		strcpy (temp, other.value);
		delete[] value;
		value = temp;
		base = other.base;
	}
	return *this;
}
Number& Number::operator= (Number&& other) noexcept
{
	if (this != &other)
	{
		delete[] value;
		value = other.value;
		base = other.base;
		other.value = nullptr;
	}

	return *this;
}

bool Number::operator! () const
{
	if (value == nullptr)
		return 1;
	else
		return strcmp (value, "0") == 0;
}
char& Number::operator[] (unsigned int index)
{
	if (index < strlen (value))
		return value[index];

	printf ("Out of bounds!\n");
	return value[0];
}
bool Number::operator> (const Number& other) const
{
	Number temp1 (*this), temp2 (other);

	temp1.switchBase (std::max (temp1.base, temp2.base));
	temp2.switchBase (std::max (temp1.base, temp2.base));

	if (strlen (temp1.value) > strlen (temp2.value))
		return true;
	if (strlen (temp1.value) < strlen (temp2.value))
		return false;

	for (int i = 0; i < strlen (temp1.value); i++)
		if (temp1.value[i] > temp2.value[i])
			return true;
		else if (temp1.value[i] < temp2.value[i])
			return false;

	return false;
}
bool Number::operator>= (const Number& other) const
{
	return (*this > other || *this == other);
}
bool Number::operator< (const Number& other) const
{
	return !(*this > other || *this == other);
}
bool Number::operator<= (const Number& other) const
{
	return !(*this > other);
}
bool Number::operator== (const Number& other) const
{
	Number temp1 (*this), temp2 (other);

	temp1.switchBase (std::max (temp1.base, temp2.base));
	temp2.switchBase (std::max (temp1.base, temp2.base));

	if (strlen (temp1.value) != strlen (temp2.value))
		return false;

	for (int i = 0; i < strlen (temp1.value); i++)
		if (temp1.value[i] != temp2.value[i])
			return false;

	return true;
}
bool Number::operator!= (const Number& other) const
{
	return !(*this == other);
}
bool Number::operator== (const int other) const
{
	Number temp (*this);

	temp.switchBase (10);

	return (atoi (temp.value) == other);
}
bool Number::operator!= (const int other) const
{
	Number temp (*this);

	temp.switchBase (10);

	return (atoi (temp.value) != other);
}

Number::operator bool ()
{
	if (value == nullptr)
		return 0;
	return strcmp (value, "0");
}

Number Number::operator| (const Number& other) const
{
	Number dis (*this), temp (other);

	dis.switchBase (10);
	temp.switchBase (10);

	int result = atoi (dis.value) | atoi (temp.value);
	dis = result;
	dis.switchBase (std::max (base, other.base));

	return dis;
}
Number Number::operator& (const Number& other) const
{
	Number dis (*this), temp (other);

	dis.switchBase (10);
	temp.switchBase (10);

	int result = atoi (dis.value) & atoi (temp.value);
	dis = result;
	dis.switchBase (std::max (base, other.base));

	return dis;
}
Number Number::operator^ (const Number& other) const
{
	Number dis (*this), temp (other);

	dis.switchBase (10);
	temp.switchBase (10);

	int result = atoi (dis.value) ^ atoi (temp.value);
	dis = result;
	dis.switchBase (std::max (base, other.base));

	return dis;
}
Number Number::operator|= (const Number& other)
{
	*this = *this | other;
	return *this;
}
Number Number::operator&= (const Number& other)
{
	*this = *this & other;
	return *this;
}
Number Number::operator^= (const Number& other)
{
	*this = *this ^ other;
	return *this;
}

void Number::operator= (const int& source)
{
	value = new char[log10 (std::max (1, source)) + 2];
	_itoa (source, value, 10);
	base = 10;
}
void Number::operator= (const char* source)
{
	base = 10;
	if (source)
	{
		value = new char[strlen (source) + 1];
		strcpy (value, source);
	}
	else
		value = nullptr;
}

Number Number::operator+= (const Number& other)
{
	*this = *this + other;
	return *this;
}

Number& Number::operator-- ()
{
	strcpy (value, value + 1);
	return *this;
}
Number& Number::operator-- (int)
{
	value[strlen (value) - 1] = 0;
	return *this;
}

Number operator- (const Number& left, const Number& right)
{
	Number temp1 (left), temp2 (right);

	temp1.switchBase (10);
	temp2.switchBase (10);

	Number result ("", 0);

	result = atoi (temp1.value) - atoi (temp2.value);
	result.base = std::max (left.base, right.base);

	return result;
}
Number operator+ (const Number& left, const Number& right)
{
	Number temp1 (left), temp2 (right);

	temp1.switchBase (10);
	temp2.switchBase (10);

	Number result ("", 0);

	result = atoi (temp1.value) + atoi (temp2.value);
	result.base = std::max (left.base, right.base);

	return result;
}

void Number::switchBase (int newBase)
{
	if (base == newBase)
		return;

	int power = 0;
	uint64_t result = 0;

	for (int i = strlen (value) - 1; i >= 0; i--)
		if (isdigit (value[i]))
			result += (value[i] - '0') * pow (base, power++);
		else if (islower (value[i]))
			result += (value[i] - 'a' + 10) * pow (base, power++);
		else
			result += (value[i] - 'A' + 10) * pow (base, power++);

	int len = log (std::max ((uint64_t)1, result)) / log (newBase);
	char* res = new char[len + 2];
	int index = len;

	while (result)
	{
		if (result % newBase < 10)
			res[index--] = result % newBase + '0';
		else
			res[index--] = result % newBase + 'a' - 10;
		result /= newBase;
	}

	res[len + 1] = 0;
	value = new char[len + 2];
	strcpy (value, res);
	base = newBase;
	delete[] res;
}
void Number::print ()
{
	printf ("%s (%d)\n", value, base);
}

int Number::getDigitsCount ()
{
	return strlen (value);
}
int Number::getBase ()
{
	return base;
}
