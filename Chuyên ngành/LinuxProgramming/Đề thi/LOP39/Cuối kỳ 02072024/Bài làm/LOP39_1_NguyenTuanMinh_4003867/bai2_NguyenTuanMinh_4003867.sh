#!/bin/bash
eval dir=${!#}
echo $dir
if [ -f $dir ]
then
	echo Day la file.
	for i in $*
	do
		if [ "$i" = "doc" ]
		then
			if [ -r $dir ]
			then echo Ban co quyen doc voi file $dir
			else echo Ban khong co quyen doc voi file $dir
			fi
		fi
		
		if [ "$i" = "ghi" ]
		then
			if [ -w $dir ]
			then echo Ban co quyen ghi voi file $dir
			else echo Ban khong co quyen ghi voi file $dir
			fi
		fi
		
		if [ "$i" = "thucthi" ]
		then
			if [ -x $dir ]
			then echo Ban co quyen thuc thi voi file $dir
			else echo Ban khong co quyen thuc thi voi file $dir
			fi
		fi
	done
else
	echo Day la thu muc.
fi
