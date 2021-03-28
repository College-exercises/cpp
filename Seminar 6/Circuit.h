#pragma once

#include "Car.h"
#include "Weather.h"

class Circuit
{
private:
	int length, index, ranks[16]{}, fuel[16]{};
	Weather condition;
	Car* cars[16]{};
public:
	Circuit ();
	void setLength (int value);
	void race ();
	void addCar (Car* car);
	void setWeather (Weather condition);
	void showFinalRanks ();
	void whoDidNotFinish ();
	void sortByConsumption ();
};
