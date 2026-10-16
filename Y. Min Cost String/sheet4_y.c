#include <stdio.h>

#define INF 1000000000000000000LL

char s[1000010];
unsigned char ch[26000000];

int main()
{
    int n = 0;
    int w[26], ord[26];
    long long cur[26], nxt[26];
    long long Lv[26], Rv[26];
    int Li[26], Ri[26];

    scanf("%1000005s", s);
    while (s[n]) n++;

    for (int i = 0; i < 26; i++)
    {
        scanf("%d", &w[i]);
        ord[i] = i;
    }

    /* sort letters by (weight, index) */
    for (int i = 1; i < 26; i++)
    {
        int x = ord[i];
        int j = i - 1;
        while (j >= 0 && (w[ord[j]] > w[x] || (w[ord[j]] == w[x] && ord[j] > x)))
        {
            ord[j + 1] = ord[j];
            j--;
        }
        ord[j + 1] = x;
    }

    /* last position */
    for (int c = 0; c < 26; c++)
    {
        if (s[n - 1] == '?' || s[n - 1] - 'a' == c)
            nxt[c] = 0;
        else
            nxt[c] = INF;
    }

    for (int i = n - 2; i >= 0; i--)
    {
        if (s[i] != '?')
        {
            int c = s[i] - 'a';
            for (int x = 0; x < 26; x++) cur[x] = INF;

            long long best = INF;
            int bd = 0;
            for (int d = 0; d < 26; d++)
            {
                if (nxt[d] >= INF) continue;
                int df = w[c] > w[d] ? w[c] - w[d] : w[d] - w[c];
                long long v = df + nxt[d];
                if (v < best)
                {
                    best = v;
                    bd = d;
                }
            }
            cur[c] = best;
            ch[(long long)i * 26 + c] = (unsigned char)bd;
        }
        else
        {
            /* prefix minima of nxt[d] - w[d] in sorted order */
            for (int k = 0; k < 26; k++)
            {
                int d = ord[k];
                long long v = nxt[d] - w[d];
                if (k == 0 || v < Lv[k - 1] || (v == Lv[k - 1] && d < Li[k - 1]))
                {
                    Lv[k] = v;
                    Li[k] = d;
                }
                else
                {
                    Lv[k] = Lv[k - 1];
                    Li[k] = Li[k - 1];
                }
            }

            /* suffix minima of nxt[d] + w[d] in sorted order */
            for (int k = 25; k >= 0; k--)
            {
                int d = ord[k];
                long long v = nxt[d] + w[d];
                if (k == 25 || v < Rv[k + 1] || (v == Rv[k + 1] && d < Ri[k + 1]))
                {
                    Rv[k] = v;
                    Ri[k] = d;
                }
                else
                {
                    Rv[k] = Rv[k + 1];
                    Ri[k] = Ri[k + 1];
                }
            }

            for (int k = 0; k < 26; k++)
            {
                int c = ord[k];
                long long v1 = Lv[k] + w[c];
                long long v2 = Rv[k] - w[c];
                long long v;
                int d;
                if (v1 < v2 || (v1 == v2 && Li[k] < Ri[k]))
                {
                    v = v1;
                    d = Li[k];
                }
                else
                {
                    v = v2;
                    d = Ri[k];
                }
                cur[c] = v;
                ch[(long long)i * 26 + c] = (unsigned char)d;
            }
        }

        for (int c = 0; c < 26; c++)
        {
            nxt[c] = cur[c];
        }
    }

    long long bestCost = INF;
    int c0 = 0;
    for (int c = 0; c < 26; c++)
    {
        if (nxt[c] < bestCost)
        {
            bestCost = nxt[c];
            c0 = c;
        }
    }

    int c = c0;
    s[0] = 'a' + c;
    for (int i = 0; i < n - 1; i++)
    {
        c = ch[(long long)i * 26 + c];
        s[i + 1] = 'a' + c;
    }

    printf("%lld\n%s\n", bestCost, s);
    return 0;
}
