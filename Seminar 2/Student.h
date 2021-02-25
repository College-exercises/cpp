#pragma once

struct Grades
{
	float maths, english, history;
};
class Student
{
private:
	char name[10];
	Grades grd;
public:
	void setName (char name[]);	
	char* getName ();

	void setMathsGrade (float x);
	float getMathsGrade ();

	void setEnglishGrade (float x);
	float getEnglishGrade ();

	void setHistoryGrade (float x);
	float getHistoryGrade ();

	float getAverage ();
};
