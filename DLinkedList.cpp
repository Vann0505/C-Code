#include <stdio.h>
#include <stdlib.h>

struct Node {
    int angka;
    struct Node *next;
    struct Node *prev;
} *head, *tail;

Node *createNode(int angka) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->angka = angka;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void pushHead(int angka) {
    Node *temp = createNode(angka);
    if (!head) {
        head = tail = temp;
    } else {
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}

void pushTail(int angka) {
    Node *temp = createNode(angka);
    if (!head) {
        head = tail = temp;
    } else {
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}

void pushMid(int angka, int flag) {
    Node *temp = createNode(angka);
    if (!head) {
        head = tail = temp;
        return;
    }

    Node *curr = head;
    while (curr) {
        if (curr->angka == flag) {
            if (curr == tail) {
                pushTail(angka);
            } else {
                temp->next = curr->next;
                temp->prev = curr;
                curr->next->prev = temp;
                curr->next = temp;
            }
            return;
        }
        curr = curr->next;
    }
    printf("Data %d is not found\n", flag);
}

void popHead() {
    if (!head) return;
    if (head == tail) {
        free(head);
        head = tail = NULL;
    } else {
        Node *temp = head;
        head = head->next;
        head->prev = NULL;
        free(temp);
    }
}

void popTail() {
    if (!head) return;
    if (head == tail) {
        free(head);
        head = tail = NULL;
    } else {
        Node *temp = tail;
        tail = tail->prev;
        tail->next = NULL;
        free(temp);
    }
}

void popMid(int angka) {
    if (!head) return;
    if (head->angka == angka) {
        popHead();
        return;
    }
    if (tail->angka == angka) {
        popTail();
        return;
    }
    
    Node *curr = head;
    while (curr && curr->angka != angka) {
        curr = curr->next;
    }
    if (!curr) { 
        printf("Data ke %d gak ada\n", angka);
        return;
    }
    
    curr->prev->next = curr->next;
    curr->next->prev = curr->prev;
    free(curr);
}

void print() {
    
	if (!head) {
        printf("Gada Isinya\n");
        return;
    }
    Node *curr = head;
    while (curr) {
        printf("%d <-> ", curr->angka);
        curr = curr->next;
    }
    printf("NULL\n");
}

int main() {
    pushHead(10);
    pushTail(20);
    pushMid(15, 10);
    pushMid(25, 20);
    print();
    
    popHead();
    print();
    
    popTail();
    print();
    
    popMid(15);
    print();
    
    return 0;
}

