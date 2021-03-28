#include <cstring>

#include "Dacia.h"
#include "Weather.h"

Dacia::Dacia ()
{
	setFuelCapacity (100);
	setFuelConsumption (25.0f);

	setAvgSpeed (30, Weather::Rain);
	setAvgSpeed (50, Weather::Sunny);
	setAvgSpeed (25, Weather::Snow);

	strcpy (name, "Dacia");
}

void Dacia::setFuelCapacity (int value)
{
	fuelCapacity = value;
}
void Dacia::setFuelConsumption (int value)
{
	fuelConsumption = value;
}
void Dacia::setAvgSpeed (int value, Weather condition)
{
	avgSpeed[condition] = value;
}
void Dacia::setName (const char* name)
{
	strcpy (this->name, name);
}

int Dacia::getFuelCapacity () 
{
	return fuelCapacity;
}
float Dacia::getFuelConsumption () 
{ 
	return fuelConsumption;
}
int Dacia::getAvgSpeed (Weather condition) 
{ 
	return avgSpeed[condition];
}
char* Dacia::getName ()
{ 
	return name; 
}
