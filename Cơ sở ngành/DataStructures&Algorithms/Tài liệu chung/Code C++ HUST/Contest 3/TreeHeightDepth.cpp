#include<bits/stdc++.h>
#include<string.h>

using namespace std;

struct Node{
    int id;
    Node* leftMostChild; // con tro tro den nut con trai nhat
    Node* rightSibling; // con tro tro den nut anh em ben phai
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

int heightNode(Node* r){
    if (r == NULL) return 0;
    int maxH = 0;
    for (Node* p = r->leftMostChild; p != NULL; p = p->rightSibling){
        int h = heightNode(p);
        if (h > maxH) maxH = h;
    }
    return maxH + 1;
}
int height(int u){
    // Tra ve do cao cua nut co id = u
    Node* r = find(u, root);
    return heightNode(r);
}

int depthNode(Node* r, int v, int d){
    // d la do sau cua nut r
    if (r == NULL) return -1;
    if (r->id == v) return d;
    Node* p = r->leftMostChild;
    for (Node* p = p->leftMostChild; p != NULL; p = p->rightSibling){
        if (p->id == v) return d+1;
        int rs = depthNode(p, v, d+1);
        if (rs > -1) return rs;
    }
    return -1;
}
int depth(int u){
    // Tra ve do sau cua nut co id = u
    return depthNode(root, u, 1);
    // Do sau tinh tu nut goc (root) = 1
}


int main(int argc, const char** argv) {
    string str;
    while (true){
        cin >> str;
        if (str == "$MakeRoot"){
            int u;
            cin >> u;
            root = makeNode(u);
        }else if (str == "$Insert"){
            int u, v;
            cin >> u >> v;
            insert(u, v);
        }else if (str == "$Height"){
            int u;
            cin >> u;
            cout << height(u) << endl;
        }else if (str == "$Depth"){
            int u;
            cin >> u;
            cout << depth(u) << endl;
        }
        if (str == "*") break;
    }
    return 0;
}
