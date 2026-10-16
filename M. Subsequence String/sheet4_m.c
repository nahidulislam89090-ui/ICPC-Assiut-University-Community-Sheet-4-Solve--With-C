#include<stdio.h>
#include<string.h>

int main()
{
    char s[10005];
    char target[] = "hello";

    scanf("%s", s);

    int i=0;
    int j=0;

    while (s[i] != '\0' && target[j] != '\0')
    {
        if(s[i] == target[j])
        {
            j++;
        }

        i++;
    }

    if(target[j] == '\0')
    {
        printf("YES\n");
    }
    else
    {
        printf("NO\n");
    }

    return 0;
}