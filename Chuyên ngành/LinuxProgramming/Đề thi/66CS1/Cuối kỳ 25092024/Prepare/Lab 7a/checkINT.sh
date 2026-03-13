# Kiểm tra xem hai tham số có phải là số hợp lệ hay không
if ! [[ "$so12" =~ ^-?[0-9]+$ && "$so13" =~ ^-?[0-9]+$ ]]; then
    echo "Tham số thứ 12 và thứ 13 phải là số nguyên."
    exit 1
fi
