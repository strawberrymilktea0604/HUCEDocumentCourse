#!bin/bash

# define input file and output file
INPUT_FILE="DanhSachHocSinh.txt"
OUTPUT_FILE="DanhSachHocSinhDuocXet.txt"

# MSSV = 212066
alpha=4
beta=11

# Check if output file is exist
if [ ! -f "$OUTPUT_FILE" ]
then
	touch "$OUTPUT_FILE"
fi

# check if alpha & beta valid
line_count=$(wc -l < "$INPUT_FILE")
if [ "$alpha" -lt 1 ] || [ "$beta" -gt "$line_count" ]
then
	echo "dong alpha hoac beta khong hop le"
	exit 1
fi

# take line from alpha to beta and save to output file
sed -n "$((alpha + 1)),$((beta + 1))p" "$INPUT_FILE" > "$OUTPUT_FILE"
# sed using when replace a string

# Đưa ra danh sách 3 học sinh có điểm Tin học cao nhất
echo "Danh sách 3 học sinh có điểm Tin học cao nhất:"
sort -t,, -k6,6nr "$OUTPUT_FILE" | head -n 3

# Đưa ra danh sách những học sinh sinh sau năm 1999 (từ 2000 trở đi)
echo "Danh sách những học sinh sinh sau năm 1999:"
awk -F,, '$3 ~ /[0-9]{2}\.[0-9]{2}\.(200[0-9]|20[1-9][0-9])/' "$OUTPUT_FILE"
