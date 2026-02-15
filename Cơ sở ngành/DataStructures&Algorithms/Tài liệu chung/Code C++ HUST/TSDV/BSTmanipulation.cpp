#include<bits/stdc++.h>

using namespace std;

typedef struct Node{
    int data;
    Node* left;
    Node* right;
}BST;

// Điều hướng cây nhị phân 
// Không cho phép thêm phần tử đã có trên cây (Bỏ qua trùng lặp giá trị)
int LeftOf(int k, BST* root){
    return k < root->data;
}
int RightOf(int k, BST* root){
    return k > root->data;
}

// Thêm nút vào cây BST
BST* Insert(BST* root, int k){
    if (root == NULL){
        BST* node = new Node;
        node->left = NULL;
        node->right = NULL;
        node->data = k;
        return node;
    }
    if (LeftOf(k, root)){
        root->left = Insert(root->left, k);
    }else if (RightOf(k, root)){
        root->right = Insert(root->right, k);
    }

    return root;
}

// Duyệt thứ tự trước
void PreOrder(BST* root){
    if (root != NULL){
        cout << root->data << " ";
        PreOrder(root->left);
        PreOrder(root->right);
    }
}

int main(int argc, const char** argv) {
    BST* root = NULL;
    string str;
    while (str != "#"){
        cin >> str;
        if (str == "$insert"){
            int k;
            cin >> k;
            root = Insert(root, k);
        }
    }
    PreOrder(root);
    return 0;
}