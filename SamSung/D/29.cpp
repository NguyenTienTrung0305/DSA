#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9; 

typedef pair<double, double> pii; 

vector<int> adj[100005]; 
double dist[100005]; // khoảng cách từ đỉnh bắt đầu đến các đỉnh khác
pii coords[100005]; // tọa độ của các đỉnh trên mặt phẳng hình học Euclid

void dijkstra(int s) {
    priority_queue<pii, vector<pii>, greater<pii>> pq; 
    pq.push({0, s}); 
    dist[s] = 0; 

    while (!pq.empty()) {
        int u = pq.top().second; 
        pq.pop();

        for (auto v : adj[u]) { 
            double w = sqrt(pow(coords[v].second - coords[u].second, 2) + pow(coords[v].first - coords[u].first, 2)); // tính khoảng cách giữa hai điểm trên mặt phẳng hình học Euclid
            if (dist[v] > dist[u] + w) { // nếu có đường đi ngắn hơn
                dist[v] = dist[u] + w; // cập nhật khoảng cách tương ứng
                pq.push({dist[v], v}); // thêm đỉnh đó vào heap với khoảng cách mới
            }
        }
    }
}

int main() {
    int n, m, s, t;
    cin >> n >> m >> s >> t;

    for (int i = 1; i <= n; i++) {
        double x, y;
        cin >> x >> y;
        coords[i] = {x, y}; // lưu trữ tọa độ của các đỉnh vào mảng hai chiều
    }

    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    fill(dist, dist + n + 1, INF); // khởi tạo khoảng cách ban đầu bằng giá trị vô cùng
    dijkstra(s); // chạy thuật toán Dijkstra từ đỉnh bắt đầu

    cout << dist[t] << endl; // in ra khoảng cách từ đỉnh bắt đầu đến đỉnh đích

    return 0;
}