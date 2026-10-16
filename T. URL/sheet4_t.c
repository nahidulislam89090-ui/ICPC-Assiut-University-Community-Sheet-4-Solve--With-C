#include <stdio.h>
#include <string.h>

int main()
{
    char s[10005];

    scanf("%s", s);

    char *p = strchr(s, '?');

    p++;

    printf("username: ");
    p = strstr(p, "username=") + 9;
    while (*p != '&')
        printf("%c", *p++);
    printf("\n");

    printf("pwd: ");
    p = strstr(p, "pwd=") + 4;
    while (*p != '&')
        printf("%c", *p++);
    printf("\n");

    printf("profile: ");
    p = strstr(p, "profile=") + 8;
    while (*p != '&')
        printf("%c", *p++);
    printf("\n");

    printf("role: ");
    p = strstr(p, "role=") + 5;
    while (*p != '&')
        printf("%c", *p++);
    printf("\n");

    printf("key: ");
    p = strstr(p, "key=") + 4;
    while (*p != '\0')
        printf("%c", *p++);
    printf("\n");

    return 0;
}