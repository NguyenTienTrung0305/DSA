#include <bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node* next;
};

Node* insertNode(Node* head , int pos , int value){
    Node* p = new Node();
    p->data = value;
    p->next = NULL;
    Node* tmp = head;
    for ( int i = 1 ; i < pos -1; i++){
        tmp = tmp->next;
    }
    p->next = tmp->next;
    tmp->next = p;
    return head;
}

Node* deleteNode(Node* head , int pos){
    Node* prev = NULL;
    Node* behind = head;
    for (int i = 1 ; i < pos ; i++){
        prev = behind;
        behind = behind->next;
    }
    if ( prev == NULL){
        head = NULL;
    }else{
        prev->next = behind->next;
    }

    return head;
}

void printNode(Node* head){
    while (head != NULL){
        cout << head->data << " ";
        head = head->next;
    }
}

int main(){
    int n ; cin >> n;
    Node* head = new Node();
    head->data = 1;
    head->next = NULL;
    for ( int i = 1 ; i <= n ;i++){
        insertNode(head , i+1 , i*2);
    }
    printNode(head);
    deleteNode(head , 2);
    printNode(head);
    return 0;
}