#include<stdio.h>
#include<string.h>

int main()
{
    char s[1000005];

    fgets(s, sizeof(s), stdin);

    int n = strlen(s);
    int start = 0;

    for(int i=0; i<n; i++)
    {
        if(s[i] == ' ' || s[i] == '\n' || s[i] == '\0')
        {
            int left = start;
            int right = i-1;

            while (left < right)
            {
                char temp = s[left];
                s[left] = s[right];
                s[right] = temp;

                left++;
                right--;
            }

            if(s[i] == '\n')
            {
                s[i] = '\0';
            }

            start = i+1;   
        }
    }

    printf("%s", s);

    return 0;
}