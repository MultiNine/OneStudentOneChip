#!/bin/bash
set -e

echo "Create database"
./ex17+5 test.dat c

echo "Set record 1"
./ex17+5 test.dat s 1 anna smith anna@example.com

echo "Set record 2"
./ex17+5 test.dat s 2 bruce smith bruce@example.com

echo "Set record 3"
./ex17+5 test.dat s 3 jerry jack jerry@example.com

echo "List all records"
./ex17+5 test.dat l

echo "Find by lastname"
./ex17+5 test.dat f smith

echo "Delete record 1"
./ex17+5 test.dat d 1
./ex17+5 test.dat l

echo "Search record 2"
./ex17+5 test.dat g 2

echo "Finish test"