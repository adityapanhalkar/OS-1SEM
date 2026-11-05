#!/bin/bash

echo "===== FILE MANAGEMENT ====="

touch file1.txt
echo "File created"

ls

cp file1.txt file2.txt
echo "File copied"

mv file2.txt newfile.txt
echo "File renamed"

rm newfile.txt
echo "File deleted"


echo ""
echo "===== DIRECTORY MANAGEMENT ====="

mkdir mydir
echo "Directory created"

cd mydir
pwd

cd ..

rmdir mydir
echo "Directory removed"


echo ""
echo "===== PROCESS MANAGEMENT ====="

sleep 100 &

pid=$!

echo "Process ID: $pid"

ps

jobs

kill "$pid"
wait "$pid" 2>/dev/null

echo "Process terminated"

echo ""
echo "Practical completed"
