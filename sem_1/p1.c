#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <stdbool.h>

bool isPrime(unsigned int n) {
    if (n <= 1)
        return false;
    if (n == 2)
        return true;
    if (n % 2 == 0)
        return false;
    for (int i = 3; i <= sqrt(n); i+=2) {
        if (n % i == 0) {
            return false;
        }
    }
     return true;
}

void test_prime() {
    assert(isPrime(0) == false);
    assert(isPrime(1) == false);
    assert(isPrime(2));
    assert(isPrime(3));
    assert(isPrime(4) ==  false);
    assert(isPrime(11));
    assert(isPrime(19));
}

int main(void) {
    test_prime();
    return 0;
}
