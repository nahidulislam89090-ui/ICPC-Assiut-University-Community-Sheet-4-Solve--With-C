#include <stdio.h>
#include <string.h>

int main()
{
    int N, Q;
    scanf("%d %d", &N, &Q);

    char S[1005];
    scanf("%s", S);

    while (Q--)
    {
        char command[20];
        scanf("%s", command);

        if (strcmp(command, "pop_back") == 0)
        {
            int len = strlen(S);
            S[len - 1] = '\0';
        }

        else if (strcmp(command, "front") == 0)
        {
            printf("%c\n", S[0]);
        }

        else if (strcmp(command, "back") == 0)
        {
            int len = strlen(S);
            printf("%c\n", S[len - 1]);
        }

        else if (strcmp(command, "sort") == 0)
        {
            int l, r;
            scanf("%d %d", &l, &r);

            if (l > r)
            {
                int temp = l;
                l = r;
                r = temp;
            }

            l--;
            r--;

            for (int i = l; i <= r; i++)
            {
                for (int j = i + 1; j <= r; j++)
                {
                    if (S[i] > S[j])
                    {
                        char temp = S[i];
                        S[i] = S[j];
                        S[j] = temp;
                    }
                }
            }
        }

        else if (strcmp(command, "reverse") == 0)
        {
            int l, r;
            scanf("%d %d", &l, &r);

            if (l > r)
            {
                int temp = l;
                l = r;
                r = temp;
            }

            l--;
            r--;

            while (l < r)
            {
                char temp = S[l];
                S[l] = S[r];
                S[r] = temp;

                l++;
                r--;
            }
        }

        else if (strcmp(command, "print") == 0)
        {
            int pos;
            scanf("%d", &pos);

            printf("%c\n", S[pos - 1]);
        }

        else if (strcmp(command, "substr") == 0)
        {
            int l, r;
            scanf("%d %d", &l, &r);

            if (l > r)
            {
                int temp = l;
                l = r;
                r = temp;
            }

            for (int i = l - 1; i <= r - 1; i++)
            {
                printf("%c", S[i]);
            }

            printf("\n");
        }

        else if (strcmp(command, "push_back") == 0)
        {
            char x;
            scanf(" %c", &x);

            int len = strlen(S);
            S[len] = x;
            S[len + 1] = '\0';
        }
    }

    return 0;
}