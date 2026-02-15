#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>
#include <limits>
#include <windows.h>
using namespace std;

class AVLNode {
public:
    int data;
    AVLNode* left;
    AVLNode* right;
    int height;

    AVLNode(int value) : data(value), left(nullptr), right(nullptr), height(1) {}
};

class AVLTree {
private:
    AVLNode* root;

    int getHeight(AVLNode* node) {
        return node ? node->height : 0;
    }

    void updateHeight(AVLNode* node) {
        if (node) node->height = 1 + max(getHeight(node->left), getHeight(node->right));
    }

    int getBalance(AVLNode* node) {
        return node ? getHeight(node->left) - getHeight(node->right) : 0;
    }

    AVLNode* rotateRight(AVLNode* y) {
        AVLNode* x = y->left;
        AVLNode* T2 = x->right;
        x->right = y;
        y->left = T2;
        updateHeight(y);
        updateHeight(x);
        return x;
    }

    AVLNode* rotateLeft(AVLNode* x) {
        AVLNode* y = x->right;
        AVLNode* T2 = y->left;
        y->left = x;
        x->right = T2;
        updateHeight(x);
        updateHeight(y);
        return y;
    }

    AVLNode* insertNode(AVLNode* node, int key) {
        if (!node) return new AVLNode(key);

        if (key < node->data) node->left = insertNode(node->left, key);
        else if (key > node->data) node->right = insertNode(node->right, key);
        else return node;

        updateHeight(node);

        int balance = getBalance(node);

        if (balance > 1 && key < node->left->data) return rotateRight(node);

        if (balance < -1 && key > node->right->data) return rotateLeft(node);

        if (balance > 1 && key > node->left->data) {
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }

        if (balance < -1 && key < node->right->data) {
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }
        return node;
    }

    AVLNode* findMin(AVLNode* node) {
        while (node && node->left) node = node->left;
        return node;
    }

    AVLNode* deleteNode(AVLNode* node, int key) {
        if (!node) return nullptr;

        if (key < node->data) node->left = deleteNode(node->left, key);
        else if (key > node->data) node->right = deleteNode(node->right, key);
        else {
            if (!node->left || !node->right) {
                AVLNode* child = node->left ? node->left : node->right;
                if (!child) {
                    delete node;
                    return nullptr;
                } else {
                    *node = *child;
                    delete child;
                }
            } else {
                AVLNode* succ = findMin(node->right);
                node->data = succ->data;
                node->right = deleteNode(node->right, succ->data);
            }
        }

        updateHeight(node);

        int balance = getBalance(node);

        if (balance > 1 && getBalance(node->left) >= 0) return rotateRight(node);

        if (balance > 1 && getBalance(node->left) < 0) {
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }

        if (balance < -1 && getBalance(node->right) <= 0) return rotateLeft(node);

        if (balance < -1 && getBalance(node->right) > 0) {
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }
        return node;
    }

    bool searchNode(AVLNode* node, int key) {
        if (!node) return false;
        if (key == node->data) return true;
        return key < node->data ? searchNode(node->left, key) : searchNode(node->right, key);
    }

    void inorderTraversal(AVLNode* node) {
        if (!node) return;
        inorderTraversal(node->left);
        cout << node->data << " ";
        inorderTraversal(node->right);
    }

    void printTreeImpl(AVLNode* node, int space, int indent) {
        if (!node) return;
        space += indent;
        printTreeImpl(node->right, space, indent);
        cout << string(max(0, space - indent), ' ') << node->data << "\n";
        printTreeImpl(node->left, space, indent);
    }

    void clear(AVLNode* node) {
        if (!node) return;
        clear(node->left);
        clear(node->right);
        delete node;
    }

public:
    AVLTree() : root(nullptr) {}

    AVLTree(const AVLTree&) = delete;
    AVLTree& operator=(const AVLTree&) = delete;

    ~AVLTree() {
        clear(root);
        root = nullptr;
    }

    void clearAll() {
        clear(root);
        root = nullptr;
    }

    void insert(int key) {
        root = insertNode(root, key);
        cout << "Da chen " << key << " vao cay." << endl;
    }

    void remove(int key) {
        if (search(key)) {
            root = deleteNode(root, key);
            cout << "Da xoa " << key << " khoi cay." << endl;
        } else {
            cout << "Khong tim thay " << key << " trong cay." << endl;
        }
    }

    bool search(int key) { return searchNode(root, key); }

    void display() {
        if (!root) { cout << "Cay rong!" << endl; return; }
        cout << "Cac phan tu trong cay (Inorder): ";
        inorderTraversal(root);
        cout << "\n\nSo do cay (ngang):\n";
        printTreeImpl(root, 0, 6);
        cout << endl;
    }

    bool isEmpty() { return root == nullptr; }
};

