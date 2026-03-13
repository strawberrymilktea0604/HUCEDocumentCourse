#!/bin/bash

draw_triangle() {
    local char=$1
    local size=$2

    if ! [[ "$size" =~ ^[1-9][0-9]*$ ]]; then
        echo "Loi: Kich thuoc phai la mot so nguyen duong."
        return
    fi

    for ((i=1; i<=size; i++)); do
        for ((j=1; j<=size-i; j++)); do
            echo -n " "
        done

        for ((k=1; k<=2*i-1; k++)); do
             echo -n "$char"
        done
        echo
    done
}

char=$1
param=$2

if [ -z "$char" ] || [ -z "$param" ]; then
    read -p "Nhap vao ky tu hien thi: " char
    read -p "Nhap vao kich thuoc: " param
fi

draw_triangle "$char" "$param"