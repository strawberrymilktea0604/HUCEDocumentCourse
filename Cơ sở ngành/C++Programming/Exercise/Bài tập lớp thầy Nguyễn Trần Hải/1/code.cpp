#include <iostream>
#include <vector>
#include <string>

// Helper function to print a vector to avoid code duplication
void printVector(const std::string& label, const std::vector<int>& vec) {
    std::cout << label << ": ";
    if (vec.empty()) {
        std::cout << "(empty)";
    } else {
        for (const int& num : vec) {
            std::cout << num << " ";
        }
    }
    std::cout << "\n";
}

int main() {
    char studentInitial;
    int arraySize;

    // 1. Input Section
    std::cout << "Nhap chu cai dau cua ten sinh vien: ";
    std::cin >> studentInitial;

    std::cout << "Nhap so luong phan tu cua day " << studentInitial << ": ";
    if (!(std::cin >> arraySize) || arraySize < 0) {
        std::cerr << "Loi: So luong phan tu khong hop le!\n";
        return 1;
    }

    std::vector<int> numbers(arraySize);
    std::vector<int> evenNumbers;
    std::vector<int> divisibleByThree;

    // 2. Data Processing Section
    std::cout << "Nhap " << arraySize << " so nguyen: ";
    for (int i = 0; i < arraySize; ++i) {
        std::cin >> numbers[i];

        if (numbers[i] % 2 == 0) {
            evenNumbers.push_back(numbers[i]);
        }
        if (numbers[i] % 3 == 0) {
            divisibleByThree.push_back(numbers[i]);
        }
    }

    // 3. Output Section
    std::cout << "\n--- Ket Qua ---\n";
    printVector("Day so chan", evenNumbers);
    printVector("Day so chia het cho 3", divisibleByThree);

    // 4. Comparison Logic
    std::cout << "\nKet qua so sanh:\n";
    size_t evenCount = evenNumbers.size();
    size_t threeCount = divisibleByThree.size();

    if (evenCount > threeCount) {
        std::cout << "-> Day so chan dai hon.\n";
    } else if (evenCount < threeCount) {
        std::cout << "-> Day so chia het cho 3 dai hon.\n";
    } else {
        std::cout << "-> Hai day co do dai bang nhau.\n";
    }

    return 0;
}
