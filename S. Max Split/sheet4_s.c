#include<stdio.h>
#include<string.h>

int main()
{
    char s[1005];

    scanf("%s", s);

    int count = 0;
    int start = 0;
    int total = 0;

    // firsr count how many balance string we can make
    for(int i=0; s[i] != '\0'; i++)
    {
        if(s[i] == 'L')
        {
            count ++;
        }
        else
        {
            count--;
        }
        if(count == 0)
        {
            total++;
        }
    }

    printf("%d\n", total);

    // print the balance string
    count = 0;
    start = 0;

    for(int i=0; s[i] != '\0'; i++)
    {
        if(s[i] == 'L')
        {
            count++;
        }
        else
        {
            count--;
        }
        if(count == 0)
        {
            for(int j=start; j<=i; j++)
            {
                printf("%c", s[j]);
            }
            
            printf("\n");
            start = i+1;
        }
    }

    return 0;
}