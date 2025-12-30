# Self Research Prime Kernel applied to Cryptography at all for dummies and self-taught like me

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

## Prime Number Theory and Complexity

Prime number theory lies at the heart of both **analytic number theory** and **computational complexity**, addressing not only the *existence* and *distribution* of primes, but also the *difficulty of computing* their distribution within large ranges of integers. This section provides a dense, detailed, and formal examination of the prime numbers’ complexity, drawing on classical results such as the **Prime Number Theorem** as well as modern insights from information theory and heuristic complexity perspectives.

大阪弁:  
「素数理論は、解析的整数論と計算複雑性の中核をなすもので、素数の存在や分布だけでなく、大きな整数範囲での計算上の困難さも扱うんや。」

---

### 1. Definitions and Preliminaries

A **prime number** is a positive integer \( p > 1 \) with no positive divisors other than 1 and itself. The prime-counting function \( \pi(x) \) denotes the number of primes less than or equal to \( x \). For example, \( \pi(10) = 4 \) because the primes ≤ 10 are 2, 3, 5, and 7.  

The central question of distribution is: *How are primes spread among the natural numbers?* Empirically, primes “thin out” as numbers grow larger, but mathematical theory seeks not just observation but **precise asymptotics and complexity bounds**. :contentReference[oaicite:0]{index=0}

---

### 2. The Prime Number Theorem (PNT)

The **Prime Number Theorem (PNT)** provides the first asymptotic description of the distribution of primes. It states that:

\[
\pi(x) \sim \frac{x}{\ln x}
\]

as \( x \to \infty \), meaning the ratio \( \pi(x) / \big(x / \ln x\big) \) approaches 1 in the limit. In other words, the *probability that a randomly chosen integer less than \( x \)* is prime is approximately \( 1 / \ln x \) for large \( x \). :contentReference[oaicite:1]{index=1}

This result was first proved in 1896 by **Jacques Hadamard** and **Charles de la Vallée‑Poussin** using complex analysis and properties of the **Riemann zeta function**. It formalizes the intuitive observation that primes become less frequent as integers increase. :contentReference[oaicite:2]{index=2}

The PNT can be restated in several equivalent formulations:

- The \( n \)-th prime \( p_n \) satisfies \( p_n \sim n \ln n \).  
- The average gap between consecutive primes near \( x \) is approximately \( \ln x \).  
- Thus, primes have an “average density” inversely proportional to the logarithm of the integer scale.

---

### 3. Complexity Perspectives on Prime Distribution

From a **computational complexity** standpoint, prime distribution also has deep implications. While the PNT provides an asymptotic count of primes, it does *not* directly yield an efficient algorithm to list primes up to \( x \) in sublinear time. Instead, it highlights the *growth rate and inherent unpredictability* of primes, which influences algorithm design and complexity analysis.

#### 3.1 Bounds via Information‑Theoretic Heuristics

Some researchers have explored **Kolmogorov complexity** approaches to prime distribution. For instance, it is known through elementary complexity arguments that there exist infinitely many primes \( p_n \) such that:

\[
p_n = O(n (\log n)^2),
\]

and with refined techniques, bounds such as:

\[
p_n = O(n (\log n)(\log \log n)^2)
\]

hold for arbitrarily large \( n \). These results arise by relating the divergence of the sum of reciprocals of primes to compressibility and prefix‑free encoding arguments, connecting coding theory to prime asymptotics. :contentReference[oaicite:3]{index=3}

However, it is widely acknowledged that **Kolmogorov complexity arguments alone are not strong enough to establish the full prime number theorem** or sharper asymptotics without further analytic machinery. :contentReference[oaicite:4]{index=4}

---

### 4. Heuristics and Independence Principles

Many heuristics in prime theory treat primality as if it were a “random event” with probability \( 1/\ln x \) at scale \( x \). Although primes are deterministic, this probabilistic model yields useful predictions:

- **Expected number of primes up to \( x \)** ≈ \( x/\ln x \).  
- **Expected number of twin primes up to \( x \)** ≈ \( 2C_2 \dfrac{x}{(\ln x)^2} \), where \( C_2 \) is the twin prime constant.  
- Gaps between consecutive primes average approximately \( \ln x \).  

These heuristic principles, often referred to as **independence assumptions**, provide accurate predictions for large ranges and are increasingly validated via computation, though rigorous proofs remain challenging. :contentReference[oaicite:5]{index=5}

日本語:  
「素数は確率的イベントとして扱うヒューリスティックがよく使われるけど、それは deterministic な数学的構造を理解するための近似モデルなんや。」

---

### 5. Related Theorems and Bounds

#### 5.1 Dirichlet’s Theorem on Arithmetic Progressions

