#include <stdio.h>

int main() {
    long long n;
    scanf("%lld", &n);

    int count[26] = {0};
    int c;
    long long i = 0;

    // consume the newline/whitespace left after scanf
    while ((c = getchar()) != EOF && (c == ' ' || c == '\n' || c == '\r' || c == '\t'));

    // count characters as we read them, without storing the string
    while (c != EOF && i < n) {
        if (c >= 'a' && c <= 'z') {
            count[c - 'a']++;
            i++;
        }
        if (i < n) {
            c = getchar();
        }
    }

    // print sorted result directly from counts
    for (int letter = 0; letter < 26; letter++) {
        for (int j = 0; j < count[letter]; j++) {
            putchar('a' + letter);
        }
    }
    putchar('\n');

    return 0;
}