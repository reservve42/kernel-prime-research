#include <chrono>
#include <cstdio>
#include "C_prime.h"

int main() {
    uint64_t numbers[] = {1000003, 1000033, 1000037};
    for (auto n : numbers) {
        auto start = std::chrono::high_resolution_clock::now();
        bool res = is_prime(n);
        auto end = std::chrono::high_resolution_clock::now();
        double elapsed = std::chrono::duration<double>(end - start).count();
        std::printf("number: %llu, prime: %s, time: %.6f s\n",
                    (unsigned long long)n, res ? "yes" : "no", elapsed);
    }
    return 0;
}
