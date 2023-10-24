// Exercise 1: Connected components
// Given an undirected computer network with n nodes (numbered from 1 to n) and m
// edges, your task is to write a program to calculate the number of connected 
// components

#include <bits/stdc++.h>
using namespace std;
int n , m;
bool isVisited[1001];
vector<vector<int>> res(1001);

void init(){
    for (int i = 1 ; i<= m ; i++){
        int x , y; cin >> x >> y;
        res[x].push_back(y);
        res[y].push_back(x);
    }
}

void dfs(int u){
    isVisited[u] = true;
    for (auto v : res[u]){
        if (!isVisited[v]){
            dfs(v);
        }
    }
}

int main() {
    int result = 0;
    cin >> n >> m;
    memset(isVisited , false , sizeof(isVisited));
    init();
    for ( int i = 1 ; i <= n ; i++){
        if (!isVisited[i]){
            dfs(i);
            ++result;
        }
    }
    cout << result;
    return 0;
}
