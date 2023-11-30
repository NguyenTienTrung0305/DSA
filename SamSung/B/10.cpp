// tim so thanh phan lien thong manh , O(m+n)
#include <bits/stdc++.h>
using namespace std;
int n , m ;
int num[1001] ; // num[u] thứ tự duyệt đến đỉnh u , vừa là biến check xem đã đỉnh u đã được duyệt đến hay chưa
int low[1001]; // low[u] là num nhỏ nhất trong tập những đỉnh mà đỉnh u có thể đi đến vd 1->2 , 2->3 , 3->1 => low[3] = 1 , low[2] = 1
int cnt = 0 ;
int connected[1001] ; /* Kiểm tra đỉnh v có còn được "kết nối" trong đồ thị hay không Nếu phát hiện ra một thành phần liên thông mạnh,
                        và một đỉnh v có trong thành phần liên thông mạnh đó, thì ta loại đỉnh v này ra khỏi đồ thị bằng câu lệnh
                        connect[v] = 0, điều này là quan trọng vì để tránh gây ảnh hưởng đến việc nén mảng low[] của những đỉnh khác
                        vẫn còn nằm trong đồ thị.
*/
int numSCC = 0; // bien luu so thanh phan lien thong manh
vector<int> a[1001] , S; // S dùng khi phát hiện 1 thành phần liên thông , nhiệm vụ của nó là cho tất cả các connected[u] trong thành phần
                        // liên thông bằng 0 => làm cho các đỉnh khác không kết nối với các đỉnh này nữa

void dfs(int u){
    low[u] = num[u] = cnt++;
    S.push_back(u);
    connected[u] = 1;
    for ( auto v : a[u]){
        if (num[v] == -1) dfs(v);
        if (connected[v]) low[u] = min(low[u] , low[v]);
    }
    if (num[u] == low[u]){ // tim duoc 1 thanh phan lien thong
        ++numSCC;
        while(true){ // xoa cac dinh cua thanh phan lien thong manh ra khoi do thi
            int x = S.back() ; S.pop_back();
            connected[x] = 0;
            if ( u == x){
                break;
            }
        }
    }
}
int main(){
    cin >> n >> m;
    for (int i = 0 ; i < m ; i++){
        int u , v; cin >> u >> v;
        a[u].push_back(v);
    }

    memset(num , -1 , sizeof(num));
    memset(low , 0 , sizeof(low));
    memset(connected , 0 , sizeof(connected));
    for ( int i = 1 ;i <= n ; i++){
        if (num[i] == -1) dfs(i);
    }
    cout << numSCC;
    return 0;
}
