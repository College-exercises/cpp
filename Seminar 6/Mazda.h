#pragma once

#include "Car.h"

class Mazda : public Car
{
public:
	Mazda ();

	void setFuelCapacity (int value) override;
	void setFuelConsumption (int value) override;
	void setAvgSpeed (int value, Weather condition) override;
	void setName (const char* name) override;

	int getFuelCapacity () override;
	float getFuelConsumption () override;
	int getAvgSpeed (Weather condition) override;
	char* getName () override;
};
