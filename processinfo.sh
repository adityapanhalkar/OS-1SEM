#!/bin/bash

echo "===== TOP PROCESSES ====="

ps aux --sort=-%cpu | head

echo ""
echo "===== CURRENT LOGGED-IN USER ====="

whoami

echo ""
echo "===== HOME DIRECTORY ====="

echo "$HOME"

echo ""
echo "===== CURRENT WORKING DIRECTORY ====="

pwd
