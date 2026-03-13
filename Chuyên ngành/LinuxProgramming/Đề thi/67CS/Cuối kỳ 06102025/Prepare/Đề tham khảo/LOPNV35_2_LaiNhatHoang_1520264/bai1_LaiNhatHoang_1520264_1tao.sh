#!/bin/bash


# xoa het 
$(rm -rf LaiNhatHoang_*)

# tao file
for i in {1..500}
do	
	$(touch LaiNhatHoang_$i)
done

