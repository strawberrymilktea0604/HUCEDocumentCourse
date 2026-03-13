#!/bin/bash
TARGET_DIR="/home/minhnt_hk3/kiemtra0207"
FILE_PATTERN="$TARGET_DIR/NguyenTuanMinh_*.sh"

if ls $FILE_PATTERN 1>/dev/null 2>&1
then
    echo "Phat hien file ton tai."
    for i in $(seq 1 500)
    do
        rm -f "$TARGET_DIR/NguyenTuanMinh_$i.sh"
    done
    echo "Da xoa xong."
else
    echo "Khong tim thay file. Dang tao moi..."
    mkdir -p "$TARGET_DIR"
    for i in $(seq 1 500)
    do
        touch "$TARGET_DIR/NguyenTuanMinh_$i.sh"
    done
    
    sudo chmod g-rwx,o-rwx "$TARGET_DIR"
    if [ -d "/share/bin" ]; then
        mv "$TARGET_DIR" /share/bin
        echo "Da tao file, phan quyen va di chuyen toi /share/bin."
    else
        echo "Thu muc /share/bin khong ton tai. Da tao file nhung chua di chuyen."
    fi
fi