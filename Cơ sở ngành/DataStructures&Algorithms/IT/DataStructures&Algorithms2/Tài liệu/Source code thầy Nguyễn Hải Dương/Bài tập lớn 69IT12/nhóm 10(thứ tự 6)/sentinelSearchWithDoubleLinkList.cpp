#include <iostream>
#include <string>
using namespace std;

struct Node {
    int Val;
    Node* Next;
    Node* Back;
};

struct DoubleLinklist {
    Node* First = nullptr;
    Node* Last = nullptr;
    int Count = 0;
};

Node* CreateNode(int value) {
    Node* p = new Node;
    p->Val = value;
    p->Next = nullptr;
    p->Back = nullptr;
    return p;
}

bool isEmpty(const DoubleLinklist& p) {
    return (p.First == nullptr || p.Last == nullptr || p.Count == 0);
}

void InsertNode(DoubleLinklist& p, int value, int idx) {
    Node* newNode = CreateNode(value);

    if (isEmpty(p)) {
        p.First = p.Last = newNode;
        p.Count++;
    } else {
        if (idx < 0 || idx > p.Count) {
            cout << "Vi tri khong hop le" << endl;
            delete newNode; // sửa free thành delete
            return;
        }

        if (idx == 0) {
            newNode->Next = p.First;
            p.First->Back = newNode;
            p.First = newNode;
        } else if (idx == p.Count) {
            newNode->Back = p.Last;
            p.Last->Next = newNode;
            p.Last = newNode;
        } else {
            Node* temp = p.First;
            for (int i = 0; i < idx - 1; i++) temp = temp->Next;

            newNode->Next = temp->Next;
            temp->Next->Back = newNode;
            temp->Next = newNode;
            newNode->Back = temp;
        }
        p.Count++;
    }
}

void PrintList(const DoubleLinklist& p) {
    if (isEmpty(p)) {
        cout << "Danh sach dang rong" << endl;
    } else {
        cout << "Danh sach la: First <-- {";
        Node* temp = p.First;
        while (temp) {
            cout << temp->Val;
            temp = temp->Next;
            if (temp) cout << ",";
        }
        cout << "} --> Last" << endl;
    }
}

int SentinelSearch(DoubleLinklist& p, int x) {
    if (isEmpty(p)) {
        cout << "Danh sach rong!" << endl;
        return -1;
    }

    Node* sentinel = CreateNode(x);
    Node* oldLast = p.Last;
    oldLast->Next = sentinel;

    Node* temp = p.First;
    int idx = 0;
    while (temp->Val != x) {
        temp = temp->Next;
        idx++;
    }

    oldLast->Next = nullptr;
    delete sentinel;

    return (temp == sentinel) ? -1 : idx;
}

int main() {
    int choice = -1;
    int Value, idx = 0;
    DoubleLinklist p;

    string mn = "-------------------------------------------------\n"
                "0.Thoat\n1.Them phan tu vao danh sach\n2.In ra danh sach\n"
                "3.Tim kiem phan tu bang tim kiem tuan tu linh canh\n"
                "-------------------------------------------------";

    while (choice != 0) {
        cout << mn << "\nNhap lua chon: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Nhap gia tri phan tu can them: ";
                cin >> Value;
                if (!isEmpty(p)) {
                    cout << "Nhap vi tri can them phan tu: ";
                    cin >> idx;
                } else idx = 0;
                InsertNode(p, Value, idx);
                break;

            case 2:
                PrintList(p);
                break;

            case 3:
                cout << "Nhap gia tri can tim: ";
                cin >> Value;
                idx = SentinelSearch(p, Value);
                if (idx == -1)
                    cout << "Khong tim thay " << Value << " trong danh sach.\n";
                else
                    cout << "Tim thay " << Value << " tai vi tri A(" << idx << ")\n";
                break;
        }
    }
    return 0;
}
