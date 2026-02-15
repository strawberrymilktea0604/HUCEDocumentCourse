#include<bits/stdc++.h>
 
using namespace std;
 
const int MAX = 1000000;
 
typedef struct LinkedList{
    string data;
    LinkedList *next;
}Node;
 
Node *makeNode(string k){
    Node *tmp = new Node;
    tmp->data = k;
    tmp->next = NULL;
    return tmp;
}
 
Node *head = NULL;
 
Node *addLast(string k){
    Node *temp, *p;
    temp = makeNode(k);
    if (head == NULL){
        head = temp;
    }else{
        p = head;
        while (p->next != NULL)
            p = p->next;
        p->next = temp;
    }
    return head;
}
 
int find(string k){
    int res = 0;
    for (Node *p = head; p != NULL; p = p->next){
        if (p->data == k) res = 1;
    }
    return res;
}
 
int insert(string k){
    if (find(k) == 1){
        // k exists in the database
        return 0;
    }else{
        head = addLast(k);
        return 1;
    }
}
 
int main(int argc, const char** argv) {
    string data;
    while (1){
        cin >> data;
        if (data == "*") break;
        else{
            head = addLast(data);
        }
    }
 
    string k;
    string str;
    while (1){
        cin >> str;
        if (str == "$find"){
            cin >> k;
            cout << find(k) << endl;
        }
        if (str == "$insert"){
            cin >> k;
            cout << insert(k) << endl;
        }
        if (str == "***") break;
    }
    return 0;
}