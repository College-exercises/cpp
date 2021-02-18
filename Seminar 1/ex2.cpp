#include <iostream>
#include <fstream>
#include <cstring>
int main()
{
    FILE* in  = fopen ("in.txt", "r");
    char words[55][20]{};
    int i = 0;

    while (!feof (in))
        fscanf (in, "%s", words[i++]);

    for (int j = 0; j < i - 1; j++)
        for (int k = j + 1; k < i; k++)
            if (strlen (words[j]) < strlen (words[k]))
                std::swap (words[j], words[k]);
            else if (strlen (words[j]) == strlen (words[k]))
                if (strcmp (words[j], words[k]) > 0)
                    std::swap (words[j], words[k]);

    for (int j = 0; j < i; j++)
        printf ("%s\n", words[j]);
}