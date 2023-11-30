// Cho một đồ thị có trọng số G và một tập cạnh S của đồ thị (không chứa chu trình). Hãy
// mô tả thuật toán tìm cây bao trùm min của G có chứa tất cả các cạnh trong tập S
#include <bits/stdc++.h>
using namespace std;

int n , m , sizeS;
int parent[10005]; int sz[10005];

struct vertex{
    int u , v ,w;
};

vector<vertex> res; // do thi co trong so
vector<vertex> mst; // do thi rong
set<int> s[10005];

void init(){
    cin >> n >> m >> sizeS;
    for (int i = 0 ; i < m ; i++){
        int u , v, w; cin >> u >> v >> w;
        vertex x{u,v,w};
        res.push_back(x);
    }
    
    for (int i = 0 ; i < sizeS ; i++){
        int a , b; cin >> a >> b;
        s[a].insert(b);
        s[b].insert(a);
    }
}

void makeSet(){
    for (int i = 1 ; i<= n ; i++){
        parent[i] = i;
        sz[i] = 1;
    }
}

int find(int u){
    if ( u == parent[u]) return u;
    else{
        return parent[u] = find(parent[u]);
    }
}

bool unionSet(int a , int b){
    a = find(a);
    b = find(b);
    if (a == b){
        return false;
    }else{
        if (sz[a] < sz[b]){
            swap(a,b);
        }
        parent[b] = a;
        sz[a] += sz[b];
    }
    return true;
}

bool cmp(vertex x , vertex y){
    return x.w < y.w;
}

bool solve(){
    // neu tap canh co nhieu canh hon so dinh cua do thi thi do thi khong the chua het duoc
    if (sizeS > n){
        return false;
    }
    queue<vertex> q;
    sort(res.begin() , res.end() , cmp);
    for (int i = 0; i < m ; i++){
        if (mst.size() == n -1) break;
        vertex e = res[i];
        if (s[e.u].count(e.v)){ // neu co cap canh u,v trong s
            if (unionSet(e.u , e.v)){
                mst.push_back(e);
            }
        }else{
            q.push(e);
        }
    }
    // lay ra cac cap canh trong queue , cac canh da duoc sap xep theo thu tu tang dan trong so
    while(!q.empty()){
        if (mst.size() == n-1) break;
        auto edge = q.front();
        q.pop();
        if (unionSet(edge.u , edge.v)){
            mst.push_back(edge);
        }
    }
    

    return true;
}


int main(){
    init();
    makeSet();
    if (solve()){
        for (int i = 0 ; i < mst.size() ; i++){
            vertex e = mst[i];
            cout << e.u << " "<< e.v << " "<<e.w <<endl;
        }
    }else{
        cout << "not exsits";
    }
    return 0;

    /**
    5 6 2
    1 2 6
    1 3 2
    2 3 3
    2 4 4
    3 4 1
    3 5 2
    1 2
    3 5


    output 
    3 5 2
    1 2 6
    3 4 1
    1 3 2
    */
}