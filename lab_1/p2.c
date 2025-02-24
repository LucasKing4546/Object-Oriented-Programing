//
// Created by Lucas on 2/24/2025.
//
#include <stdio.h>

int main() {
    for (int i=9; i>=0; i--) {
        for (int j=9; j>=0 && j!=i; j--) {
            for (int k=9; k>=0 && k!=i && k!=j; k--) {
                int l = 24 - i - j - k;
                if (l < 10 && l!=i && l!=j && l!=k)
                    printf("%d%d%d%d\n", i,j,k,l);
            }
        }
    }
}