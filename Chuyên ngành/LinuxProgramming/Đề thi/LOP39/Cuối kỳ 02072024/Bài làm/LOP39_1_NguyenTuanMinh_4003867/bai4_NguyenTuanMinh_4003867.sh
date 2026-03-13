#!/bin/bash
status="true"
InDir=""
perm () {
InDir=$1
if [ -f $InDir ]
				then echo -e  Day la file.
				else echo -e  Day la thu muc.
			fi
			if [ -w $InDir ]
				then echo -e  Ban co quyen ghi.
				else echo -e  Ban khong co quyen ghi. 
			fi
			if [ -r $InDir ]
				then echo -e Ban co quyen doc.
				else echo -e  Ban khong co quyen doc. 
			fi
			if [ -x $InDir ]
				then echo -e Ban co quyen thuc thi.
				else echo -e  Ban khong co quyen thuc thi. 
			fi
}

while [ "$status" = "true" ]
do
	printf "1. Present WD\n2. Input\n3. Information\n4.Exit\n"
	read inputVal
	if [ "$inputVal" = "1" ] || [ "$inputVal" = "p" ] || [ "$inputVal" = "P" ] 
	then
		echo `pwd`; tree | tail -1
	fi
	
	if [ "$inputVal" = "2" ] || [ "$inputVal" = "i" ] || [ "$inputVal" = "I" ] 
	then
		read -p "nhap vao duong dan tuyet doi" dir
	fi
	
	if [ "$inputVal" = "3" ] || [ "$inputVal" = "t" ] || [ "$inputVal" = "T" ] 
	then
		if [ "$InDir" = "" ]
		then
		read -p "nhap vao duong dan tuyet doi" dir
		InDir="$dir"
		perm $InDir
		else
			perm $InDir
		fi
	fi
	
	if [ "$inputVal" = "4" ] || [ "$inputVal" = "e" ] || [ "$inputVal" = "E" ] 
	then
		echo Bye Bye
		status="false"
	fi
	
done
