#!bin/bash

# read -p "Nhap so thu 1: " 1
# read -p "Nhap so thu 2: " 2

if [ "$1" -gt "$2" ]
then
	echo "So thu nhat lon hon so thu hai"
elif [ "$1" -lt "$2" ]
then 
	echo "So thu nhat nho hon so thu hai"
else
	echo "Hai so bang nhau"
fi
