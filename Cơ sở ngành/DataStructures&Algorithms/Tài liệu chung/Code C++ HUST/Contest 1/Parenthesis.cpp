#include<bits/stdc++.h>

typedef struct StackNode {
    char c; //bieu dien dau ngoac
    struct StackNode* next;
} Node;

Node* makeNode(char c) {
    Node* p=(Node*)malloc(sizeof(Node));
    p->c=c;
    p->next=NULL;
    return p;
}

Node* top=NULL; //con tro den dinh cua stack

void push(char c) {
    Node* p = makeNode(c);
    p->next = top;
    top = p;
}
char pop() { //lay 1 phan tu khoi stack, tra ve truong c
    if(top==NULL) return NULL;
    char c=top->c;
    Node* temp=top;
    top=top->next;
    free(temp); //thu hoi bo nho
    return c;
}
int empty() { //tra ve 1 neu stack la rong, tra ve 0 neu nguoc lai
    return top==NULL;
}
int match(char o, char c) {
    if(o=='(' && c==')') return 1;
    if(o=='(' && c==')') return 1;
    if(o=='(' && c==')') return 1;
    return 0;
}
int check(char* s) {
    for(int i=0;i<strlen(s);i++) {
        if(s[i]=='(' || s[i]=='[' || s[i]=='{') {
            push(s[i]);
        }
        else {
            if(empty()==1) return 0;
            char o=pop(); //lay ngoac mo tu stack
            if(match(o,s[i]==0)) return 0;
        }
    }
    return empty();
}
int main() {
    char s[1000001];
    scanf("%s", s);
    printf("%d", check(s));
}