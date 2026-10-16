#include<stdio.h>
#include<string.h>

int main()
{
    char s[100005];
    char key[] = "PgEfTYaWGHjDAmxQqFLRpCJBownyUKZXkbvzIdshurMilNSVOtec#@_!=.+-*/";
    char original[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    
    int n;

    scanf("%d", &n);
    scanf("%s", s);

    int i = 0;

    for(int i=0; s[i] != '\0'; i++)
    {
        for(int j=0; original[j] != '\0'; j++)
        {
            if(n==1)
            {
                if(s[i] == original[j])
                {
                    printf("%c", key[j]);
                    break;
                }
            }
            else
            {
                if(s[i] == key[j])
                {
                    printf("%c", original[j]);
                    break;
                }
            }
        }
    }

    return 0;
}