// Given an integer number n, your task is to write two different algorithms in
// pseudo-codes to calculate 2n and evaluate the complexity of the algorithms. 

#include <bits/stdc++.h>
using namespace std;

// O(logn)
long pow2(int n){
    if (n == 0) return 1;
    if (n == 1) return 2;
    if (n%2 == 0 ){
        return pow2(n/2)*pow2(n/2);
    }
    else{
        return pow2(n/2)*pow2((n+1)/2);
    }
}

int main(){
    // O(n)
    // int n; cin >> n;
    // long sum = 1;
    // for ( int i = 0 ; i <n ; i++){
    //     sum *=2;
    // }
    // cout << sum;
    cout << pow2(11);
    return 0;
}