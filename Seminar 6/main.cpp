#include "Circuit.h"
#include "Dacia.h"
#include "Ford.h"
#include "Mazda.h"
#include "Mercedes.h"
#include "Toyota.h"

int main ()
{
	Circuit c;
	c.setLength (1000);

	c.addCar (new Dacia ());
	c.addCar (new Toyota ());
	c.addCar (new Mercedes ());
	c.addCar (new Ford ());
	c.addCar (new Mazda ());
	
	c.setWeather (Weather::Rain);
	c.race ();
	c.showFinalRanks ();	// it will print the time each car needed to finish the circuit sorted from the fastest car to the slowest.
	c.whoDidNotFinish ();	// it is possible that some cars don't have enough fuel to finish the circuit
	
	c.setWeather (Weather::Snow);
	c.race ();
	c.showFinalRanks ();
	c.whoDidNotFinish ();
	
	c.setWeather (Weather::Sunny);
	c.race ();
	c.showFinalRanks ();
	c.whoDidNotFinish ();
	c.sortByConsumption ();

	return 0;
}
