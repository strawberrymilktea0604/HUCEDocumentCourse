#include<bits/stdc++.h>

using namespace std;

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

int CountLeaves(Node* r){
    if (r == NULL) return 0;
    if (r->leftMostChild == NULL) return 1;
    int result = 0;
    for (Node* p = r->leftMostChild; p != NULL; p = p->rightSibling){
        result += CountLeaves(p);
    }
    return result;
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
        }else if (str == "$CountLeaves"){
            int v;
            cin >> v;
            Node* r = find(v, root);
            cout << CountLeaves(r) << endl;
        }else if (str == "*") break;
    }

    return 0;
}