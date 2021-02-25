#include <cstring>
#include "Student.h"

void Student::setName (char name[])
{
	strcpy (this->name, name);
}
char* Student::getName ()
{
	return name;
}

void Student::setMathsGrade (float x)
{
	if (x >= 0 && x <= 10)
		grd.maths = x;
}
float Student::getMathsGrade ()
{
	return grd.maths;
}

void Student::setEnglishGrade (float x)
{
	if (x >= 0 && x <= 10)
		grd.english = x;
}
float Student::getEnglishGrade ()
{
	return grd.english;
}

void Student::setHistoryGrade (float x)
{
	if (x >= 0 && x <= 10)
		grd.history = x;
}
float Student::getHistoryGrade ()
{
	return grd.history;
}

float Student::getAverage ()
{
	return (grd.english + grd.maths + grd.history) / 3;
}
