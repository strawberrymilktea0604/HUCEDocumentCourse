#!bin/bash

character=${1:-*} 
lines=${2:-5}      
n=0

while [ "$n" -lt "$lines" ]; do  
    printf "%${n}s" | tr ' ' "$character"  
    echo ""  # Xuống dòng
    n=$((n + 1))
done
