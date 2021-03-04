#pragma once

class Math
{
public:

    static int add (int, int);
    static int add (int, int, int);
    static int add (double, double);

    static int mul (int, int);
    static int mul (int, int, int);
    static int mul (double, double);
    static int mul (double, double, double);

    static int add (int count, ...);                // adds 'count' numbers
    static char* add (const char*, const char*);    // adds two numbers inputed as strings
};
