#include<stdio.h>
#include<string.h>

int main()
{
    char s[1005];

    scanf("%s", s);

    // check palindrome.
    int n = strlen(s);
    int check=1;

    for(int i=0; i < n/2; i++)
    {
        if(s[i] != s[n-i-1])
        {
            check=0;
            break;
        }
    }

    //print ans
    if(check)
    {
        printf("YES");
    }
    else
    {
        printf("NO");
    }

    return 0;
}