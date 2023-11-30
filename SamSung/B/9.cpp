// tim chu trinh euler tren do thi co huong
#include <bits/stdc++.h>
using namespace std;

int degree[1001]; // tim bac cua dinh
int n , m;

set<int> adj[1001]; // dung set lưu danh sách để thuận lời cho việc xóa các cạnh

void init(){
    memset(degree , 0 , sizeof(degree));
    cin >> n >> m;
    for ( int i = 0; i < m ; i++){
        int x , y ; cin >> x >> y;
        adj[x].insert(y);
        degree[x]--;
        degree[y]++;
    }
}

bool checkdegee(){
    for ( auto x : degree){
        if (x != 0) return false;
    }
    return true;
}

void euler(int v){
    stack<int> st;
    vector<int> EC; // luu chu trinh euler
    st.push(v);
    while (!st.empty()){
        int x = st.top();
        if (adj[x].size() != 0 ){
            int y = *adj[x].begin(); // lay ra thang dau tien trong danh sach cua dinh x
            // push in stack
            st.push(y);
            // xóa cạnh x , y
            adj[x].erase(y);

        }else{
            st.pop();
            EC.push_back(x);
        }
    }
    reverse(EC.begin() , EC.end());
    for ( auto x : EC){
        cout << x <<" ";
    }
}

int main(){
    init();
    if (checkdegee()) euler(3);
    else cout <<"Not exsits euler cycle";
    return 0;
}