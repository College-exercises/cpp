#include <iostream>

#include "Number.h"

int main ()
{
	// demo from https://sites.google.com/view/fii-poo/2021/laboratories
	Number n1 ("10110010", 2);
	Number n2 ("734", 8);
	Number n3 ("FF", 16);

	printf ("n1 has %d digits and it is written in base %d\n", n1.getDigitsCount (), n1.getBase ());
	for (int tr = 0; tr < n1.getDigitsCount (); tr++)
		printf ("n1[%d]=%c\n", tr, n1[tr]);
	n1.print ();
	n2.print ();
	n1 = (n2 + n3 - n1) + n1;	// after this n1 will be in base 16
	n1.switchBase (2);
	n1.print ();
	if (n1 > n2)
		printf ("n1 is bigger than n2\n");
	else 
		printf ("n2 is bigger than n1\n");

	Number n4 = 12345;			// n4 will be in base 10

	n1 = 255;		// n1 will be 11111111 (value 255 from base 10 in base 2)
	n4 += n1;
	n4.print ();
	n4 = "13579";	// n4 mentains its base (10) and will be 13579
	n4.print ();
	--n4;			// the first digit from n4 will be removed ==> n4 becomes 3579
	n4.print ();
	n4--;			// the last digit from n4 will be removed ==> n4 becomes 357
	n4.print ();

	// demo for ==, != and bitwise operators
	Number test1 ("123", 10), test2 ("345", 10);

	printf ("%d ", (test1 | test2) == (123 | 345));
	printf ("%d ", (test1 & test2) == (123 & 345));
	printf ("%d \n", (test1 ^ test2) == (123 ^ 345));

	printf ("%d ", (test1 |= test2) != (123 | 345));
	printf ("%d ", (test1 &= test2) != (123 & 345));		// no longer equal
	printf ("%d \n", (test1 ^= test2) != (123 ^ 345));		// no longer equal

	if (!test1)
	{
		test1.print ();
		printf ("^ is 0 or nullptr\n");
	}
	if (test2)
	{
		test2.print ();
		printf ("^ is not 0 or nullptr\n");
	}

	return 0;
}