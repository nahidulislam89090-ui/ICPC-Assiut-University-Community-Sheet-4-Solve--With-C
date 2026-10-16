#include <stdio.h>
#include <ctype.h>

int main()
{
    char s[1000005];

    fgets(s, sizeof(s), stdin);

    int count = 0;

    for (int i = 0; s[i] != '\0'; i++)
    {
        if (isalpha(s[i]) && (i == 0 || !isalpha(s[i - 1])))
        {
            count++;
        }
    }

    printf("%d", count);

    return 0;
}