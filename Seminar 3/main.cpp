#include <iostream>

#include "Canvas.h"
#include "Math.h"

int main ()
{
	// 1
	printf ("%d\n", Math::add (10, 15));
	printf ("%d\n", Math::add (12, 15, 25));
	printf ("%d\n", Math::add (13.1, 15.5));

	printf ("%d\n", Math::mul (11, 15));
	printf ("%d\n", Math::mul (23, 15, 10));
	printf ("%d\n", Math::mul (47.1, 15.2));
	printf ("%d\n", Math::mul (10.1, 15.5, 20.1));

	printf ("%d\n", Math::add (4, 30, 5, 3, 2));
	printf ("%s\n\n\n", Math::add ("292442", "14444"));

	// 2
	Canvas canvas (20, 20);
	
	canvas.clear ();
	
	canvas.drawCircle (15, 15, 4, '@');
	canvas.fillCircle (16, 6, 3, '*');
	canvas.drawRect (0, 0, 7, 3, '#');
	canvas.fillRect (5, 5, 12, 12, '+');
	canvas.drawLine (9, 0, 0, 15, '0');
	canvas.setPoint (6, 3, '~');

	canvas.print ();
	
	return 0;
}
