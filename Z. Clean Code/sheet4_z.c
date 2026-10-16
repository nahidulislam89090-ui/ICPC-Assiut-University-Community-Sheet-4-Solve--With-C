#include <stdio.h>

int main()
{
    char s[100000];
    char out[100000];

    int i = 0, j = 0;
    int block = 0;
    int inString = 0;
    int inChar = 0;

    while (fgets(s, sizeof(s), stdin))
    {
        i = 0;

        while (s[i] != '\0')
        {
            /* Inside block comment */
            if (block)
            {
                if (s[i] == '*' && s[i + 1] == '/')
                {
                    block = 0;
                    i += 2;
                }
                else
                {
                    i++;
                }
            }

            /* Inside string */
            else if (inString)
            {
                out[j++] = s[i];

                if (s[i] == '\\' && s[i + 1] != '\0')
                {
                    out[j++] = s[i + 1];
                    i += 2;
                }
                else if (s[i] == '"')
                {
                    inString = 0;
                    i++;
                }
                else
                {
                    i++;
                }
            }

            /* Inside character */
            else if (inChar)
            {
                out[j++] = s[i];

                if (s[i] == '\\' && s[i + 1] != '\0')
                {
                    out[j++] = s[i + 1];
                    i += 2;
                }
                else if (s[i] == '\'')
                {
                    inChar = 0;
                    i++;
                }
                else
                {
                    i++;
                }
            }

            /* Start single line comment */
            else if (s[i] == '/' && s[i + 1] == '/')
            {
                while (s[i] != '\0' && s[i] != '\n')
                    i++;
            }

            /* Start block comment */
            else if (s[i] == '/' && s[i + 1] == '*')
            {
                block = 1;
                i += 2;
            }

            /* Start string */
            else if (s[i] == '"')
            {
                inString = 1;
                out[j++] = s[i++];
            }

            /* Start character */
            else if (s[i] == '\'')
            {
                inChar = 1;
                out[j++] = s[i++];
            }

            /* Normal character */
            else
            {
                out[j++] = s[i++];
            }
        }
    }

    out[j] = '\0';

    /* Print only non-empty lines */
    int start = 0;

    while (start < j)
    {
        int end = start;
        int hasCode = 0;

        while (end < j && out[end] != '\n')
        {
            if (out[end] != ' ' &&
                out[end] != '\t' &&
                out[end] != '\r')
            {
                hasCode = 1;
            }

            end++;
        }

        if (hasCode)
        {
            for (i = start; i < end; i++)
                putchar(out[i]);

            putchar('\n');
        }

        if (end < j)
            end++;

        start = end;
    }

    return 0;
}