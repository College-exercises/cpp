#include <cstring>

#include "Mercedes.h"

Mercedes::Mercedes ()
{
	setFuelCapacity (70);
	setFuelConsumption (5.1f);

	setAvgSpeed (46, Weather::Rain);
	setAvgSpeed (43, Weather::Sunny);
	setAvgSpeed (35, Weather::Snow);

	strcpy (name, "Mercedes");
}

void Mercedes::setFuelCapacity (int value)
{
	fuelCapacity = value;
}
void Mercedes::setFuelConsumption (int value)
{ 
	fuelConsumption = value; 
}
void Mercedes::setAvgSpeed (int value, Weather condition)
{ 
	avgSpeed[condition] = value; 
}
void Mercedes::setName (const char* name) 
{
	strcpy (this->name, name);
}

int Mercedes::getFuelCapacity () 
{
	return fuelCapacity; 
}
float Mercedes::getFuelConsumption () 
{ 
	return fuelConsumption; 
}
int Mercedes::getAvgSpeed (Weather condition)
{
	return avgSpeed[condition];
}
char* Mercedes::getName ()
{
	return name;
}
