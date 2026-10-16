#include<stdio.h>
#include<string.h>
int main()
{
    int t;

    // t = test case
    scanf("%d", &t);

    while(t--)
    {
        char s[1005];

        scanf("%s", s);

        int x = strlen(s);

        if(x<=10)
        {
            printf("%s\n", s);
        }
        else
        {
            int y = x-2;

            printf("%c%d%c\n", s[0], y, s[x-1]);
        }
    }

    return 0;
}