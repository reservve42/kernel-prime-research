#include "prime.h"
#include "bigint.h"
#include <cstdio>

int main() {
    uint64_t n = 1000003;
    printf("Testing number: %llu\n", (unsigned long long)n);
    printf("prime? %s\n", is_prime(n) ? "yes" : "no");

    BigInt a(1234567890123456789ULL);
    BigInt b(9876543210987654321ULL);
    BigInt c = a * b;

    printf("bigint multiplication result: ");
    c.print();

    return 0;
}

