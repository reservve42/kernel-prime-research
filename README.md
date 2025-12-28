# prime-kernel-research

## Overview

This project constitutes an **independent, self-guided research initiative** into the computational intricacies of **prime number theory, cryptographic hardness, and low-level systems computation**, developed in a **kernel-inspired C++ and Fortran environment**.  
Special attention is given to **deterministic and probabilistic primality tests**, **factorization algorithms**, and **arbitrary-precision arithmetic**, laying groundwork for reproducible experimentation.

大阪弁で説明すると、
「このプロジェクトは、素数の複雑さや暗号の難易度を低レベル環境で研究する独立型やねん。C++とFortranでカーネル風に書いてて、再現性のある実験環境を構築しとるんや。」

---

## Theoretical Foundations

### Prime Number Complexity

The project explores the computational complexity underlying prime distribution. This includes:

- **Naïve trial division** as baseline.  
- **Pollard's Rho and advanced factorization** for medium-sized composites.  
- **Miller–Rabin probabilistic primality** for large integers.  

The work integrates concepts from **Ramanujan’s formulas for prime sums and partitions**, with attention to **modular arithmetic patterns**, and considers empirical evidence relating to the **Riemann Hypothesis**.

素数分布の複雑性については、
「ラマヌジャンの公式や分割理論を使って、モジュラー演算のパターンを解析しとるんや。リーマン仮説との関係も考慮しつつ、計算実験で確認する感じや。」

---

### Cryptographic Implications

The project assesses:

- **Hardness assumptions for RSA-like moduli**, leveraging large semi-primes.  
- **Timing attack susceptibility** in kernel-level computations.  
- **Randomized prime generation** for cryptographic simulations.  

All computations are executed with **high-precision big integers**, designed in a **kernel-style C++ class (`BigInt`)** and **Fortran module (`bigint_mod`)**, explicitly managing memory and low-level arithmetic to avoid hidden optimisation biases.

暗号への応用では、
「大きな半素数を使ったRSAの難易度を測定し、タイミング攻撃にも注意して計算してまうんや。BigIntクラスとFortranモジュールで、高精度計算をちゃんと管理しとるんや。」

---

## Software Architecture

### C++ (kernel-inspired)

- **`cpp/core/prime.cpp`**: primality, factorization, deterministic and probabilistic algorithms  
- **`cpp/core/bigint.cpp`**: arbitrary-precision integer arithmetic with explicit carry management  
- **`cpp/include/*.h`**: reusable headers, inline functions, kernel-style modularity  
- **`cpp/tools/benchmarks.cpp`**: micro-benchmarks for timing analysis

### Fortran

- **`fortran/modules/prime_mod.f90`**: primality test functions with explicit integer kind management  
- **`fortran/modules/bigint_mod.f90`**: high-precision integer arithmetic for numerical experiments  
- **`fortran/main.f90`**: orchestrates experiments, logs results for reproducibility

大阪弁でいうと、
「C++もFortranも、カーネル風にモジュール化して、再現性ある実験用の高精度計算をしとるんや。」

---

## Experiments

### Timing Analysis

- Execution time measurements using `chrono` and `rdtsc` in C++  
- Benchmarks include naive, Pollard-Rho, and Miller–Rabin tests  
- Logging performed in CSV for later statistical analysis

### Factorization Study

- Naive trial division vs Pollard-Rho performance  
- Analysis of semi-primes (RSA-sized integers)  
- Integration of big integer arithmetic for numbers beyond 64 bits

実験内容は、
「素因数分解の性能を比較して、半素数（RSAサイズ）の計算もやっとるんや。結果はCSVに保存して統計解析に使う感じや。」

---

## Environments

- **Gentoo / FreeBSD**: controlled OS environments for low-level benchmarking  
- **Docker**: reproducible containers to isolate dependencies  
- **ISO images**: minimal stage3 Gentoo with precompiled binaries and scripts

大阪弁でいうと、
「どの環境でも同じ結果出るように、GentooとFreeBSDでベンチマークして、DockerやISOで再現性確保しとるんや。」

---

## Research Status

- Active workspace; **no publications yet**  
- Framework prepared for **probabilistic primality tests, advanced bigint arithmetic, and timing/security analysis**  
- Base ready for integration with cryptographic simulations and kernel-level scheduling studies

---

## Future Directions

1. **High-performance big integer arithmetic** for cryptography  
2. **Probabilistic primality testing** beyond Miller-Rabin  
3. **Timing and cache side-channel analysis** in virtualized Gentoo / FreeBSD  
4. **Integration with AI-assisted pattern recognition** in prime distributions (Ramanujan-inspired sequences)

将来的には、
「暗号用の大整数演算や、素数パターン解析をAIと組み合わせて研究するんや。」

---

## References

- Rob Pike & Brian W. Kernighan (1984) “The Unix Programming Environment” — fundamental principles of **process control, IPC, and shell scripting automation**  
- Garey, M. R., & Johnson, D. S. (1979) “Computers and Intractability: A Guide to the Theory of NP-Completeness” — theoretical foundations for **computational hardness and algorithmic intractability**  
- Zhirkov, I. (2016) “Low-Level Programming: C, Assembly, and Program Execution on Intel® 64 Architecture” — deep dive into **systems programming, Linux internals, and low-level computation**  
- Cormen, T., Leiserson, C., Rivest, R., Stein, C. (2009) “Introduction to Algorithms” — **algorithm design, complexity analysis, and data structures**  
- Menezes, A., van Oorschot, P., Vanstone, S. (1996) “Handbook of Applied Cryptography” — **applied cryptography, modular arithmetic, and number-theoretic foundations**  
- Ramanujan, S. (1913–1920) “Collected Papers” — advanced **partition functions and prime patterns**  
- Riemann, B. (1859) “On the Number of Primes Less Than a Given Magnitude” — **analytic foundations of prime distribution and zeta function theory**

大阪弁で言うと、
「このプロジェクトは、Unixプログラミング環境やNP完全性の理論、低レベルプログラミングの本を参考にしとるんや。暗号や素数理論の応用も意識してるで。」

---

## License

This repository is licensed under the **GNU Lesser General Public License v2.1 (LGPL v2.1)**, ensuring that **all modifications to the library/core modules remain open**, while permitting **linking from proprietary projects**.

---

## Build & Run Examples

### C++

```bash
g++ -O2 cpp/main.cpp cpp/core/bigint.cpp cpp/core/prime.cpp -o prime_cpp
./prime_cpp
```
### Fortran

```bash
gfortran fortran/main.f90 fortran/modules/bigint_mod.f90 fortran/modules/prime_mod.f90 -o prime_fortran
./prime_fortran
```
### Docker

```bash
docker build -t prime-kernel-research ./docker
docker run -it prime-kernel-research
```
