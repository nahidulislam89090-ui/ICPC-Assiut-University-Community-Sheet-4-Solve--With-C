#include <stdio.h>

int main()
{
    char s[10005];

    scanf("%s", s);

    int i = 0;

    while (s[i] != '\0')
    {
        if (s[i] == 'E' && s[i + 1] == 'G' && s[i + 2] == 'Y' && s[i + 3] == 'P' && s[i + 4] == 'T')
        {
            printf(" ");
            i = i + 5;
        }
        else
        {
            printf("%c", s[i]);
            i++;
        }
    }

    return 0;
}