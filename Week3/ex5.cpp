#include <bits/stdc++.h>
using namespace std;

int arr[10000];
int index;

void push(int x){
    arr[index++] =x;
}

void pop(){
    --index;
    arr[index] ='\0'; 
}

void printStack(){
    for (int i = index -1 ;i >= 0 ; i--){
        cout << arr[i] <<" ";
    }
}
int main(){
    cin >> index;
    int t ; cin >> t;
    while (t--){
        cout << "==================\n";
        cout << "1. push\n";
        cout << "2. pop\n";
        cout << "3. print stack\n";
        cout << "=================\n";

        int lc ; cin >> lc;
        if (lc == 1){
            int x ; cin >> x;
            push(x);
        }else if (lc == 2){
            pop();
        }else if (lc == 3){
            printStack();
        }
    }
    return 0;
}