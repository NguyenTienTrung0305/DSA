#include <bits/stdc++.h>
using namespace std;
int n , m;
int degree[1001];
vector<vector<int>> res(1001);
void input(){
    cin >> n >> m;
    for (int i = 0 ; i < m ; i++){
        int a , b;
        cin >> a >> b;
        res[a].push_back(b);
        degree[b]++;
    }
}

void solve(){
    queue<int> qe;
    for (int i = 1 ; i <= n ; i++){
        if (degree[i] == 0){
            qe.push(i);
        }
    }
    while(!qe.empty()){
        int u = qe.front();
        qe.pop();
        for (auto x : res[u]){

        }
    }
}
int main(){
    return 0;
}