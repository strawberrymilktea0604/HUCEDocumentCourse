#!/bin/bash
INPUT_FILE="DanhSachThiSinh.txt"
OUTPUT_FILE="DanhSachThiSinh_Moi.txt"   


if [ ! -f "$INPUT_FILE" ]; then
    echo "File $INPUT_FILE không tồn tại!"
    exit 1
fi
"$OUTPUT_FILE"  # xóa nội dung cũ nếu có

echo "SBD,,Ho va ten,,Tuoi,,Chuyen mon,,Ngoai ngu,,Tin hoc,,Tong diem,,Ket qua" > "$OUTPUT_FILE"

# Đọc file từ dòng 2 trở đi (bỏ qua header)
tail -n +2 "$INPUT_FILE" | sed 's/\r$//' | while IFS=',,' read -r stt _ hoten _ ngaysinh _ chuyen_mon _ ngoai_ngu _ tin_hoc || [[ -n "$stt" ]]
do
    # Bỏ qua dòng trống hoặc dòng chỉ có dấu phẩy
    if [[ -z "$stt" || "$stt" =~ ^[[:space:]]*$ ]]; then
        continue
    fi
    
    # Lấy năm sinh từ ngày sinh (định dạng dd.mm.yyyy)
    nam_sinh=$(echo "$ngaysinh" | cut -d'.' -f3)
    tuoi=$((2025 - nam_sinh))
    
    # Tính tổng điểm (chuyên môn + ngoại ngữ + tin học)
    tong_diem=$((chuyen_mon + ngoai_ngu + tin_hoc))
    
    # Xác định kết quả
    if [ "$tong_diem" -ge 21 ]; then
        ket_qua="Dau"
    else
        ket_qua="Truot"
    fi

    echo "$stt,,$hoten,,$tuoi,,$chuyen_mon,,$ngoai_ngu,,$tin_hoc,,$tong_diem,,$ket_qua" >> "$OUTPUT_FILE"
done

echo "Đã tạo file $OUTPUT_FILE với các cột mới."
echo "Nội dung file $OUTPUT_FILE:"
cat "$OUTPUT_FILE"


for sbd in {1..10}; do
    output_file="ThongBaoKetQuaTuyenSinh_${sbd}.txt"
    grep -E "^${sbd},," "$OUTPUT_FILE" > temp.txt
    if [ -s temp.txt ]; then
        IFS=',,' read -r _ _ hoten _ tuoi _ chuyen_mon _ ngoai_ngu _ tin_hoc _ tong_diem _ ket_qua < temp.txt
        {
            echo "Công ty HUCEABC xin gửi kết quả tuyển dụng như sau:"
            echo "SBD: $sbd"
            echo "Họ và tên: $hoten"
            echo "Tuoi : $tuoi"
            echo "Diem chuyen mon : $chuyen_mon"
            echo "Diem ngoai ngu: $ngoai_ngu"
            echo "Diem tin hoc: $tin_hoc"
            echo "Tong diem: $tong_diem"
            echo "Ket qua: $ket_qua"
        } > "$output_file"
        echo "Đã tạo file $output_file"
    else
        echo "Không tìm thấy thí sinh với SBD: $sbd"
    fi
    rm -f temp.txt
done