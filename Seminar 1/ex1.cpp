#include <iostream>
#include <fstream>
#include <cstring>
int atoi (char source[])
{
    int value = 0;
    if (source[0] != '-')
    {
        for (int i = 0; i < strlen (source); i++)
            value = value * 10 + source[i] - '0';
        return value;
    }
    else
    {
        for (int i = 1; i < strlen (source); i++)
            value = value * 10 + source[i] - '0';
        return -value;
    }
}
int main ()
{
    FILE* in = fopen ("in.txt", "r");
    int sum = 0;
    while (!feof (in))
    {
        char string[10]{};
        fscanf (in, "%s", string);
        sum += atoi (string);
    }
    printf ("%d", sum);
}