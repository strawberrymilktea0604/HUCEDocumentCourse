#!bin/bash

if [ "$1" -gt 0 ]; then
    echo "Tham số là số nguyên dương."
elif [ "$1" -lt 0 ]; then
    echo "Tham số là số nguyên âm."
else
    echo "Tham số là số 0."
fi
