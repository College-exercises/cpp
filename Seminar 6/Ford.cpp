#include <cstring>

#include "Ford.h"

Ford::Ford ()
{
	setFuelCapacity (80);
	setFuelConsumption (3.8f);

	setAvgSpeed (32, Weather::Rain);
	setAvgSpeed (49, Weather::Sunny);
	setAvgSpeed (30, Weather::Snow);

	strcpy (name, "Ford");
}

void Ford::setFuelCapacity (int value) 
{ 
	fuelCapacity = value;
}
void Ford::setFuelConsumption (int value)
{ 
	fuelConsumption = value;
}
void Ford::setAvgSpeed (int value, Weather condition)
{ 
	avgSpeed[condition] = value;
}
void Ford::setName (const char* name) 
{ 
	strcpy (this->name, name);
}

int Ford::getFuelCapacity () 
{ 
	return fuelCapacity;
}
float Ford::getFuelConsumption ()
{
	return fuelConsumption; 
}
int Ford::getAvgSpeed (Weather condition)
{
	return avgSpeed[condition];
}
char* Ford::getName () 
{
	return name; 
}
