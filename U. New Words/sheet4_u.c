#include <stdio.h>

int main()
{
    char s[1000005];

    scanf("%s", s);

    int e = 0, g = 0, y = 0, p = 0, t = 0;

    int i = 0;

    while (s[i] != '\0')
    {
        if (s[i] == 'E' || s[i] == 'e')
            e++;

        else if (s[i] == 'G' || s[i] == 'g')
            g++;

        else if (s[i] == 'Y' || s[i] == 'y')
            y++;

        else if (s[i] == 'P' || s[i] == 'p')
            p++;

        else if (s[i] == 'T' || s[i] == 't')
            t++;

        i++;
    }

    int ans = e;

    if (g < ans) 
    {
        ans = g;
    }
    if (y < ans) 
    {
        ans = y;
    }
    if (p < ans) 
    {
        ans = p;
    }
    if (t < ans) 
    {
        ans = t;
    }

    printf("%d\n", ans);

    return 0;
}