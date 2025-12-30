#!/bin/bash
set -e

BIN=bin
mkdir -p $BIN

echo "[*] compiling C++ core"

g++ -std=c++20 -O2 -Wall -Wextra \
    -Icpp/include \
    cpp/core/main.cpp \
    cpp/core/bigint.cpp \
    cpp/core/prime.cpp \
    cpp/tools/benchmarks.cpp \
    -o $BIN/prime_cpp

echo "[*] compiling C++ experiments"

g++ -std=c++20 -O2 -Wall -Wextra \
    -Icpp/include \
    experiments/timing/prime_timing.cpp \
    cpp/core/bigint.cpp \
    cpp/core/prime.cpp \
    -o $BIN/prime_timing

g++ -std=c++20 -O2 -Wall -Wextra \
    -Icpp/include \
    experiments/factorization/pollard_rho.cpp \
    cpp/core/bigint.cpp \
    cpp/core/prime.cpp \
    -o $BIN/pollard_rho

echo "[*] compiling Fortran"

gfortran -O2 \
    fortran/modules/bigint_mod.f90 \
    fortran/modules/prime_mod.f90 \
    fortran/main.f90 \
    -o $BIN/prime_fortran

echo "[+] build finished successfully"
