#include <bits/stdc++.h>

using namespace std;

const int INF = numeric_limits<int>::max();

typedef pair<int, int> pii;

// vector<vector<pii>> graph; // đồ thị có hướng có trọng số
set<pair<int,int>> graph[1001];
vector<int> dist; // khoảng cách tạm thời từ đỉnh s đến các đỉnh
vector<int> parent; // đỉnh cha của mỗi đỉnh trong đường đi ngắn nhất từ s đến t

int dijkstra(int start, int end) {
    priority_queue<pii> pq;
    pq.push(make_pair(0, start));
    dist[start] = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (u == end) break;

        for (auto v : graph[u]) {
            int weight = v.second;
            int alt = dist[u] + weight;
            if (alt < dist[v.first]) {
                dist[v.first] = alt;
                parent[v.first] = u;
                pq.push(make_pair(-dist[v.first], v.first));
            }
        }
    }
    return dist[end];
}

pair<int,int> findMaxDist(int start, int end) {
    int maxDist = -INF;
    int u = end;
    int edge1 , edge2;

    while (u != start) {
        int v = parent[u];
        int tmp = dist[u] - dist[v];
        fill(dist.begin() , dist.end() , INF);
        graph[v].erase({u,tmp}); // xoa canh dang xet
        int dis = dijkstra(start , end); // tinh khoang cach ngan nhat sau khi xoa canh dang xet
        if (dis == INF){
            continue;
        }
        if (dis > maxDist){
            maxDist = dis;
            edge1 = v;
            edge2 = u;
        }
        graph[v].insert({u,tmp}); // them lai canh do 
        u = v;
    }

    return make_pair(edge1,edge2);
}

int main() {
    int n, m, s, t;
    cin >> n >> m >> s >> t;

    dist.resize(n , INF);
    parent.resize(n, -1);

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].insert(make_pair(v, w));
    }

    dijkstra(s, t);

    pair<int,int> res = findMaxDist(s, t);

    cout << res.first <<" " << res.second << endl;

    return 0;
}