#!/bin/bash
# run timing and factorization experiments

mkdir -p /opt/research/experiments/results

echo "[*] running prime timing benchmarks"
./bin/prime_timing > /opt/research/experiments/results/timing.log

echo "[*] running factorization benchmarks"
./bin/pollard_rho > /opt/research/experiments/results/factorization.log

echo "[*] experiments completed"

