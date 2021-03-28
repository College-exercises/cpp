#include <cstring>

#include "Toyota.h"

Toyota::Toyota ()
{
	setFuelCapacity (80);
	setFuelConsumption (3.8f);

	setAvgSpeed (32, Weather::Rain);
	setAvgSpeed (49, Weather::Sunny);
	setAvgSpeed (30, Weather::Snow);

	strcpy (name, "Toyota");
}

void Toyota::setFuelCapacity (int value) 
{
	fuelCapacity = value;
}
void Toyota::setFuelConsumption (int value)
{
	fuelConsumption = value; 
}
void Toyota::setAvgSpeed (int value, Weather condition)
{
	avgSpeed[condition] = value; 
}
void Toyota::setName (const char* name) 
{
	strcpy (this->name, name);
}

int Toyota::getFuelCapacity ()
{ 
	return fuelCapacity;
}
float Toyota::getFuelConsumption ()
{
	return fuelConsumption;
}
int Toyota::getAvgSpeed (Weather condition) 
{ 
	return avgSpeed[condition]; 
}
char* Toyota::getName ()
{
	return name; 
}
