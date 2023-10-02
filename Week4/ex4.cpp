// Your task is to write operations of queue data structure in pseudo-codes using a 
// linked list, then evaluate the complexities of the operations.

#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
};

Node* makeNode(int data){
    Node* p = new Node();
    p->data = data;
    p->next = NULL;
    return p;
}

// O(n) : n is size of root
Node* enqueue(Node* root ,int value){
    Node* p = makeNode(value);
    if (root == NULL ){
        root = p;
    }else{
        Node* tmp = root;
        while(tmp->next != NULL){
            tmp = tmp->next;
        }
        tmp->next = p;
    }
    return root;
}

// O(1)
Node* dequeue(Node* root){
    root = root->next;
    return root;
}



int main(){
    Node* root = makeNode(3);
    root = enqueue(root , 4);
    root = enqueue(root , 5);
    root = dequeue(root);
    cout << root->data << endl;
    root = dequeue(root);
    cout << root->data << endl;
    return 0;
}