void createCustomTree(AVLTree& tree) {
    cout << "\n TU TAO CAY " << endl;
    cout << "Chon cach nhap du lieu:\n";
    cout << "1. Nhap tung gia tri mot\n";
    cout << "2. Nhap tat ca gia tri tren mot dong\n";
    cout << "3. Nhap theo day so (tu a den b, cho phep buoc am)\n";
    cout << "Chon (1-3): ";

    int inputChoice;
    cin >> inputChoice;

    if (inputChoice == 1) {
        int n, value;
        cout << "\nNhap so luong phan tu muon them: ";
        cin >> n;
        if (n <= 0) { cout << "So luong phai lon hon 0!\n"; return; }

        cout << "Nhap " << n << " gia tri:\n";
        for (int i = 0; i < n; i++) {
            cout << "Gia tri thu " << (i + 1) << ": ";
            cin >> value;
            tree.insert(value);
            cout << "  -> Da them " << value << " vao cay\n";
        }
        cout << "\nDa tao cay voi " << n << " phan tu!\n";

    } else if (inputChoice == 2) {
        cout << "\nNhap tat ca gia tri tren mot dong (cach nhau boi dau cach):\n";
        cout << "Vi du: 10 5 15 3 7 12 20\n";
        cout << "Nhap gia tri: ";

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        string line;
        getline(cin, line);

        istringstream iss(line);
        int value, count = 0;
        while (iss >> value) {
            tree.insert(value);
            cout << "  -> Da them " << value << "\n";
            ++count;
        }
        if (count == 0) cout << "Khong co gia tri nao duoc nhap!\n";
        else cout << "\nDa tao cay voi " << count << " phan tu!\n";

    } else if (inputChoice == 3) {
        int start, end, step;
        cout << "\nNhap gia tri bat dau: ";
        cin >> start;
        cout << "Nhap gia tri ket thuc: ";
        cin >> end;
        cout << "Nhap buoc nhay (!= 0, cho phep am): ";
        cin >> step;

        if (step == 0) { cout << "Buoc nhay phai khac 0!\n"; return; }

        cout << "\nDang tao day so tu " << start << " den " << end << " voi buoc " << step << ":\n";
        int count = 0;

        if ((step > 0 && start <= end) || (step < 0 && start >= end)) {
            if (step > 0) {
                for (int i = start; i <= end; i += step) {
                    tree.insert(i);
                    cout << "  -> Da them " << i << "\n";
                    ++count;
                }
            } else {
                for (int i = start; i >= end; i += step) {
                    tree.insert(i);
                    cout << "  -> Da them " << i << "\n";
                    ++count;
                }
            }
            cout << "\nDa tao cay voi " << count << " phan tu!\n";
        } else {
            cout << "Thong so day so khong hop le so voi dau cua buoc nhay!\n";
        }

    } else {
        cout << "Lua chon khong hop le!\n";
    }
}

void displayCreateTreeMenu() {
    cout << "\n TAO CAY AVL \n";
    cout << "1. Tu nhap cac gia tri\n";
    cout << "2. Tao cay rong\n";
    cout << "Chon (1-2): ";
}

void displayMenu() {
    cout << "\n MENU CAY AVL \n";
    cout << "1. Tao cay moi\n";
    cout << "2. Chen phan tu\n";
    cout << "3. Xoa phan tu\n";
    cout << "4. Tim kiem phan tu\n";
    cout << "5. Hien thi cay (inorder + so do)\n";
    cout << "6. Thoat\n";
    cout << "Chon chuc nang (1-6): ";
}

int main() {
    SetConsoleOutputCP(65001);
    AVLTree tree;
    int choice, value;

    while (true) {
        displayMenu();
        if (!(cin >> choice)) {
            cout << "Du lieu khong hop le. Thoat.\n";
            return 0;
        }

        switch (choice) {
            case 1: {
                tree.clearAll();
                int createChoice;
                displayCreateTreeMenu();
                cin >> createChoice;

                if (createChoice == 1) {
                    createCustomTree(tree);
                } else if (createChoice == 2) {
                    cout << "Da tao cay rong!\n";
                } else {
                    cout << "Lua chon khong hop le!\n";
                }
                break;
            }
            case 2:
                cout << "Nhap gia tri can chen: ";
                cin >> value;
                tree.insert(value);
                break;

            case 3:
                cout << "Nhap gia tri can xoa: ";
                cin >> value;
                tree.remove(value);
                break;

            case 4:
                cout << "Nhap gia tri can tim: ";
                cin >> value;
                cout << (tree.search(value) ? "Tim thay " : "Khong tim thay ") << value << " trong cay.\n";
                break;

            case 5:
                tree.display();
                break;

            case 6:
                cout << "Cam on ban da su dung chuong trinh!\n";
                return 0;

            default:
                cout << "Lua chon khong hop le! Vui long chon tu 1-6.\n";
                break;
        }
    }
}
