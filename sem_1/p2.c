//
// Created by Lucas on 3/3/2025.
//
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

unsigned int* SieveOfEratostene(unsigned int n, int* cont) {
    bool* prime = calloc((n+1), sizeof(bool));
    prime[0] = true;
    prime[1] = true;
    *cont = n - 1;
    for (int i = 2; i <= n; i++) {
        if (!prime[i]) {
            for (int j = 2 * i; j <= n; j += i) {
                if (!prime[j] == false) {
                    cont--;
                }
                prime[j] = true;
            }
        }
    }
    unsigned int* primes = malloc(*cont * sizeof(unsigned int));
    *cont = 0;
    for (int i = 2; i <= n; i++) {
        if (!prime[i]) {
            primes[(*cont)++] = i;
        }
    }
    free(prime);
    return primes;
}

int main() {
    unsigned int n;
    scanf("%u", &n);
    int cont = 0;
    unsigned int* primes = SieveOfEratostene(n, &cont);
    for (int i = 0; i < cont; i++) {
        printf("%u\n", primes[i]);
    }
    free(primes);
}