// thu tu topo duy nhat
#include <bits/stdc++.h>
using namespace std;
int n , m;
bool visited[1001];
vector<int> topo;
int in[1001];
vector<vector<int>> res(1001);

void input(){
    cin >> n >> m;
    memset( visited , false , sizeof(visited));
    for ( int i = 0; i < m ; i++){
        int a , b ; cin >> a >> b;
            res[a].push_back(b);
            // tăng dần bán bậc vào
            in[b]++;
    }
}
void kahn(){
    queue<int> qe;
    for ( int i = 1 ; i <= n ;i++){
        if ( in[i] == 0){
            qe.push(i);
        }
    }
    while ( !qe.empty()){
        int u = qe.front();
        qe.pop();
        topo.push_back(u);
        int count = 0; // biến đếm xem tại 1 thời điểm có bao nhiêu đỉnh có bán bậc vào bằng 0 , count = 1 thì có 1 đường đi từ u , count  = 2 thì có 2 đường đi từ u
        for ( auto v : res[u]){
            // xóa bán bậc vào
            in[v]--;
            // nếu bán bậc vào bằng 0 thì đẩy nó vào hàng đợi
            if ( in[v] == 0){
                ++count;
                if (count > 1){
                    cout << "Khong co thu tu topo duy nhat";
                    return;
                }
                qe.push(v);
            }
        }
        count = 0;
    }
    for ( auto x: topo){
        cout << x << " ";
    }
}
int main(){
    input();
    kahn();
    return 0;
}