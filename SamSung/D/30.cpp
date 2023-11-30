// Cài thuật toán tìm đường đi dài nhất trong đồ thị có hướng phi chu trình có trọng số.
#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

typedef pair<int, int> pii;

vector<vector<pii>> graph; // đồ thị có hướng phi chu trình có trọng số
vector<int> dist; // khoảng cách tạm thời từ đỉnh xuất phát đến các đỉnh
vector<bool> visited; // đánh dấu các đỉnh đã được duyệt

void dijkstra(int start) {
    priority_queue<pii> pq; // vì là đồ thị không có chu trình, nên ta chỉ việc lấy ra thằng lớn nhất ở mỗi lần xét
    pq.push({0, start});
    dist[start] = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (visited[u]) continue;
        visited[u] = true;

        for (auto v : graph[u]) {
            int weight = v.second;
            int alt = dist[u] + weight;
            if (alt > dist[v.first]) {
                dist[v.first] = alt;
                pq.push({dist[v.first], v.first});
            }
        }
    }
}

int main() {
    int n, m, start;
    cin >> n >> m >> start;

    graph.resize(n + 1);
    dist.resize(n + 1, -INF);
    visited.resize(n + 1, false);

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
    }

    dijkstra(start);

    for (int i = 1; i <= n; i++) {
        if (dist[i] == -INF) {
            cout << "INF" << endl;
        } else {
            cout << dist[i] << endl;
        }
    }

    return 0;
}