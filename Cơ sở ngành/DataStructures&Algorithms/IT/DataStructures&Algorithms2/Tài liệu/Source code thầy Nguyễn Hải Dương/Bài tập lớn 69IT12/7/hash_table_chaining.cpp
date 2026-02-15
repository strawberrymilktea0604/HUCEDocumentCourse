#include <bits/stdc++.h>
using namespace std;

// Cau truc Node de luu cap key - value
struct Node {
    int key;
    string value;
};

class HashTable {
private:
    int size;                        // so bucket
    vector<list<Node> > table;        // moi bucket la 1 danh sach (chaining)

    // Ham bam: lay key % size
    int hashFunction(int key) {
        return key % size;
    }

public:
    HashTable(int n) {
        size = n;
        table.resize(size);
    }

    // Them (key, value)
    void insertItem(int key, string value) {
        int index = hashFunction(key);
        // Kiem tra neu key da ton tai thi cap nhat value
        for (list<Node>::iterator it = table[index].begin(); it != table[index].end(); it++) {
            if (it->key == key) {
                it->value = value;
                return;
            }
        }
        // Neu chua co thi them moi
        Node newNode;
        newNode.key = key;
        newNode.value = value;
        table[index].push_back(newNode);
    }

    // Tim kiem theo key
    string searchItem(int key) {
        int index = hashFunction(key);
        for (list<Node>::iterator it = table[index].begin(); it != table[index].end(); it++) {
            if (it->key == key) {
                return it->value;
            }
        }
        return ""; // khong tim thay
    }

    // Sua value theo key
    bool updateItem(int key, string newValue) {
        int index = hashFunction(key);
        for (list<Node>::iterator it = table[index].begin(); it != table[index].end(); it++) {
            if (it->key == key) {
                it->value = newValue;
                return true;
            }
        }
        return false;
    }

    // Xoa theo key
    void removeItem(int key) {
        int index = hashFunction(key);
        for (list<Node>::iterator it = table[index].begin(); it != table[index].end(); it++) {
            if (it->key == key) {
                table[index].erase(it);
                return;
            }
        }
    }

    // Hien thi toan bo hash table
    void display() {
        for (int i = 0; i < size; i++) {
            cout << i << " --> ";
            for (list<Node>::iterator it = table[i].begin(); it != table[i].end(); it++) {
                cout << "(" << it->key << ", " << it->value << ") ";
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

