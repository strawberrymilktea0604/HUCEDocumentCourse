#!bin/bash

read -p "Nhap so thu 1: " INT1
read -p "Nhap so thu 2: " INT2

if [ "$INT1" -gt "$INT2" ]
then
	echo "So thu nhat lon hon so thu hai"
elif [ "$INT1" -lt "$INT2" ]
then 
	echo "So thu nhat nho hon so thu hai"
else
	echo "Hai so bang nhau"
fi
