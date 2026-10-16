#include <stdio.h>

char s[10005], cand[10005], best[10005];

int main() 
{
    int n = 0;
    scanf("%10004s", s);
    while (s[n]) n++;

    if (n == 1) 
    {
        printf("%s\n", s);
        return 0;
    }

    for (int i = 1; i < n; i++) 
    {
        int cnt[26], p = 0;

        /* sort the left part S[0..i) with counting sort */
        for (int c = 0; c < 26; c++) 
        {
            cnt[c] = 0;
        }

        for (int k = 0; k < i; k++) 
        {
            cnt[s[k] - 'a']++;
        }

        for (int c = 0; c < 26; c++)
        {
            for (int t = 0; t < cnt[c]; t++) 
            {
                cand[p++] = 'a' + c;
            }
        }

        /* sort the right part S[i..n) with counting sort */
        for (int c = 0; c < 26; c++) 
        {
            cnt[c] = 0;
        }

        for (int k = i; k < n; k++) 
        {
            cnt[s[k] - 'a']++;
        }

        for (int c = 0; c < 26; c++)
        {
            for (int t = 0; t < cnt[c]; t++) 
            {
                cand[p++] = 'a' + c;
            }
        }   /* <-- this closing brace was missing */

        /* compare cand with best */
        int better = 0;
        if (i == 1) 
        {
            better = 1;
        } 
        else 
        {
            int k = 0;
            while (k < n && cand[k] == best[k]) 
            {
                k++;
            }

            if (k < n && cand[k] < best[k]) 
            {
                better = 1;
            }
        }

        /* copy if smaller */
        if (better)
        {
            for (int k = 0; k < n; k++) 
            {
                best[k] = cand[k];
            }
        }
    }

    best[n] = '\0';
    printf("%s\n", best);
    return 0;
}