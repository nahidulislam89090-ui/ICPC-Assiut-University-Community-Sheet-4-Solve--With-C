#include<stdio.h>
#include<string.h>

int main()
{
    char a[100], b[100];

    scanf("%s %s", a, b);

    int x = strlen(a);
    int y = strlen(b);

    printf("%d %d\n", x, y);
    printf("%s%s\n", a, b);

        char temp = a[0];
        a[0] = b[0];
        b[0] = temp;

    printf("%s %s\n", a, b);

    return 0;
}