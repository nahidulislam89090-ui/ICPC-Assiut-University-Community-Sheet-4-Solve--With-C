#include<stdio.h>
#include<string.h>
int main()
{
    char s[10000005];
    int sum=0;

    scanf("%s", s);

    int i=0;

    while(s[i] != '\0')
    {
        sum = sum + (s[i] - '0');
        i++;
    }

    printf("%d\n", sum);

    return 0;
}