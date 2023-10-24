#include <bits/stdc++.h>
using namespace std;
int n , m;
vector<vector<int>> res(1001);
int in[1001];
vector<int> path;
void init(){
    cin >> n >> m;
    for (int i = 1 ; i<= m ; i++){
        int x , y;
        cin >> x >> y;
        res[x].push_back(y);
        in[y]++;
    }
}

void solve(){
    queue<int> qe;
    for ( int i = 1 ; i <= n ;i++){
        if ( in[i] == 0){
            qe.push(i);
        }
    }
    while ( !qe.empty()){
        int u = qe.front();
        qe.pop();
        path.push_back(u);
        for ( auto v : res[u]){
            // xóa bán bậc vào
            in[v]--;
            // nếu bán bậc vào bằng 0 thì đẩy nó vào hàng đợi
            if ( in[v] == 0){
                qe.push(v);
            }
        }
    }
    for ( auto x: path){
        cout << x << " ";
    }
}
int main(){
    init();
    solve();
    return 0;
}
// 8 10
// 2 3
// 1 3
// 1 8
// 7 8
// 7 4 
// 3 6
// 3 5
// 3 4
// 8 5
// 5 4