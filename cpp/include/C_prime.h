#ifndef PRIME_H
#define PRIME_H

#include <cstdint>

/*
 * prime.h
 * naive and deterministic primality and factorization
 * kernel-inspired style
 */

static inline bool is_prime(uint64_t n) {
    if (n < 2) return false;
    if (n == 2) return true;
    if ((n & 1) == 0) return false;
    for (uint64_t i = 3; i * i <= n; i += 2)
        if (n % i == 0) return false;
    return true;
}

#endif

