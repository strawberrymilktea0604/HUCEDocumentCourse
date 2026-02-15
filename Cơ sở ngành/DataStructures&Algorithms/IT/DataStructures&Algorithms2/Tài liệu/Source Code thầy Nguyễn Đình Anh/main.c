//
//  main.c
//  PriorityQueue
//
//  Created by Anh Nguyen on 11/24/17.
//  Copyright © 2017 Anh Nguyen. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int priority;
    char *task;
} node;

typedef struct {
    node *nodes;
    int len; // so phan tu da dung trong nodes
    int size; // kich co cua nodes
} heap;

void insert(heap *h, int priority, char *task) {
    // kiem tra xem co can thay doi kich co cua mang dong nodes
    if(h->len+1 >= h->size) {
        h->size = h->size ? h->size*2 : 4;
        h->nodes = (node *)realloc(h->nodes, h->size * sizeof(node));
    }
    // Tinh chi so vi tri cuoi cung va vi tri cha cua no
    int i = h->len+1;
    int j = i/2;
    // thuc hien upheap
    while (i > 1 && h->nodes[j].priority < priority) {
        h->nodes[i] = h->nodes[j];
        i = j;
        j = j/2;
    }
    h->nodes[i].task = task;
    h->nodes[i].priority = priority;
    h->len++;
}

char * removeMin(heap *h) {
    if (!h->size) {
        return NULL;
    }
    char * data = h->nodes[1].task;
    h->nodes[1] = h->nodes[h->len];
    h->len--;
    //Down heap
    int i = 1;
    while(1) {
        int k=i;
        int j = 2*i;
        if (j <= h->len && h->nodes[j].priority < h->nodes[k].priority ) {
            k = j;
        }
        if (j+1 <= h->len && h->nodes[j+1].priority < h->nodes[k].priority) {
            k = j+1;
        }
        if (k==i) break;
        h->nodes[i] = h->nodes[k];
        i = k;
    }
    
    h->nodes[i] = h->nodes[h->len+1];
    return data;
}

char* getMin(heap *h) {
    if (!h->len) {
        return NULL;
    }
    return h->nodes[1].task;
}

int main() {
    heap *h = (heap *)malloc(1*sizeof(heap));
    h->len = 0;
    h->size = 0;
    insert(h, 5,"Hoc bai");
    insert(h, 1,"Di choi");
    insert(h, 3,"Ngu");
    insert(h, 4,"An com");
    insert(h, 2,"Tam");
    int len = h->len;
    for(int i=0; i<len; i++) {
        printf("%s\n",removeMin(h));
    }
    return 0;
}
