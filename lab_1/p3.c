//
// Created by Lucas on 2/24/2025.
//
#include <stdio.h>

int main() {
    int number, cont=0, copy;
    printf("Enter a number: ");
    scanf("%d", &number);
    copy = number;
    while (number != 0) {
        if (number % 2 == 1) {
            cont++;
        }
        number = number / 2;
    }
    printf("The number of 1's in binary of %d is %d", copy, cont);
}