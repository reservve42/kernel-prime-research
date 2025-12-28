#!/bin/bash
# compile all research binaries

echo "[*] compiling C++ binaries"
g++ -O2 -Wall -Wextra /opt/research/cpp/main.cpp /opt/research/cpp/core/bigint.cpp /opt/research/cpp/core/prime.cpp -o /opt/research/bin/prime_cpp
g++ -O2 -Wall -Wextra /opt/research/experiments/timing/prime_timing.cpp -o /opt/research/bin/prime_timing
g++ -O2 -Wall -Wextra /opt/research/experiments/factorization/pollard_rho.cpp -o /opt/research/bin/pollard_rho

echo "[*] compiling Fortran binaries"
gfortran -O2 /opt/research/fortran/main.f90 /opt/research/fortran/modules/bigint_mod.f90 /opt/research/fortran/modules/prime_mod.f90 -o /opt/research/bin/prime_fortran

echo "[*] compilation done"

