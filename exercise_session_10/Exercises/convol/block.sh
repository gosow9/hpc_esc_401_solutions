#!/usr/bin/env bash
set -e

BLOCKSIZES="32 64 128 256 512 1024"

echo "Autotuning BLOCKSIZE for N=$(grep '#define N' main.c | awk '{print $3}')"
echo

for bs in $BLOCKSIZES; do
    echo "=== Testing BLOCKSIZE = $bs ==="
    make clean > /dev/null

    make BLOCKSIZE=$bs > /dev/null

    output=$(./a.out)

    gpu_time=$(echo "$output" | awk '/GPU/ {print $3}')
    cpu_time=$(echo "$output" | awk '/CPU/ {print $3}')
    status=$(echo "$output" | awk '/PASSED|FAILED/ {print $1}')

    echo "Result: $status"
    echo "GPU time: ${gpu_time}s"
    echo "CPU time: ${cpu_time}s"
    echo
done

