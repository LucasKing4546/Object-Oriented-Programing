//
// Created by Lucas on 3/3/2025.
//
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

void find_all(const char * str, char character, int* positions, unsigned int cap, unsigned int *l) {
    const char* p = str;
    while (*p != '\0') {
        const char* c = strchr(p, character);
        if (c == NULL || *l + 1 > cap) {
            break;
        }
        positions[(*l)++] = (int)(c-str);
        p = c + 1;
    }
}


int main() {
    const char* str = "hello world";
    char character = 'o';
    int* positions = (int*) calloc(10, sizeof(int));;
    unsigned int length = 0;
    find_all(str, character, positions, 10, &length);
    printf("Length: %u\n", length);
    for (int i = 0; i < length; i++) {
        printf("%d ", positions[i]);
    }
    free(positions);
}