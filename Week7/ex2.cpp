// Exercise 2: Shortest path
// Given a directed computer network with n nodes (numbered from 1 to n) and m
// edges, your task is to write a program to find the shortest path that has the minimum 
// number of edges between two node X and Y

#include <bits/stdc++.h>
using namespace std;
int n,m , s,t;
vector<pair<int,int>> adj[1001];
void init(){
    cin >> n >> m >> s >> t;
    for (int i =1 ; i<= m ; i++){
        int x , y ,w;
        cin >> x >> y >> w;
        adj[x].push_back({y,w});
    }
}

const int INF = 1e9;

void dijkstra(int s , int t){
    // mang luu khoang cach duong di
    vector<long long> path(n+1,INF);
    path[s] = 0;

    // mang check xem da tim duoc khoang cach lon nhat tu s den u chua
    vector<bool> visited(n+1, false);
   

    priority_queue<pair<int , int> , vector<pair<int , int>> , greater<pair<int,int>>> Q;
    Q.push({s , 0});
    while(!Q.empty()){
        pair<int ,int > top = Q.top() ; Q.pop();
        int u = top.first;
        int kc = top.second;
        if (visited[u]) continue;
        visited[u] = true;
        for (auto x : adj[u]){
            int v = x.first;
            int w = x.second;
            if (path[v] > path[u] + w){
                path[v] = path[u] + w;
                Q.push({v , path[v]});
            }
        }
    }
}
int main(){
    return 0;
}