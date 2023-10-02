// Your task is to write operations of stack data structure in pseudo-codes using a 
// linked list, then evaluate the complexities of the operations

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
Node* push(Node* root ,int value){
    Node* p = makeNode(value);
    if (root == NULL ){
        root = p;
    }else{
        p->next = root;
        root = p;
    }
    return root;
}

//
int top(Node* root){
    return root->data;
}

// O(1)
Node* pop(Node* root){
    root = root->next;
    return root;
}

int main(){
    Node* root = makeNode(3);
    root = push(root , 4);
    root = push(root , 5);
    cout << top(root) << endl;
    root = pop(root);
    cout << top(root) << endl;
    return 0;
}