#include<bits/stdc++.h>

using namespace std;

struct Node{
    int id;
    struct Node* leftMostChild;// con tro den con trai nhat
    struct Node* rightSibling;// con tro den anh em ben phai
};

Node* root;

Node* makeNode(int v){
    Node* p = new Node;
    p->id = v;
    p->leftMostChild = NULL; 
    p->rightSibling = NULL;
    return p;
}

Node* find(int v, Node* r){
    // tra ve con tro den nut co id bang v tren cay goc r
    if (r == NULL) return NULL;
    if (r->id == v)  return r;
    Node* p = r->leftMostChild;
    while (p != NULL){
        Node* q = find(v, p);
        if (q != NULL) return q;
        p = p->rightSibling;
    }
    return NULL;
}

void insert(int u, int v){
    // tao mot nut co id bang u, chen vao cuoi DS nut con cua nut co id bang v
    // tren cay goc la root
    Node* r = find(v, root);
    Node* p = NULL;

    p = makeNode(u);
    if (r->leftMostChild == NULL)
        r->leftMostChild = p;
    else{
        Node* h = r->leftMostChild;
        while (h->rightSibling != NULL)
            h = h->rightSibling;
        h->rightSibling = p;
    }
}

void printTree(Node* r){
    if (r == NULL) return;
    cout << r->id;
    for (Node* p = r->leftMostChild; p != NULL; p = p->rightSibling){
        cout << p->id;
    }
    cout << endl;
    for(Node* p = r->leftMostChild; p != NULL; p = p->rightSibling){
        printTree(p);
    }
}

void inOrder(Node* r){
    if (r == NULL) return ;
    Node* p = r->leftMostChild;// p tro vao nut goc cay con r1
    inOrder(p);
    cout << r->id << " ";// tham nut goc
    if (p == NULL) return;
    p = p->rightSibling;// truy cap den goc r2
    while (p != NULL){
        inOrder(p);// tham cay theo thu tu giua
        p = p->rightSibling;
    }
}
void preOrder(Node* r){
    if (r == NULL) return;
    cout << r->id << " ";
    Node* p = r->leftMostChild;
    while (p != NULL){
        preOrder(p);
        p = p->rightSibling;
    }

}

void postOrder(Node* r){
    if (r == NULL) return;
    Node* p = r->leftMostChild;
    while(p != NULL){
        postOrder(p);
        p = p->rightSibling;
    }
    cout << r->id << " ";
}

int main(int argc, const char** argv) {
    string str;
    while (true){
        cin >> str;
        if (str == "$MakeRoot"){
            int v;
            cin >> v;
            root = makeNode(v);
        }else if (str == "$Insert"){
            int u, v;
            cin >> u >> v;
            insert(u, v);
        }else if (str == "$InOrder"){
            inOrder(root);
            cout << endl;
        }else if (str == "$PreOrder"){
            preOrder(root);
            cout << endl;
        }else if (str == "$PostOrder"){
            postOrder(root);
            cout << endl;
        }else if (str == "*") break;
    }

    return 0;
}