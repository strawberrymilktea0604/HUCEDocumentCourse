#include <iostream>
#include <string>
#include <limits> // Để dùng numeric_limits
using namespace std;

const int HASH_SIZE = 10; // số lượng bucket

// Cấu trúc Node cho danh sách liên kết đôi
struct Node {
    int key;
    string value;
    Node* next;
    Node* prev;
    Node(int k, string v) : key(k), value(v), next(nullptr), prev(nullptr) {}
};

// Bảng băm
struct HashTable {
    Node* table[HASH_SIZE]; // mỗi phần tử là head của danh sách

    // Constructor
    HashTable() {
        for (int i = 0; i < HASH_SIZE; i++)
            table[i] = nullptr;
    }

    // Destructor - Giải phóng bộ nhớ
    ~HashTable() {
        for (int i = 0; i < HASH_SIZE; i++) {
            Node* current = table[i];
            while (current != nullptr) {
                Node* temp = current;
                current = current->next;
                delete temp;
            }
            table[i] = nullptr;
        }
    }

    // Hàm băm
    int hashFunc(int key) {
        return key % HASH_SIZE;
    }

    // Thêm phần tử
    void insert(int key, string value) {
        int index = hashFunc(key);

        // Kiểm tra trùng key
        Node* current = table[index];
        while (current != nullptr) {
            if (current->key == key) {
                cout << " Loi: Key " << key << " da ton tai, khong the chen!\n";
                return;
            }
            current = current->next;
        }

        // Thêm phần tử mới vào đầu bucket
        Node* newNode = new Node(key, value);
        if (table[index] == nullptr) {
            table[index] = newNode;
        } else {
            newNode->next = table[index];
            table[index]->prev = newNode;
            table[index] = newNode;
        }
        cout << " Da chen (" << key << ", " << value << ") vao bucket " << index << endl;
    }

    // Tìm kiếm
    Node* search(int key) {
        int index = hashFunc(key);
        Node* current = table[index];
        while (current != nullptr) {
            if (current->key == key) return current;
            current = current->next;
        }
        return nullptr;
    }

    // In toàn bộ bảng băm
    void display() {
        for (int i = 0; i < HASH_SIZE; i++) {
            cout << "bucket " << i << ": ";
            Node* current = table[i];
            while (current != nullptr) {
                cout << "(" << current->key << ", " << current->value << ") <-> ";
                current = current->next;
            }
            cout << "NULL\n";
        }
    }
};

int main() {
    HashTable ht;
    int choice = -1;
    string menu = "-------------------------------------------------\n"
                  "0. Thoat\n"
                  "1. Them phan tu vao danh sach\n"
                  "2. In ra danh sach\n"
                  "3. Tim kiem phan tu\n"
                  "-------------------------------------------------";

    while (choice != 0) {
        cout << menu;
        cout << "\nNhap lua chon: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            int key;
            string value;
            cout << "Nhap key (so nguyen): ";
            cin >> key;
            cout << "Nhap gia tri (chuoi): ";
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Xóa toàn bộ ký tự thừa
            getline(cin, value);
            ht.insert(key, value);
            break;
        }
        case 2:
            cout << "\n== Danh sach hien tai ==\n";
            ht.display();
            break;
        case 3: {
            int key;
            cout << "Nhap key can tim: ";
            cin >> key;
            Node* found = ht.search(key);
            if (found) cout << " Tim thay: " << found->key << " -> " << found->value << endl;
            else cout << " Khong tim thay key " << key << endl;
            break;
        }
        case 0:
            cout << "Thoat chuong trinh.\n";
            break;
        default:
            cout << " Lua chon khong hop le. Vui long thu lai!\n";
        }
    }
    return 0;
}
