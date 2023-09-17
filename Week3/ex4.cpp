#include <bits/stdc++.h>
using namespace std;

int arr[10000];
int index;

void enqueue(int x){
    arr[index++] =x;
}

void dequeue(){
    for (int i = 0 ; i < index ; i++){
        arr[i] = arr[i+1];
    }
    arr[index-1] = '\0';
    --index;
}

void printQueue(){
    for (int i = 0 ;i < index ; i++){
        cout << arr[i] <<" ";
    }
}
int main(){
    cin >> index;
    int t ; cin >> t;
    while (t--){
        cout << "==================\n";
        cout << "1. enqueue\n";
        cout << "2. dequeue\n";
        cout << "3. print queue\n";
        cout << "=================\n";

        int lc ; cin >> lc;
        if (lc == 1){
            int x ; cin >> x;
            enqueue(x);
        }else if (lc == 2){
            dequeue();
        }else if (lc == 3){
            printQueue();
        }
    }
    return 0;
}