#include <stdio.h>
#include <string.h>

int main()
{
    int n;
    scanf("%d", &n);

    while (n--)
    {
        char s[1005], t[1005];

        scanf("%s %s", s, t);

        int len_s = strlen(s);
        int len_t = strlen(t);

        int i = 0;

        // print first half pattern
        while (i < len_s || i < len_t)
        {
            if (i < len_s)
                printf("%c", s[i]);

            if (i < len_t)
                printf("%c", t[i]);

            i++;
        }

        printf("\n");
    }

    return 0;
}