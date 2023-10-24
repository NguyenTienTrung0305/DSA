#include <bits/stdc++.h>
using namespace std;
int n , m;
struct graph{
    int u , v , w;
};

int parent[1001];
int sz[1001];

vector<graph> res;

void init(){
    cin  >> n >> m;
    for (int i = 1 ; i<= m ;i++){
        int u , v , w;
        cin >> u >> v >> w;
        res.push_back({u , v ,w});
    }
}

void makeGraph(){
    for (int i = 1 ; i <= n ; i++){
        sz[i] = 1;
        parent[i] = i;
    }
}

int findParent(int u){
    if (u == parent[u]) return u;
    else{
        return parent[u] = findParent(parent[u]);
    }
}

bool unionParent(int u , int v){
    u = findParent(u);
    v = findParent(v);
    if (u == v){
        return false;
    }else{
        if (sz[u] < sz[v]){
            swap(u ,v);
        }
        parent[v] = u;
        sz[u] += sz[v];
    }
    return true;
}


bool cmp(graph x , graph y){
    return x.w < y.w;
}

void solve(){
    // create chu trinh rong
    vector<graph> gp;
    sort(res.begin() , res.end() , cmp);
    int d = 0;
    for (int i = 0 ; i < m; i++){
        if (gp.size() == n -1) break;
        graph e = res[i];
        if (unionParent(e.u , e.v)){
            d+= e.w;
            gp.push_back(e);
        }
    }

    cout <<"Path:" <<d << endl;
    for (auto x : gp){
        cout << x.u << " "<< x.v <<" " << x.w <<endl;
    }

}
int main(){
    init();
    makeGraph();
    solve();
    return 0;
}