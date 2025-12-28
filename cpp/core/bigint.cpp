#include "bigint.h"

BigInt::BigInt(uint64_t n) {
    while (n) {
        digits.push_back(n & 0xFFFFFFFF);
        n >>= 32;
    }
    if (digits.empty()) digits.push_back(0);
}

void BigInt::print() const {
    for (auto it = digits.rbegin(); it != digits.rend(); ++it)
        std::printf("%u ", *it);
    std::printf("\n");
}

BigInt BigInt::operator*(const BigInt &other) const {
    BigInt result(0);
    result.digits.resize(digits.size() + other.digits.size(), 0);
    for (size_t i = 0; i < digits.size(); i++) {
        uint64_t carry = 0;
        for (size_t j = 0; j < other.digits.size(); j++) {
            uint64_t sum = uint64_t(digits[i]) * other.digits[j] + result.digits[i+j] + carry;
            result.digits[i+j] = sum & 0xFFFFFFFF;
            carry = sum >> 32;
        }
        size_t idx = i + other.digits.size();
        while (carry) {
            uint64_t sum = result.digits[idx] + carry;
            result.digits[idx] = sum & 0xFFFFFFFF;
            carry = sum >> 32;
            idx++;
        }
    }
    return result;
}

BigInt BigInt::operator+(const BigInt &other) const {
    BigInt result;
    size_t n = std::max(digits.size(), other.digits.size());
    result.digits.resize(n, 0);
    uint64_t carry = 0;
    for (size_t i = 0; i < n; i++) {
        uint64_t sum = carry;
        if (i < digits.size()) sum += digits[i];
        if (i < other.digits.size()) sum += other.digits[i];
        result.digits[i] = sum & 0xFFFFFFFF;
        carry = sum >> 32;
    }
    if (carry) result.digits.push_back(carry);
    return result;
}

