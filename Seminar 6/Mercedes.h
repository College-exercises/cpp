#pragma once

#include "Car.h"

class Mercedes : public Car
{
public:
	Mercedes ();

	void setFuelCapacity (int value) override;
	void setFuelConsumption (int value) override;
	void setAvgSpeed (int value, Weather condition) override;
	void setName (const char* name) override;

	int getFuelCapacity () override;
	float getFuelConsumption () override;
	int getAvgSpeed (Weather condition) override;
	char* getName () override;
};
