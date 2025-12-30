#include <chrono>
#include <cstdio>
#include <cstdint>
#include <random>
#include "C_prime.h"

uint64_t modmul(uint64_t a, uint64_t b, uint64_t mod) {
    uint64_t result = 0;
    a %= mod;
    while (b) {
        if (b & 1) result = (result + a) % mod;
        a = (a << 1) % mod;
        b >>= 1;
    }
    return result;
}

uint64_t modpow(uint64_t base, uint64_t exp, uint64_t mod) {
    uint64_t result = 1;
    base %= mod;
    while (exp) {
        if (exp & 1) result = modmul(result, base, mod);
        base = modmul(base, base, mod);
        exp >>= 1;
    }
    return result;
}

bool miller_rabin(uint64_t n, int iter = 5) {
    if (n < 2) return false;
    if (n == 2 || n == 3) return true;
    if (n % 2 == 0) return false;

    uint64_t d = n - 1;
    int s = 0;
    while ((d & 1) == 0) { d >>= 1; s++; }

    std::mt19937_64 rng(std::random_device{}());
    std::uniform_int_distribution<uint64_t> dist(2, n - 2);

    for (int i = 0; i < iter; i++) {
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

int main() {
    uint64_t start = 2, end = 10000000, prev_prime = 0;
    auto global_start = std::chrono::high_resolution_clock::now();

    for (uint64_t n = start; n <= end; n++) {
        auto t0 = std::chrono::high_resolution_clock::now();
        if (miller_rabin(n, 7)) {
            auto t1 = std::chrono::high_resolution_clock::now();
            std::printf("%llu prime, %.6f s\n", n, std::chrono::duration<double>(t1 - t0).count());
            if (prev_prime && n - prev_prime == 2)
                std::printf("Twin primes: %llu and %llu\n", prev_prime, n);
            if ((n & (n + 1)) == 0)
                std::printf("Mersenne candidate: 2^%llu - 1 = %llu\n", (unsigned long long)(__builtin_ctzll(n+1)), n);
            prev_prime = n;
        }
    }

    auto global_end = std::chrono::high_resolution_clock::now();
    std::printf("Search completed in %.6f s\n", std::chrono::duration<double>(global_end - global_start).count());
    return 0;
}
