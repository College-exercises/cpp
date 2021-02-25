#pragma once
#include <cstring>
#include "Student.h"

int compareName (Student first, Student second)
{
	return strcmp (first.getName (), second.getName ());
}

int compareMaths (Student first, Student second)
{
	if (first.getMathsGrade () == second.getMathsGrade ())
		return 0;
	if (first.getMathsGrade () > second.getMathsGrade ())
		return 1;
	return -1;
}
int compareEnglish (Student first, Student second)
{
	if (first.getEnglishGrade () == second.getEnglishGrade ())
		return 0;
	if (first.getEnglishGrade () > second.getEnglishGrade ())
		return 1;
	return -1;
}
int compareHistory (Student first, Student second)
{
	if (first.getMathsGrade () == second.getMathsGrade ())
		return 0;
	if (first.getMathsGrade () > second.getMathsGrade ())
		return 1;
	return -1;
}

int compareAverage (Student first, Student second)
{
	if (first.getAverage () == second.getAverage ())
		return 0;
	if (first.getAverage () > second.getAverage ())
		return 1;
	return -1;
}
