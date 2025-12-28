#ifndef BIGINT_H
#define BIGINT_H

#include <cstdint>
#include <vector>
#include <cstdio>

/*
 * bigint.h
 * simple arbitrary-precision integer
 * kernel-style: explicit, no STL magic beyond vector
 */

class BigInt {
public:
    std::vector<uint32_t> digits;

    BigInt(uint64_t n = 0);
    void print() const;
    BigInt operator*(const BigInt &other) const;
    BigInt operator+(const BigInt &other) const;
};

#endif

