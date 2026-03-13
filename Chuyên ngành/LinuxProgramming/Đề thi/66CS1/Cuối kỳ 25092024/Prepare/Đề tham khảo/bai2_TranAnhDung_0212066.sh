#!bin/bash

# check if file exist
if [ ! -f "$1" ]
then
	echo "File not exist/No file input"
	exit 1
fi

# line count
line_count() {
	count=0
	while IFS= read -r line
	do
		count=$((count + 1))
	done < "$1"
	echo "So dong: $count"
}

# word count
word_count() {	
	count=0
	while IFS= read -r line
	do
		for word in $line
		do
			count=$((count + 1))
		done
	done < "$1"
	echo "So tu: $count"
}

# CONDITION: no arg
if [ $# -eq 1 ]
then
	line_count "$1"
	word_count "$1"

# CONDITION: if have argument 'dong' or 'tu'
elif [ $# -eq 2 ]
then
	if [ "$2" == "dong" ]
	then
		line_count "$1"
	elif [ "$2" == "tu" ]
	then
		word_count "$1"
	else
		echo "Tham so 2 khong hop le, chon 'dong' hoac 'tu'"
	fi
else
	echo "Cach dung: ./*.sh <ten_file> [dong|tu]"
fi

