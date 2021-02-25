#include <iostream>
#include "NumberList.h"
#include "Student.h"
#include "global.h"

int main()
{
	NumberList newList;

	newList.Init ();
	newList.Add (2);
	newList.Add (1);
	newList.Add (9);
	newList.Add (20);
	newList.Add (12);
	newList.Add (12);
	newList.Print ();

	newList.Sort ();
	newList.Print ();

	newList.insert (2, 1000);
	newList.Print ();

	newList.removeAllElements (12);
	newList.Print ();

	Student s1, s2;
	s1.setName ((char*)"Student123");
	s1.setEnglishGrade (10);
	s1.setMathsGrade (2.2);
	s1.setEnglishGrade (5.4);

	s2.setName ((char*)"florin");
	s2.setEnglishGrade (2);
	s2.setMathsGrade (8.5);
	s2.setHistoryGrade (9);

	printf ("%s %s\n%f %f\n%f %d", s1.getName (), s2.getName (),
		s1.getMathsGrade (), s2.getEnglishGrade (),
		s1.getAverage (), compareAverage (s1, s2));
	return 0;
}