Dirichlet’s theorem states that for any two positive coprime integers \( a \) and \( d \), there are infinitely many primes in the sequence:

\[
a,\, a+d,\, a+2d,\, a+3d,\, \ldots
\]

This result generalizes the idea of infinite primes into arithmetic progressions and underpins many results about prime distribution in structured sets. :contentReference[oaicite:6]{index=6}

日本語:  
「算術級数の中に無限に素数が存在するというDirichletの定理は、素数分布の重要な理論的基盤を提供しとるんや。」

---

### 6. Practical Complexity Insights

**Prime testing algorithms** such as Miller‑Rabin and deterministic sieves (e.g., Sieve of Eratosthenes) use prime distribution properties in their complexity analysis:

- **Trial Division**: Up to \( \sqrt{n} \); infeasible for large \( n \).  
- **Miller‑Rabin**: Probabilistic cost roughly \( O(k \log^3 n) \).  
- **Pollard‑Rho**: Expected factorization time \( O(n^{1/4}) \).  
- **Sieving Methods**: Efficient for structured enumeration up to large bounds.

The **Prime Number Theorem** informs the expected density of primes, which in turn influences runtime estimates and practical performance of these algorithms.

---

### 7. Modern Research and Formalization

In addition to heuristic and analytic proofs, **formal verifications** of the PNT and related theorems have been developed using proof assistants such as Isabelle and Metamath, establishing these results within rigorous formal systems. :contentReference[oaicite:7]{index=7}

Contemporary research also explores **partition‑theoretic models** to describe prime distribution from first principles, predicting prime gaps and empirical variations with high accuracy. :contentReference[oaicite:8]{index=8}

---

### 8. Summary

- The **Prime Number Theorem** asserts the asymptotic density of primes as \( \pi(x) \sim x/\ln x \). :contentReference[oaicite:9]{index=9}  
- Computational complexity perspectives provide **bounds** and heuristic insights, but do not replace analytic proofs. :contentReference[oaicite:10]{index=10}  
- Related results such as **Dirichlet’s theorem** and sieve bounds further characterize prime distribution. :contentReference[oaicite:11]{index=11}  
- Modern work continues to refine our understanding of primes via **formalization**, **partition models**, and **information‑theoretic heuristics**.

日本語:  
「素数の理論と複雑性は、解析的証明と情報理論的ヒューリスティックを統合することで、深い構造を明らかにしとるんや。」

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

# Compilation and Execution Instructions

This document provides detailed instructions for compiling and executing the **Self Research Prime Kernel** project in **Fortran**, **C++**, and within a **Docker container**, following the provided project tree. It includes module compilation order, object linking, and environment reproducibility notes.

---

## 1. Fortran Compilation

The Fortran code is modularized with `bigint_mod.f90` and `prime_mod.f90` under `fortran/modules`. Compilation must respect module dependencies to ensure `.mod` files are correctly generated.

### Compilation Steps

```bash
gfortran -O2 -Wall -Wextra fortran/modules/bigint_mod.f90 -Jfortran/modules -o bigint_mod.o
gfortran -O2 -Wall -Wextra fortran/modules/prime_mod.f90 -Jfortran/modules -o prime_mod.o
```
### Compile main program with modules

```bash
gfortran -O2 -Wall -Wextra -Ifortran/modules fortran/main.f90 bigint_mod.o prime_mod.o -o bin/prime_fortran
```
### Execute the binary

```bash
./bin/prime_fortran
```

### Notes

> *`-Jfortran/modules` specifies the directory for generated `.mod` files.
> Module compilation order is critical: dependencies must be compiled first (e.g., `bigint_mod.f90` before `prime_mod.f90`).
> The binary output is placed in `bin/` for consistency with C++ executables.*

## 2. C++ Compilation

The C++ code follows a **kernel-inspired modular structure**:

- `cpp/core/`: main logic (`main.cpp`, `bigint.cpp`, `prime.cpp`)
- `cpp/include/`: reusable headers (`C_bigint.h`, `C_prime.h`)
- `cpp/tools/`: benchmarking scripts (`benchmarks.cpp`)

### 2.1 Compile Object Files and Static Library

```bash 
g++ -std=c++20 -O2 -Wall -Wextra -Icpp/include -c cpp/core/bigint.cpp -o bigint.o
g++ -std=c++20 -O2 -Wall -Wextra -Icpp/include -c cpp/core/prime.cpp -o prime.o


ar rcs libprime.a bigint.o prime.o
```

### 2.2 Compile Executables

