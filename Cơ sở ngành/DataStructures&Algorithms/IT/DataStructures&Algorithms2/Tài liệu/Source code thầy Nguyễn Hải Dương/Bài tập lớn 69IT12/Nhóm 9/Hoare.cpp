#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>

// Hàm phân hoạch Hoare
int partition_hoare(std::vector<int>& arr, int left, int right) {
    int pivot = arr[left]; // Chọn phần tử đầu tiên làm chốt
    int i = left - 1;
    int j = right + 1;

    while (true) {
        // Tìm phần tử từ bên trái lớn hơn hoặc bằng chốt
        do {
            i++;
        } while (arr[i] < pivot);

        // Tìm phần tử từ bên phải nhỏ hơn hoặc bằng chốt
        do {
            j--;
        } while (arr[j] > pivot);

        // Nếu các con trỏ đã gặp nhau, trả về vị trí phân hoạch
        if (i >= j) {
            return j;
        }

        // Hoán đổi các phần tử không đúng vị trí
        std::swap(arr[i], arr[j]);
    }
}

// Hàm Quick sort
void quickSort(std::vector<int>& arr, int left, int right) {
    if (left < right) {
        // pi là chỉ mục của chốt sau khi phân hoạch
        int pi = partition_hoare(arr, left, right);

        // Đệ quy sắp xếp hai mảng con
        quickSort(arr, left, pi);
        quickSort(arr, pi + 1, right);
    }
}

// Hàm in mảng
void printArray(const std::vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}


int main() {
    // Test Case 1: Mảng ngẫu nhiên
    /*
    std::vector<int> arr1 = {10, 7, 8, 9, 1, 5};
    std::cout << "Test Case 1: Mang ngau nhien\n";
    std::cout << "Truoc khi sap xep: ";
    printArray(arr1);

    quickSort(arr1, 0, arr1.size() - 1);

    std::cout << "Sau khi sap xep:  ";
    printArray(arr1);
    std::cout << "\n-------------------\n";

    // Test Case 2: Mảng đã sắp xếp
    std::vector<int> arr2 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    std::cout << "Test Case 2: Mang da sap xep\n";
    std::cout << "Truoc khi sap xep: ";
    printArray(arr2);

    quickSort(arr2, 0, arr2.size() - 1);

    std::cout << "Sau khi sap xep:  ";
    printArray(arr2);
    std::cout << "\n-------------------\n";

    // Test Case 3: Mảng đã sắp xếp ngược
    std::vector<int> arr3 = {15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    std::cout << "Test Case 3: Mang da sap xep nguoc\n";
    std::cout << "Truoc khi sap xep: ";
    printArray(arr3);

    quickSort(arr3, 0, arr3.size() - 1);

    std::cout << "Sau khi sap xep:  ";
    printArray(arr3);
    std::cout << "\n-------------------\n";

    // Test Case 4: Mảng có các phần tử trùng lặp
    std::vector<int> arr4 = {5, 2, 8, 5, 1, 9, 2, 5, 5, 8, 1, 2};
    std::cout << "Test Case 4: Mang co phan tu trung lap\n";
    std::cout << "Truoc khi sap xep: ";
    printArray(arr4);

    quickSort(arr4, 0, arr4.size() - 1);

    std::cout << "Sau khi sap xep:  ";
    printArray(arr4);
    std::cout << "Thoi gian chay: " << duration.count() << " nanoseconds" << std::endl;
    std::cout << "\n-------------------\n";

    // Test Case 5: Mảng có các phần tử âm
    std::vector<int> arr5 = {-10, 0, -5, -2, -8, -1};
    std::cout << "Test Case 5: Mang co phan tu am\n";
    std::cout << "Truoc khi sap xep: ";
    printArray(arr5);

    quickSort(arr5, 0, arr5.size() - 1);

    std::cout << "Sau khi sap xep:  ";
    printArray(arr5);
    std::cout << "\n-------------------\n";

    // Test Case 6: Mảng rỗng
    std::vector<int> arr6 = {};
    std::cout << "Test Case 6: Mang rong\n";
    std::cout << "Truoc khi sap xep: ";
    printArray(arr6);

    quickSort(arr6, 0, arr6.size() - 1);

    std::cout << "Sau khi sap xep:  ";
    printArray(arr6);
    std::cout << "\n-------------------\n";

    // Test Case 7: Mảng có một phần tử
    std::vector<int> arr7 = {99};
    std::cout << "Test Case 7: Mang co mot phan tu\n";
    std::cout << "Truoc khi sap xep: ";
    printArray(arr7);

    quickSort(arr7, 0, arr7.size() - 1);

    std::cout << "Sau khi sap xep:  ";
    printArray(arr7);
    std::cout << "\n-------------------\n";

    // Test Case 8: Mảng lớn ngẫu nhiên
    std::vector<int> arr8;
    for (int i = 0; i < 10000; i++) {
        arr8.push_back(rand() % 10000);
    }
    std::cout << "Test Case 8: Mang lon ngau nhien (10,000 phan tu)\n";
    std::cout << "Truoc khi sap xep: [Mang qua lon khong in ra]\n";

    quickSort(arr8, 0, arr8.size() - 1);

    std::cout << "Sau khi sap xep: [Mang da duoc sap xep]\n";
    std::cout << "\n-------------------\n";

    // Test Case 9: Mảng lớn đã sắp xếp (worst case for quicksort)
    std::vector<int> arr9;
    for (int i = 0; i < 1000; i++) {
        arr9.push_back(i);
    }
    std::cout << "Test Case 9: Mang lon da sap xep (1,000 phan tu) - Worst Case\n";
    std::cout << "Truoc khi sap xep: [1, 2, 3, ..., 1000]\n";

    quickSort(arr9, 0, arr9.size() - 1);

    std::cout << "Sau khi sap xep: [Mang da duoc sap xep]\n";
    std::cout << "\n-------------------\n";

    return 0;
}
