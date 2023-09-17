#include <bits/stdc++.h>
using namespace std;
int main(){
    map<int , int> mp;
    int count = 0;
    int n ; cin >> n;
    for (int i = 0 ; i < n ;i++){
        int x ; cin >> x;
        mp[x]++;
    }
    for ( pair<int,int> x : mp){
        count+= (x.second)*(x.second-1)/2;
    }
    cout << count;
    return 0;
}