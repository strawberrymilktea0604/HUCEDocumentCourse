#include<bits/stdc++.h>

using namespace std;

typedef struct LinkedList{
    string name;
    int age;
    LinkedList *next;
} Node;


Node *makeNode(string name, int age){
    Node *tmp = new Node;
    tmp->name = name;
    tmp->age = age;
    tmp->next = NULL;
    return tmp;
}

Node *head = NULL;

Node *addFirst(string name, int age){
    Node *temp = makeNode(name, age);
    if (head == NULL){
        head = temp;
    }else{
        temp->next = head;
        head = temp;
    }
    return head;
}

Node *addLast(string name, int age){
    Node *temp, *p;
    temp = makeNode(name, age);
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

Node *removeNode(Node *head, string name){
    if(head == NULL) return NULL;
    if(head->name == name) {
    	Node *tmp = head;
		head = head->next;
		free(tmp);
		head = removeNode(head, name);
		return head;
	}
    head->next = removeNode(head->next, name);
	return head;
}

int main(int argc, const char** argv) {
    string name;
    int age;
    string str;
    while (1){
        cin >> str;
        if (str == "$addfirst"){
            cin >> name;
            cin >> age;
            head = addFirst(name, age);
        }
        if (str == "$addlast"){
            cin >> name;
            cin >> age;
            head = addLast(name, age);
        }
        if (str == "$remove"){
            cin >> name;
            head = removeNode(head, name);
        }
        if (str == "***") break;
    }

    for (Node *p = head; p != NULL; p = p->next){
        cout << p->name << " ";
    }
    return 0;
}