// SPDX-License-Identifier: GPL-2.0-or-later
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

#ifndef BIGINT_H
#define BIGINT_H

#include <cstdint>
#include <vector>
#include <cstdio>

/*
 * bigint.h
 * simple arbitrary-precision integer
 * kernel: explicit, no STL magic beyond vector
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

