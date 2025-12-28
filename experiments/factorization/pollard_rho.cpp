/*
 * pollard_rho.cpp
 * simple Pollard's Rho factorization
 * kernel-style explicit, reproducible
 */

#include <cstdio>
#include <cstdint>
#include <cstdlib>

uint64_t gcd(uint64_t a, uint64_t b) {
    while (b) { uint64_t t = b; b = a % b; a = t; }
    return a;
}

uint64_t pollard_rho(uint64_t n) {
    if (n % 2 == 0) return 2;
    uint64_t x = 2, y = 2, d = 1;
    uint64_t c = 1;
    while (d == 1) {
        x = (x*x + c) % n;
        y = (y*y + c) % n; y = (y*y + c) % n;
        d = gcd((x>y?x-y:y-x), n);
    }
    return d;
}

int main() {
    uint64_t n = 8051; // example composite
    uint64_t factor = pollard_rho(n);
    printf("factor of %llu: %llu\n", (unsigned long long)n, (unsigned long long)factor);
    return 0;
}

