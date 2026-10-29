#!/bin/bash

set -e

echo "TEST: list directions can go"
output=$(printf 'l\n' | ./ex19)
echo "$output" | grep -Fq "NORTH"
echo "[PASS] list directions"

echo "TEST: move north"
output=$(printf 'n\n' | ./ex19)
printf '%s\n' "$output" | grep -Fq "The throne room."
echo "[PASS] move north"

echo "TEST: multiple actions"
output=$(printf 'n\ne\nw\nw\na\na\na\n' | ./ex19)
printf '%s\n' "$output" | grep -Fq "The throne room."
printf '%s\n' "$output" | grep -Fq "The arena, with the minotaur."
printf '%s\n' "$output" | grep -Fq "You attack"
echo "[PASS] multiple actions"