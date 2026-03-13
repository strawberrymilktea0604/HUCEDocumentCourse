#!/bin/bash
TARGET_DIR="/home/minhkhanhla/test"
for i in $(seq 1 500)
do
      rm -rf "$TARGET_DIR/SinhVienHUCE_$i"
done
