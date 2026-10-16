#include<stdio.h>
#include<string.h>

int main()
{
    int t;

    // t = test case
    scanf("%d", &t);

    while(t--)
    {
        // input string
        char s[100005];
        scanf("%s", s);

        int good=0;

        // check good or bad
        for(int i=0; s[i] !='\0'; i++)
        {
            if(s[i]=='0' && s[i+1]=='1' && s[i+2]=='0' || s[i]=='1' && s[i+1]=='0' && s[i+2]=='1')
            {
                good=1;
                break;
            }
        }

       if(good)
       {
          printf("Good\n");
       } 
       else
       {
          printf("Bad\n");
       }
    }

    return 0;
}