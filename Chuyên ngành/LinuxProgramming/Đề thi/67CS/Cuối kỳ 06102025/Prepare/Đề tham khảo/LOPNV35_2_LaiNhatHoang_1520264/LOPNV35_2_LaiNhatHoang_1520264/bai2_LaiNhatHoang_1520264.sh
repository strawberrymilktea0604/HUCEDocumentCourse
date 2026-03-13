#!/bin/bash

if [ $# -lt 1 ];
then
	echo "Khong co tham so nao"
	exit 1
fi

minLength=$(expr length $1)
minIndex=1;
minValue=$1;

count=0

for i in $@
do
	# Dem thu tu tham so
	count=$((count+1))
	# Tinh do dai tham so
	tempLength=$(expr length $i)
	# Kiem tra xem co be hon khong
	if [ $tempLength -lt $minLength ];
	then
		minValue=$i
		minLength=$tempLength
		minIndex=$count
	fi	
done

echo
echo "Tham so ngan nhat dau tien la: $minValue"
echo "So ky tu la: $minLength" 
echo "Vi tri la: $minIndex"
