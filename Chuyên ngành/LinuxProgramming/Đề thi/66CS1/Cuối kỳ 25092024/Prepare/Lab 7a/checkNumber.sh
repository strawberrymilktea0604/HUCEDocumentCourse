#!bin/bash

read -p "Nhap vao 1 so nguyen: " intNum
if [ "$intNum" -eq 0 ]
then
	echo "Nguoi dung nhap vao so: " $intNum
elif [ "$intNum" -gt 0 ]
then
	echo "Nguoi dung nhap so " $intNum "lon hon 0"
else
	echo "Nguoi dung nhap so " $intNum "nho hon 0"
fi

