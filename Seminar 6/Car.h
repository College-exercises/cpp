#pragma once

#include "Weather.h"

class Car
{
protected:
	int fuelCapacity, avgSpeed[3];
	float fuelConsumption;
	char name[32];
public:
	virtual void setFuelCapacity (int value) = 0;
	virtual void setFuelConsumption (int value) = 0;
	virtual void setAvgSpeed (int value, Weather condition) = 0;
	virtual void setName (const char* name) = 0;

	virtual int getFuelCapacity () = 0;
	virtual float getFuelConsumption () = 0;
	virtual int getAvgSpeed (Weather condition) = 0;
	virtual char* getName () = 0;
};