```bash
g++ -std=c++20 -O2 -Wall -Wextra \
    -Icpp/include \
    cpp/core/main.cpp \
    cpp/core/bigint.cpp \
    cpp/core/prime.cpp \
    cpp/tools/benchmarks.cpp \
    -o bin/prime_cpp

g++ -std=c++20 -O2 -Wall -Wextra \
    -Icpp/include \
    experiments/factorization/pollard_rho.cpp \
    cpp/core/bigint.cpp \
    cpp/core/prime.cpp \
    -o bin/pollard_rho

g++ -std=c++20 -O2 -Wall -Wextra \
    -Icpp/include \
    experiments/timing/prime_timing.cpp \
    cpp/core/bigint.cpp \
    cpp/core/prime.cpp \
    -o bin/prime_timing
```
### Notes

> *Use `-Icpp/include` to ensure all header files are found.
> Linking object files guarantees dependencies between `BigInt` arithmetic and primality routines are resolved.
> Output executables are consistently placed under `bin/`.*

----
## 3. Docker Build and Run

The Dockerfile is located under `docker/` and ensures environment reproducibility across Gentoo, FreeBSD, or minimal Linux containers.

#### Build Docker image

```Bash
docker build -t prime-kernel-research ./docker
```

#### Build Docker image

```bash
docker run -it prime-kernel-research
```

#### Inside container, execute C++ binary

```bash
./bin/prime_cpp
```

#### Inside container, execute Fortran binary

```bash
./bin/prime_fortran
```

### Notes

> *Ensure the Dockerfile installs `g++`, `gfortran`, and all necessary dependencies.
> The container provides deterministic results across different host machines.
> Use bind mounts to persist logs or CSV outputs:*

```bash
docker run -it -v $(pwd)/bin:/workspace/bin prime-kernel-research
``` 

# Folder Structure 

> ***The following is the relevant subtree for compilation:***

```bash
├── bin/
│   ├── prime_cpp
│   ├── prime_fortran
│   ├── pollard_rho
│   └── prime_timing
├── cpp/
│   ├── core/
│   │   ├── bigint.cpp
│   │   ├── main.cpp
│   │   └── prime.cpp
│   ├── include/
│   │   ├── C_bigint.h
│   │   └── C_prime.h
│   └── tools/
│       └── benchmarks.cpp
├── fortran/
│   ├── main.f90
│   └── modules/
│       ├── bigint_mod.f90
│       └── prime_mod.f90
├── libprime.a
├── bigint.o
├── prime.o
└── docker/
    └── Dockerfile
```
---

## 2. Experimental Methodology

### 2.1 Prime Testing

- **Range**: 2 – 10⁷, scalable via **BigInt** to handle larger integers beyond native types.  
- **Methods**:  
  - **Miller-Rabin probabilistic test** (7 iterations by default), providing a high-confidence primality check.  
  - **Naïve trial division** for verification and cross-validation of smaller numbers.  
- **Logging**:  
  - Primality status of each tested number.  
  - Elapsed computation time per number.  
  - Detected **twin primes**.  
  - Candidate **Mersenne primes** identified during the range scan.  

### 2.2 Twin Primes

- **Sequential comparison** of verified primes: for each prime `p`, check if `p + 2` is prime.  
- Log pairs with timestamps to CSV for statistical analysis and empirical verification.  
- 日本語: 「双子素数の検出では、各素数を順番に比較して、条件を満たすペアを記録しとるんや。」

### 2.3 Mersenne Candidates

- Compute **Mersenne numbers** \( M_p = 2^p - 1 \) using **BigInt arithmetic** for high-precision handling.  
- Preliminary **Miller-Rabin filtering** applied to candidate numbers before deterministic verification.  
- **Lucas-Lehmer test** performed on filtered candidates for full primality confirmation.  
- 日本語: 「大きなメルセンヌ素数の計算は、BigIntを使い、分散処理やGPUを必要とする場合もあるんや。」

### 2.4 Factorization Analysis

- Compare **naïve trial division** versus **Pollard-Rho** factorization for semi-primes.  
- Metrics recorded: memory footprint, execution time, algorithmic scaling for increasing number size.  
- Applicable to **cryptographic key analysis**, providing insight into RSA modulus hardness.  
- 日本語: 「素因数分解の性能比較では、メモリ使用量や実行時間も記録して、アルゴリズムのスケーリングを解析しとるんや。」

### 2.5 Timing Analysis

- **C++**: `std::chrono::high_resolution_clock` used for microsecond-precision timing.  
- **Fortran**: `cpu_time` intrinsic used for per-number timing measurements.  
- **Metrics collected**:  
  - Individual number runtime.  
  - Cumulative runtime across ranges.  
  - Algorithmic complexity scaling with respect to number size.  
- 日本語: 「タイミング解析では、各計算ステップの時間を詳細に測定して、性能のボトルネックを特定しとるんや。」

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
