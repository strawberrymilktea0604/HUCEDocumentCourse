#include <bits/stdc++.h>
using namespace std;

// Cau truc Node (key, value)
struct Node {
    int key;
    string value;
    bool isDeleted;  // danh dau da xoa

    Node() {         // ham tao mac dinh
        key = -1;
        value = "";
        isDeleted = false;
    }
};

class HashTable {
private:
    int size;           // so bucket
    vector<Node> table; // mang cac Node

    // Ham bam: lay key % size
    int hashFunction(int key) {
        return key % size;
    }

public:
    HashTable(int n) {
        size = n;
        table.resize(size); // tu dong goi Node() -> key=-1
    }

    // Them (key, value)
    void insertItem(int key, string value) {
        int index = hashFunction(key);
        int startIndex = index;

        while (table[index].key != -1 && !table[index].isDeleted) {
            if (table[index].key == key) {
                // Neu trung key thi cap nhat value
                table[index].value = value;
                return;
            }
            index = (index + 1) % size;
            if (index == startIndex) {
                cout << "Bang bam day, khong the chen!\n";
                return;
            }
        }
        table[index].key = key;
        table[index].value = value;
        table[index].isDeleted = false;
    }

    // Tim kiem theo key
    string searchItem(int key) {
        int index = hashFunction(key);
        int startIndex = index;

        while (table[index].key != -1) {
            if (table[index].key == key && !table[index].isDeleted) {
                return table[index].value;
            }
            index = (index + 1) % size;
            if (index == startIndex) break;
        }
        return ""; // khong tim thay
    }

    // Sua value theo key
    bool updateItem(int key, string newValue) {
        int index = hashFunction(key);
        int startIndex = index;

        while (table[index].key != -1) {
            if (table[index].key == key && !table[index].isDeleted) {
                table[index].value = newValue;
                return true;
            }
            index = (index + 1) % size;
            if (index == startIndex) break;
        }
        return false;
    }

    // Xoa theo key
    void removeItem(int key) {
        int index = hashFunction(key);
        int startIndex = index;

        while (table[index].key != -1) {
            if (table[index].key == key && !table[index].isDeleted) {
                table[index].isDeleted = true; // danh dau xoa
                return;
            }
            index = (index + 1) % size;
            if (index == startIndex) break;
        }
    }

    // Hien thi toan bo hash table
    void display() {
        for (int i = 0; i < size; i++) {
            cout << i << " --> ";
            if (table[i].key != -1 && !table[i].isDeleted) {
                cout << "(" << table[i].key << ", " << table[i].value << ")";
            } else {
                cout << "NULL";
            }
            cout << endl;
        }
    }
};

int main() {
    int n;
    cout << "Nhap so bucket (kich thuoc bang bam): ";
    cin >> n;

    HashTable h(n);

    int choice, key;
    string value;
    do {
        cout << "\n===== MENU =====\n";
        cout << "1. Them (key, value)\n";
        cout << "2. Sua value theo key\n";
        cout << "3. Xoa phan tu theo key\n";
        cout << "4. Tim kiem theo key\n";
        cout << "5. Hien thi bang bam\n";
        cout << "0. Thoat\n";
        cout << "Chon: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Nhap key: ";
            cin >> key;
            cout << "Nhap value: ";
            cin.ignore();
            getline(cin, value);
            h.insertItem(key, value);
            break;

        case 2:
            cout << "Nhap key muon sua: ";
            cin >> key;
            cout << "Nhap value moi: ";
            cin.ignore();
            getline(cin, value);
            if (h.updateItem(key, value))
                cout << "Da sua thanh cong!\n";
            else
                cout << "Khong tim thay key!\n";
            break;

        case 3:
            cout << "Nhap key muon xoa: ";
            cin >> key;
            h.removeItem(key);
            cout << "Da xoa (neu co)!\n";
            break;

        case 4:
            cout << "Nhap key muon tim: ";
            cin >> key;
            value = h.searchItem(key);
            if (value != "")
                cout << "Tim thay key " << key << " voi value = " << value << endl;
            else
                cout << "Khong tim thay!\n";
            break;

        case 5:
            cout << "Noi dung bang bam:\n";
            h.display();
            break;

        case 0:
            cout << "Thoat chuong trinh.\n";
            break;

        default:
            cout << "Lua chon khong hop le!\n";
        }
    } while (choice != 0);

    return 0;
}

