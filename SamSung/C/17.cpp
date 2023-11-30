#include <bits/stdc++.h>
using namespace std;
int n , m , st, en , tmp;
set<pair<int,int>> res[1001];
int parent[1001];
bool visited[1001];

// check xem co tao thanh chu trinh euler khong
bool isCycle(int u){
    queue<int> qe;
    qe.push(u);
    visited[u] = true;
    while(!qe.empty()){
        int v = qe.front();
        qe.pop();
        for (auto x : res[u]){
            int secnode = x.first;
            // int weight = x.second;
            if (!visited[secnode]){
                qe.push(secnode);
                parent[secnode] = v;
            }else{
                if (secnode != parent[v]){
                    st = v;
                    en =secnode;
                    tmp = secnode;
                    return true;
                }
            }
        }
    }
    return false;
}

void solve(){
    cin >> n >> m;
    for (int i = 0 ; i< m ; i++){
        int u , v , w; cin >> u >> v >> w;
        res[u].insert({v,w});
        res[v].insert({u,w});
        memset(visited , false , sizeof(visited));
        memset(parent  , -1 , sizeof(parent));
        if(isCycle(u)){
            int maxWeight = -1e9;
            int maxIdx;
            int maxIdy;
            // tim cap canh co trong so lon nhat
            while(st != en){
                for (auto x : res[st]){
                    if (x.first == tmp && x.second > maxWeight){
                        maxWeight = x.second;
                        maxIdx = st;
                        maxIdy = x.first;
                    }
                }
                tmp =st;
                st = parent[st];
            }
            for (auto x : res[st]){
                    if (x.first == tmp && x.second > maxWeight){
                        maxWeight = x.second;
                        maxIdx = st;
                        maxIdy = x.first;
                    }
            }
            // xoa cap canh co trong so lon nhat
            res[maxIdx].erase({maxIdy , maxWeight});
            res[maxIdy].erase({maxIdy , maxWeight});
            cout << maxWeight <<" ";
        }

    }
}
int main(){
    solve();
    return 0;
}