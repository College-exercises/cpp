#include <algorithm>

#include "Circuit.h"

Circuit::Circuit () :
	length (100), condition (Weather::Sunny), index (0) {}

void Circuit::setLength (int value) 
{ 
	length = value;
}
void Circuit::race ()
{
	for (int i = 0; i < index; i++)
		ranks[i] = cars[i]->getAvgSpeed (condition);

	std::sort (cars, cars + index, [=](Car* left, Car* right)->bool
		{ return left->getAvgSpeed (condition) > right->getAvgSpeed (condition); });
}
void Circuit::addCar (Car* car) 
{
	cars[index++] = car;
}
void Circuit::setWeather (Weather condition) 
{ 
	this->condition = condition; 
}
void Circuit::showFinalRanks ()
{
	int rank = 1;
	
	for (int i = 0; i < index; i++)
	{
		float autonomy = 100 * cars[i]->getFuelCapacity () / cars[i]->getFuelConsumption ();

		if (autonomy >= length)
			printf ("%i. %s finished\n", rank++, cars[i]->getName ());
	}

	printf ("\n");
}
void Circuit::whoDidNotFinish ()
{
	for (int i = 0; i < index; i++)
	{
		float autonomy = 100 * cars[i]->getFuelCapacity () / cars[i]->getFuelConsumption ();

		if (autonomy < length)
			printf ("%s did not finish\n", cars[i]->getName ());
	}

	printf ("\n");
}
void Circuit::sortByConsumption ()
{
	for (int i = 0; i < index; i++)
		fuel[i] = cars[i]->getAvgSpeed (condition);

	std::sort (cars, cars + index, [=](Car* left, Car* right)->bool
		{ return left->getFuelConsumption () > right->getFuelConsumption (); });

	for (int i = 0; i < index; i++)
		printf ("%d. %s\n", i + 1, cars[i]->getName ());
}