#!bin/bash

while true
do
    echo "=====MENU====="
    echo "1. Hello"
    echo "2. Count"
    echo "3. Statistic"
    echo "4. Exit"
    read -p "Con mot muc (1, 2, 3, 4 hoac h, c, s, e): " choice

    case "$choice" in
    1 | h | H)
        # print hello
        echo "Xin chao, $USER!"
        echo "Vi tri thu muc hien hanh: $(pwd)"
        echo "Ngay gio hien tai: $(date)"
        ;;
    2 | c | C)
        # Read 2 strings from input
        read -p "Nhap chuoi chinh: " main_string
        read -p "Nhap chuoi can tim: " search_string
        count=$(grep -o -i "$search_string" <<<"$main_string" | wc -l)
        # -o xuat cac phan trung khop; -i khong phan biet L/Ucase; <<< here string = dua string vao grep
        echo "Chuoi '$search_string' xuat hien trong chuoi chinh $count lan"
        ;;
    3 | s | S)
        # count user with UID >= 1000
        user_count=$(awk -F: '$3 >= 1000 {count++} END {print count}' /etc/passwd)
        echo "So nguoi dung duoc them vao he thong (UID >= 1000): $user_count"
        ;;
    4 | e | E)
        # Exit program
        echo "Cam on ban da su dung chuong trinh!"
        exit 0
        ;;
    *)
        echo "Lua chon khong hop le! Vui long chon lai"
        ;;
    esac
done
