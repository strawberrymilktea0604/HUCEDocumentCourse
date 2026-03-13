#!bin/bash

# Check if enough 13 args or not
if [ $# -lt 13 ]
then
	echo "Yeu cau nhap it nhat 13 tham so"
	exit 1
fi

# Arg 12 & 13
num12=${12}
num13=${13}

# Sum
sum=$((num12 + num13))

# Output
echo "Tong cua tham so thu 12 ($num12) va tham so thu 13 ($num13) la: $sum"
