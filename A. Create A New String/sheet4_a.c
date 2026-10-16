#include<stdio.h>
int main()
{
    char s[1005];
    char t[1005];

    int count_s=0;
    int count_t=0;

    scanf("%s", &s);
    scanf("%s", &t);

    int i=0;

    while(s[i] != '\0')
    {
        count_s++;
        i++;
    }

    int j=0;

    while(t[j] != '\0')
    {
        count_t++;
        j++;
    }

    printf("%d %d\n", count_s, count_t);
    printf("%s %s\n", s,t);

    return 0;
}