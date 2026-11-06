#!/bin/bash

echo "===== OS INFORMATION ====="

echo "Operating System Version:"
cat /etc/os-release

echo ""
echo "===== KERNEL INFORMATION ====="

echo "Kernel Version:"
uname -r

echo ""
echo "Kernel Release Information:"
uname -v

echo ""
echo "===== SYSTEM INFORMATION ====="

echo "System Architecture:"
uname -m

echo "Operating System Name:"
uname -s
