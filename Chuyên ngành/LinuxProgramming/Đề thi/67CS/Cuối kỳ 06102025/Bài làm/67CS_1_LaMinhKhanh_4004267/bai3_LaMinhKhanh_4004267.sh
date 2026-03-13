#!/bin/bash

while true 
do
	echo 
	echo "1. Count"
	echo "2. Process"
	echo "3. Move"
	echo "4. Exit"
	read -p "Xin moi chon: " input
	case $input in
		1|c|C)
			path="./"
			read -p "Nhap vao 1 duong dan (mac dinh: './') : " path
			echo "So luong folder la: $(ls $path -lR | grep ^d | wc -l)"
			echo "So luong files: $(ls $path -lR | grep ^- | wc -l)"
			;;
		2|p|P) echo 
			echo "Cac tien trinh dang chay: "
			echo "$(ps -a)"
			;;
		3|m|M) echo 
			while true 
			do
				read -p "Nhap vao ten file: " file
				if [ -f "$file" ];
				then
					break
				else 
					echo "File KHONG ton tai"
				fi
			done

			while true 
			do
				read -p "Nhap vao duong dan: " path
				if  [ -d "$path" ]; 
				then
					break
				else 
					echo "Duong dan KHONG ton tai"
				fi
			done
			mv "$file" "$path"
			echo "=>> Di chuyen thanh cong"
			;;
		4|e|E) 
			echo "Goodbye"
			exit 1
			;;
	esac
done



