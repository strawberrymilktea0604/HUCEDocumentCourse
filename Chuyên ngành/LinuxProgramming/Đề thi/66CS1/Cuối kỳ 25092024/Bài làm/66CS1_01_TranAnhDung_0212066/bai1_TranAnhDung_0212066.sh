#!bin/bash

path="/home/$USER/kiemtra2509"
n=500
f=0

# check if dir kiemtra2509 is exist
if [ ! -f "$path" ]; then
    mkdir "$path"
else
    continue
fi

# create file from f -> n
create_file() {
    while [ "$f" -lt "$n" ]; do
        echo "Dang tao file TranAnhDung_$f.zsh"
        touch "$path/TranAnhDung_$f.zsh"
        f=$((f + 1))
    done
}

# check if file exist then delete old file
if [ ! -f "$path/TranAnhDung_$f.zsh" ]; then
    continue
else
    rm "$path/TranAnhDung_$f.zsh"
    create_file "$f"
fi

# # rename from .zsh to .csv
# while true; do
#     if [ ! -f "$path/TranAnhDung_$f.zsh" ]; then
#         continue
#     else
#         echo "Dang doi file $f.zsh thanh $f.csv"
#         mv "$path/TranAnhDung_$f.zsh" "$path/TranAnhDung_$f.csv"
#     fi
# done
#
# name=TranAnhDung
# id="0212066"
# class=66CS1
# subClass=66CS1
#
# # add data to file
# while true; do
#     if [ ! -f "$path/TranAnhDung_$f.zsh" ]; then
#         continue
#     else
#         echo "Thong tin sinh vien:"
#         echo "Ho va Ten: $name, MSSV: $id"
#         echo "Lop quan ly: $class, Lop mon hoc: $subClass, Hoc ky 1 2024-2025"
#     fi
# done
#
# # change mod
# chmod 700 "$path/*.csv"
#
# # mv to /share/bin
# if [ ! -f "$path" ]; then
#     mkdir "$path"
# else
#     continue
# fi
# mv "$path" "/share/bin/"
