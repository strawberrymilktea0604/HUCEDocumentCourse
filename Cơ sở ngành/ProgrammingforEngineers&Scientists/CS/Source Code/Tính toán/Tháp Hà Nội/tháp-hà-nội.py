# -*- coding: utf-8 -*-
"""
Created on Thu Apr 20 02:01:50 2023

@author: minhk
"""

""" Bài toàn tháp Hà Nội """
""" Nhập số n đĩa trên cột a """

sodia = int(input("Nhap so dia trong cot a: ")) 

""" Giờ ta sẽ tiến hành xây dựng giải bài toán Tháp Hà Nội """ 

def ThapHaNoi(sodia, dau, giua, cuoi): 
    
    if (sodia == 1): 
        print("Chuyen dia " + str(sodia) + " tu " + str(dau) + " den " + str(cuoi))
        return
    else:
        ThapHaNoi(sodia - 1, dau, cuoi, giua) 
        print("Chuyen dia " + str(sodia) + " tu " + str(dau) + " den " + str(cuoi))
        ThapHaNoi(sodia - 1, giua, dau, cuoi) 
        
""" Xuất kết quả """
ThapHaNoi(sodia, 'A', 'B', 'C') 