#!bin/bash

read_permission=false
write_permission=false
execute_permission=false

for arg in "$@"; do
    case $arg in
        d) read_permission=true ;;
        g) write_permission=true ;;
        t) execute_permission=true ;;
        *) last_arg="$arg" ;;
    esac
done

if [ -d "$last_arg" ]; then
    type="thư mục"
else
    type="file"
fi

if [ -e "$last_arg" ]; then
    permissions=$(ls -l "$last_arg" | awk '{print $1}')
    if [ "$read_permission" = true ]; then
        echo "Bạn có quyền đọc đối với $last_arg."
    else
        echo "Bạn không có quyền đọc đối với $last_arg."
    fi
    if [ "$write_permission" = true ]; then
        echo "Bạn có quyền ghi đối với $last_arg."
    else
        echo "Bạn không có quyền ghi đối với $last_arg."
    fi
    if [ "$execute_permission" = true ]; then
        echo "Bạn có quyền thực thi đối với $last_arg."
    else
        echo "Bạn không có quyền thực thi đối với $last_arg."
    fi
else
    echo "$last_arg không tồn tại."
fi
