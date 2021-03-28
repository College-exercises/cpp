#include <cstring>

#include "Mazda.h"

Mazda::Mazda ()
{
	setFuelCapacity (65);
	setFuelConsumption (3.8f);

	setAvgSpeed (25, Weather::Rain);
	setAvgSpeed (50, Weather::Sunny);
	setAvgSpeed (15, Weather::Snow);

	strcpy (name, "Mazda");
}

void Mazda::setFuelCapacity (int value) 
{
	fuelCapacity = value; 
}
void Mazda::setFuelConsumption (int value)
{ 
	fuelConsumption = value; 
}
void Mazda::setAvgSpeed (int value, Weather condition) 
{ 
	avgSpeed[condition] = value;
}
void Mazda::setName (const char* name)
{ 
	strcpy (this->name, name);
}

int Mazda::getFuelCapacity () 
{ 
	return fuelCapacity;
}
float Mazda::getFuelConsumption ()
{
	return fuelConsumption; 
}
int Mazda::getAvgSpeed (Weather condition)
{
	return avgSpeed[condition];
}
char* Mazda::getName () 
{
	return name;
}
