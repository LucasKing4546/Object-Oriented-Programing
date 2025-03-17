//
// Created by Lucas on 3/3/2025.
//
#include <stdio.h>
#include <stdlib.h>

const char* strchr(const char* str, int c) {
    const char* p = str;
    while (*p != '\0') {
        if (*p == c)
            return p;
        p++;
    }
    return NULL;
}
int main() {
    char str[] = "Hello World!";
    printf("%s\n", strchr(str, 'W'));
}
