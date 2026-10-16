#include <stdio.h>

int main()
{
    long long N;
    scanf("%lld", &N);

    char s[2000005];
    scanf("%s", s);

    int front = 0;
    int back = N;
    int score = 0;

    while (front < back)
    {
        char c = s[front++];

        if (c == 'V')
        {
            score += 5;
        }
        else if (c == 'W')
        {
            score += 2;
        }
        else if (c == 'X')
        {
            if (front < back)
                front++;
        }
        else if (c == 'Y')
        {
            if (front < back)
            {
                s[back++] = s[front++];
            }
        }
        else if (c == 'Z')
        {
            if (front < back)
            {
                if (s[front] == 'V')
                {
                    score /= 5;
                    front++;
                }
                else if (s[front] == 'W')
                {
                    score /= 2;
                    front++;
                }
            }
        }
    }

    printf("%d\n", score);

    return 0;
}