#include<stdio.h>
#include<string.h>
int main()
{
    char s[100005];
    long long n;

    scanf("%lld", &n);
    scanf("%s", s);

    long long result = 0;
    char last = '\0';

    for(int i=0; i<n; i++)
    {
        if(s[i] != last)
        {
            result++;
            last = s[i];
        }
    }

    printf("%lld", result);

    return 0;
}