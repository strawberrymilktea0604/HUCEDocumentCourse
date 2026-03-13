#!bin/bash

# Check if enough 3 args or not
if [ $# -lt 3 ]
then
	echo "Yeu cau nhap it nhat 3 tham so"
	exit 1
fi

num1=$1
num2=$2
num3=$3

# Max
if [ "$num1" -ge "$num2" ] && [ "$num1" -ge "$num2" ]
then
	max="1st"
	max_value=$num1
elif [ "$num2" -ge "$num1" ] && [ "$num2" -ge "$num3" ]
then
	max="2nd"
	max_value=$num2
else
	max="3rd"
	max_value=$num3
fi 

# Min
if [ "$num1" -le "$num2" ] && [ "$num1" -le "$num2" ]
then
	min="1st"
	min_value=$num1
elif [ "$num2" -le "$num1" ] && [ "$num2" -le "$num3" ]
then
	min="2nd"
	min_value=$num2
else
	min="3rd"
	min_value=$num3
fi 

# Output
echo "Tham so thu $max co gia tri lon nhat la: $max_value"
echo "Tham so thu $min co gia tri nho nhat la: $min_value"
