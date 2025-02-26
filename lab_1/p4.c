//
// Created by Lucas on 2/24/2025.
//
#include <stdio.h>

int main() {
    int year;
    printf("Enter a year: ");
    scanf("%d", &year);
    if (year < 1876)
        printf("Invalid input, the year should be greater or equal to 1876");
    int A = year % 19;
    int B = year % 4;
    int C = year % 7;
    int D = (19*A + 24) % 30;
    int E = (2*B + 4*C + 6*D + 5) % 7;
    int date = (22 + E+D);
    char* str1 = "March";
    char* str2 = "April";
    if (date > 31) {
        date  = date % 31;
        printf("In %d the Easter date is %s %d", year, str2, date);
    }
    else {
        printf("In %d the Easter date is %s %d", year, str1, date);
    }
}