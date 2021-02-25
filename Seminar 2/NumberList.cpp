#include <iostream>
#include "NumberList.h"

void NumberList::Init ()
{
	count = 0;
}
bool NumberList::Add (int x)
{
	if (count > 9)
		return false;
	numbers[count++] = x;
	return true;
}
void NumberList::removeAllElements (int x)
{
	for (int i = 0; i < count; i++)
		if (numbers[i] == x)
		{
			for (int j = i; j < count; j++)
				numbers[j] = numbers[j + 1];
			count--;
			i--;
		}
}
bool NumberList::insert (int pos, int x)
{
	if (count > 9 || pos < 0 || pos > 9)
		return false;
	for (int i = count; i > pos; i--)
		numbers[i] = numbers[i - 1];
	numbers[pos] = x;
	count++;
	return true;
}
void NumberList::Sort ()
{
	for (int i = 0; i < count - 1; i++)
		for (int j = i + 1; j < count; j++)
			if (numbers[i] > numbers[j])
				std::swap (numbers[i], numbers[j]);
}
void NumberList::Print ()
{
	for (int i = 0; i < count; i++)
		printf ("%d ", numbers[i]);
	printf ("\n");
}
