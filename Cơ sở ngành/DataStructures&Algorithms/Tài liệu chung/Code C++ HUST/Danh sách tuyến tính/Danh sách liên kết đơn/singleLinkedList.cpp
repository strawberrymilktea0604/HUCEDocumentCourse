#include<bits/stdc++.h>

using namespace std;

typedef struct LinkedList{
    int value;
    struct LinkedList* next;
}Node;

Node* head;

// Tạo node
Node* makeNode(int x){
    Node* p = new Node;
    p->value = x;
    p->next = NULL;
    return p;
}

// Duyệt in danh sách
void printList(Node* head){
    Node* p = head;
    while (p != NULL){
        cout << p->value << " ";
        p = p->next;
    }
}

// Thêm node có trường value = x vào đầu danh sách
Node* addFirst(int x, Node* head){
    Node* p = makeNode(x);
    p->next = head;
    return p;
}

// Thêm node có trường value = x vào cuối danh sách
Node* addLast(int x, Node* head){
    Node* temp = makeNode(x);

    if (head == NULL){
        head = temp;
    }else{
        Node* p = head;
        // p trỏ đến phần tử cuối cùng
        while (p->next != NULL){
            p = p->next;
        }
        p->next = temp;
    }
    return head;
}

// Thêm 1 node có trường value = x vào trước node đầu tiên có giá trị y trên danh sách
Node* insertBefore(int x, int y, Node* head){
    if (head == NULL) return NULL;
    if (head->value == y){ // Nếu y ở trong phần tử đầu
        // Chèn phần tử mới vào đầu danh sách
        Node* p = makeNode(x);
        p->next = head;
        return p;
    }

    // Nếu không gọi đệ quy, tìm trong danh sách con
    head->next = insertBefore(x, y, head->next);
    return head;
}

// Thêm 1 node có trường value = x vào sau node đầu tiên có giá trị y trên danh sách
Node* insertAfter(int x, int y, Node* head){
    if (head == NULL) return NULL;
    if (head->value == y){ // Nếu y ở trong phần tử đầu
        Node* p = makeNode(x);
        p->next = head->next;
        head->next = p;
        return head;
    }

    // Nếu không gọi đệ quy, tìm trong danh sách con
    head->next = insertAfter(x, y, head->next);
    return head;
}

// Xóa node đầu tiên có trường value = x trong danh sách
Node* remove(int x, Node* head){
    if (head == NULL) return NULL;
    if (head->value == x){
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    Node* p = head;
    while (p->next != NULL){
        if (p->next->value == x) break;
        p = p->next;
    }
    if (p->next != NULL){
        Node* temp = p->next;
        p->next = temp->next;
        delete temp;
    }
    return head;
}

void freeList(Node* head){
    if (head == NULL) return;
    freeList(head->next); // Gọi đệ quy giải phóng vùng nhớ cho danh sách con
    delete(head); // Giải phóng vùng nhớ cho head
    
}

// Đảo ngược danh sách
Node* reverse(Node* head){
    Node* p = head;
    Node* pp = NULL; // phần tử trước p (previous p)
    Node* np = NULL;
    while (p != NULL){
        np = p->next;
        p->next = pp;
        pp = p;
        p = np;
    }
    return pp;
}

int main(int argc, const char** argv) {
    head = NULL;
    for (int i = 1; i <= 10; i++){
        head = addLast(i, head);
    }
    printList(head);
    cout << endl;

    head = remove(1, head);
    cout << "After removing: ";
    printList(head);
    cout << endl;

    head = remove(1000, head);
    cout << "After removing: ";
    printList(head);
    cout << endl;

    head = remove(7, head);
    cout << "After removing: ";
    printList(head);
    cout << endl;

    head = insertBefore(11, 3, head);
    cout << "After inserting 11 before node 3: ";
    printList(head);
    cout << endl;

    head = insertAfter(12, 5, head);
    cout << "After inserting 12 after node 5: ";
    printList(head);
    cout << endl;


    head = reverse(head);
    cout << "After reversing: ";
    printList(head);
    cout << endl;

    return 0;
}