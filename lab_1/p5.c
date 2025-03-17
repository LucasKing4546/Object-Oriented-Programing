//
// Created by Lucas on 3/1/2025.
//
#include <stdio.h>
#include <string.h>

int main() {
    char s[250];
    int n;
    scanf("%d", &n);
    fgets(s, sizeof(s), stdin);
    for (int i = 0; i < strlen(s); i++) {
        if (s[i] >= 'a' && s[i] <= 'z') {
            int c  = s[i] - n;
            if (c < 'a')
                c += 26;
            s[i] = (char) c;
        }
    }
    printf("%s", s);
}