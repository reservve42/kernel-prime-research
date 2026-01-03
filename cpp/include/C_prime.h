/*
 * Kernel Cryptography Research Project
 *
 * Low-level cryptography algorithms and protocols
 * for Linux kernel experimentation.
 *
 * Project focuses on:
 *     - Prime number computations
 *     - Cryptographic number theory
 *     - Computational hardness
 *     - Encrypted data handling and protocol tracing (e.g., CP2A)
 *
 * Documentation and research notes are maintained internally.
 *
 * Copyright (c) 2025 Luís Henrique (Heanrig) <henriqueeeee85@gmail.com>
 *
 * This project is intended for research and educational purposes.
 * Redistribution and modification are allowed under GPL-2.0-or-later.
 */


#ifndef C_PRIME_H
#define C_PRIME_H

#include <cstdint>
#include <random>

namespace prime {

/* Modular multiplication to avoid overflow */
static inline uint64_t modmul(uint64_t a, uint64_t b, uint64_t mod) {
    uint64_t result = 0;
    a %= mod;
    while (b) {
        if (b & 1) result = (result + a) % mod;
        a = (a << 1) % mod;
        b >>= 1;
    }
    return result;
}

/* Modular exponentiation */
static inline uint64_t modpow(uint64_t base, uint64_t exp, uint64_t mod) {
    uint64_t result = 1;
    base %= mod;
    while (exp) {
        if (exp & 1) result = modmul(result, base, mod);
        base = modmul(base, base, mod);
        exp >>= 1;
    }
    return result;
}

/* Miller-Rabin primality test */
static inline bool is_prime(uint64_t n, int iterations = 7) {
    if (n < 2) return false;
    if (n == 2 || n == 3) return true;
    if ((n & 1) == 0) return false;

    uint64_t d = n - 1;
    int s = 0;
    while ((d & 1) == 0) { d >>= 1; s++; }

    std::mt19937_64 rng(std::random_device{}());
    std::uniform_int_distribution<uint64_t> dist(2, n - 2);

    for (int i = 0; i < iterations; i++) {
        uint64_t a = dist(rng);
        uint64_t x = modpow(a, d, n);
        if (x == 1 || x == n - 1) continue;
        bool cont = false;
        for (int r = 1; r < s; r++) {
            x = modmul(x, x, n);
            if (x == n - 1) { cont = true; break; }
        }
        if (!cont) return false;
    }
    return true;
}

} // namespace prime

/* For compatibility with old code */
static inline bool is_prime(uint64_t n) {
    return prime::is_prime(n);
}

#endif
