#include <bits/stdc++.h>
using namespace std;

// Node của cây AA
struct Node
{
    int key;        // giá trị của node
    int level;      // level của node trong cây AA
    Node* left;     // con trái
    Node* right;    // con phải
    Node(int k) : key(k), level(1), left(nullptr), right(nullptr) {}
};

class AATree
{
private:
    Node* root; // gốc cây

    // Skew: xoay phải nếu node con trái cùng level
    Node* skew(Node* node)
    {
        if (!node || !node->left) return node;
        if (node->left->level == node->level)
        {
            Node* l = node->left;
            node->left = l->right;
            l->right = node;
            return l;
        }
        return node;
    }

    // Split: xoay trái nếu node con phải phải cùng level
    Node* split(Node* node)
    {
        if (!node || !node->right || !node->right->right) return node;
        if (node->right->right->level == node->level)
        {
            Node* r = node->right;
            node->right = r->left;
            r->left = node;
            r->level++;
            return r;
        }
        return node;
    }

    // Hàm đệ quy chèn node
    Node* ins(Node* node, int k)
    {
        if (!node) return new Node(k);
        if (k < node->key) node->left = ins(node->left, k);
        else if (k > node->key) node->right = ins(node->right, k);
        else return node; // trùng key

        node = skew(node);
        node = split(node);
        return node;
    }

    // Tìm node kế tiếp (successor) để dùng khi xóa node có 2 con
    Node* succ(Node* node)
    {
        node = node->right;
        while (node && node->left) node = node->left;
        return node;
    }

    // Giảm level sau khi xóa nếu cần
    Node* dec(Node* node)
    {
        int lvLeft = 0, lvRight = 0;
        if (node->left) lvLeft = node->left->level;
        if (node->right) lvRight = node->right->level;
        int shouldBe = min(lvLeft, lvRight) + 1;

        if (shouldBe < node->level)
        {
            node->level = shouldBe;
            if (node->right && node->right->level > shouldBe)
                node->right->level = shouldBe;
        }
        return node;
    }

    // Hàm đệ quy xóa node
    Node* del(Node* node, int k)
    {
        if (!node) return nullptr;
        if (k < node->key) node->left = del(node->left, k);
        else if (k > node->key) node->right = del(node->right, k);
        else
        {
            // Node có <=1 con
            if (!node->left || !node->right)
            {
                Node* tmp;
                if (node->left) tmp = node->left;
                else tmp = node->right;
                delete node;
                return tmp;
            }
            else     // Node có 2 con
            {
                Node* s = succ(node);
                node->key = s->key; // thay key bằng successor
                node->right = del(node->right, s->key);
            }
        }

        // Điều chỉnh cây sau xóa
        node = dec(node);
        node = skew(node);
        if (node->right) node->right = skew(node->right);
        if (node->right && node->right->right)
            node->right->right = skew(node->right->right);
        node = split(node);
        if (node->right) node->right = split(node->right);
        return node;
    }

    // Tìm node theo key
    Node* search(Node* node, int k)
    {
        if (!node) return nullptr;
        if (k == node->key) return node;
        if (k < node->key) return search(node->left, k);
        return search(node->right, k);
    }

    // Duyệt cây theo thứ tự in-order
    void inorder(Node* node)
    {
        if (!node) return;
        inorder(node->left);
        cout << node->key << " ";
        inorder(node->right);
    }

    // In cây theo cấu trúc, khoảng trắng
    void print(Node* node, int ind)
    {
        if (!node) return;
        print(node->right, ind + 4); // in nhánh phải trước
        cout << string(ind, ' ') << node->key << "(" << node->level << ")\n";
        print(node->left, ind + 4); // sau đó nhánh trái
    }

    // Đếm số node
    int cnt(Node* node)
    {
        if (!node) return 0;
        return 1 + cnt(node->left) + cnt(node->right);
    }

    // Tính chiều cao cây
    int height(Node* node)
    {
        if (!node) return 0;
        return 1 + max(height(node->left), height(node->right));
    }

    // Tìm key nhỏ nhất
    int minKey(Node* node)
    {
        if (!node) return INT_MIN;
        while (node->left) node = node->left;
        return node->key;
    }

    // Tìm key lớn nhất
    int maxKey(Node* node)
    {
        if (!node) return INT_MAX;
        while (node->right) node = node->right;
        return node->key;
    }

public:
    AATree() : root(nullptr) {}

    // Các thao tác công khai
    void insert(int k)
    {
        root = ins(root, k);
    }
    void remove(int k)
    {
        root = del(root, k);
    }
    void insertMultiple(const vector<int>& v)
    {
        for(int x:v) insert(x);
    }
    void removeMultiple(const vector<int>& v)
    {
        for(int x:v) remove(x);
    }
    void display()
    {
        cout << "Cay (in-order): ";
        inorder(root);
        cout << "\n";
    }
    void printTree()
    {
        if(!root)
        {
            cout<<"Cay rong!\n";
            return;
        }
        print(root,0);
    }
    void stats()
    {
        cout<<"So node: "<<cnt(root)<<", Chieu cao: "<<height(root)<<", Min: "<<minKey(root)<<", Max: "<<maxKey(root)<<"\n";
    }

    // Tìm node và in chi tiết (level và bên)
    void searchDetail(int k)
    {
        Node* n = search(root, k);
        if (!n)
        {
            cout << "Khong tim thay " << k << " trong cay.\n";
            return;
        }
        string side = "root";
        Node* c = root;
        while (c != n)
        {
            if (k < c->key)
            {
                side = "left";
                c = c->left;
            }
            else
            {
                side = "right";
                c = c->right;
            }
        }
        cout << "Tim thay " << k << ", level: " << n->level << ", ben: " << side << "\n";
    }
};

int main()
{
    AATree t;
    vector<int> init = {2,4,6,8,10,12,14,16,18,20};
    t.insertMultiple(init);
    cout << "Da chen chuoi mac dinh: ";
    for(int x:init) cout << x << " ";
    cout<<"\n";

    int ch;
    while(true)
    {
        cout<<"\n=== MENU ===\n1.Chen\n2.Xoa\n3.Tim\n4.In-order\n5.In theo cau truc\n6.Thong tin\n7.Thoat\nChon: ";
        if(!(cin>>ch))
        {
            cin.clear();
            cin.ignore(1000,'\n');
            cout<<"Nhap so hop le!\n";
            continue;
        }
        if(ch==7) break;

        switch(ch)
        {
        case 1:
        {
            cout<<"Nhap danh sach can chen: ";
            string line;
            cin.ignore();
            getline(cin,line);
            stringstream ss(line);
            int v;
            vector<int> vals;
            while(ss>>v) vals.push_back(v);
            t.insertMultiple(vals);
            cout<<"Da chen!\n";
            break;
        }
        case 2:
        {
            cout<<"Nhap danh sach can xoa: ";
            string line;
            cin.ignore();
            getline(cin,line);
            stringstream ss(line);
            int v;
            vector<int> vals;
            while(ss>>v) vals.push_back(v);
            t.removeMultiple(vals);
            cout<<"Da xoa!\n";
            break;
        }
        case 3:
        {
            cout<<"Nhap gia tri can tim: ";
            int v;
            cin>>v;
            t.searchDetail(v);
            break;
        }
        case 4:
            t.display();
            break;
        case 5:
            t.printTree();
            break;
        case 6:
            t.stats();
            break;
        default:
            cout<<"Lua chon khong hop le!\n";
        }
    }
    return 0;
}
