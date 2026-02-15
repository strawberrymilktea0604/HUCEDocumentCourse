#include <bits/stdc++.h>

using namespace std;

typedef struct LinkedList{
    int value;
    LinkedList *next;
} Node;


Node *makeNode(int value){
    Node *tmp = new Node;
    tmp->value = value;
    tmp->next = NULL;
    return tmp;
}

Node *head = NULL;

Node *addNode(int value){
    if (head == NULL)
        return makeNode(value);
    else{
        Node *p = head;
        while (p->next != NULL)
            p = p->next;
        p->next = makeNode(value);
    }
    return head;
}

Node *deleteNode(int value){
    Node *p = head, *prev;
    while (head->value == value)
        head = head->next;
    while (p->next != NULL){
        if (p->next->value == value)
            p->next = p->next->next;
        else
            p = p->next;
    }
    return head;
}

void printList(){
    Node *p = head;
    while (p != NULL) {
        cout << p->value << " ";
        p = p->next;
    }
}

int main(int argc, char const *argv[]){
    int n;
    cin >> n;
    int tmp;
    for (int i = 0; i < n; i++){
        cin >> tmp;
        head = addNode(tmp);
    }

    int m;
    cin >> m;
    for (int i = 0; i < m; i++){
        cin >> tmp;
        deleteNode(tmp);
    }

    printList();

    return 0;
}