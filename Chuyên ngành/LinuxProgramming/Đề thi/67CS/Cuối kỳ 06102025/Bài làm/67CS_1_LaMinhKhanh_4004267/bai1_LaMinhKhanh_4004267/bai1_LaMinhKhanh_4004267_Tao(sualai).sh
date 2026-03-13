#!/bin/bash
TARGET_DIR="/home/"
FOLDER_PATTERN="$TARGET_DIR/LaMinhKhanh_*"
FILE_TARGET="/home/minhkhanhla/laminhkhanhhk120252026/kiemtra0610/67CS_1_LaMinhKhanh_4004267/bai1_LaMinhKhanh_4004267/ThongTin.txt"

if ls $FOLDER_PATTERN 1>/dev/null 2>&1
then
    echo "Phat hien thu muc ton tai."
    for i in $(seq 1 500)
    do
        rm -rf "$TARGET_DIR/LaMinhKhanh_$i"
    done
    echo "Da xoa xong."
else
    echo "Khong tim thay thu muc. Dang tao moi..."
    mkdir -p "$TARGET_DIR"
    for i in $(seq 1 500)
    do
        mkdir "$TARGET_DIR/LaMinhKhanh_$i"
    done

    for i in $(seq 1 500)
    do
        mv "$TARGET_DIR/LaMinhKhanh_$i" "$TARGET_DIR/SinhVienHUCE_$i"
    done    

    for i in $(seq 1 500)
    do
            cp "$FILE_TARGET" "$TARGET_DIR/SinhVienHUCE_$i"
    done
fi
