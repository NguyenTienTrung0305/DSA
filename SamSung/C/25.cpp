#include <bits/stdc++.h>

using namespace std;

// Định nghĩa một cạnh của đồ thị
struct Edge {
    int u, v, weight;
    Edge(int u, int v, int weight) : u(u), v(v), weight(weight) {}
};

// Định nghĩa toán tử so sánh để sử dụng trong heap
struct CompareEdges {
    bool operator()(const Edge& e1, const Edge& e2) {
        return e1.weight > e2.weight;
    }
};

// Hàm thực hiện thuật toán Prim với kiểm soát bộ nhớ
vector<Edge> prim(vector<vector<pair<int, int>>>& graph, int V, int memory_limit) {
    // Chọn một đỉnh bắt đầu
    int start_vertex = 0;

    // Khởi tạo tập cạnh và cây bao trùm
    priority_queue<Edge, vector<Edge>, CompareEdges> edges;
    vector<Edge> mst_edges;

    // Khởi tạo tập đỉnh đã thăm
    set<int> visited;
    visited.insert(start_vertex);

    // Thêm các cạnh của đỉnh bắt đầu vào heap
    for (auto neighbor : graph[start_vertex]) {
        int v = neighbor.first;
        int weight = neighbor.second;
        edges.push(Edge(start_vertex, v, weight));
    }

    while (mst_edges.size() < V - 1) {
        // Chọn cạnh thấp nhất từ heap
        Edge current_edge = edges.top();
        edges.pop();

        int u = current_edge.u;
        int v = current_edge.v;

        // Kiểm tra bộ nhớ
        if (mst_edges.size() == memory_limit) {
            // Loại bỏ cạnh thấp nhất đã chọn để giảm bộ nhớ
            mst_edges.erase(mst_edges.begin());
        }

        // Thêm cạnh vào cây bao trùm
        mst_edges.push_back(current_edge);

        // Thêm đỉnh mới vào tập đỉnh đã thăm
        visited.insert(v);

        // Thêm các cạnh của đỉnh mới vào heap
        for (auto neighbor : graph[v]) {
            int next_vertex = neighbor.first;
            int weight = neighbor.second;

            if (visited.find(next_vertex) == visited.end()) {
                edges.push(Edge(v, next_vertex, weight));
            }
        }
    }

    return mst_edges;
}

int main() {
    int V = 6;
    int memory_limit = 5;

    vector<vector<pair<int, int>>> graph(V);

    graph[0].push_back({1, 2});
    graph[0].push_back({2, 3});
    graph[1].push_back({0, 2});
    graph[1].push_back({2, 4});
    graph[2].push_back({0, 3});
    graph[2].push_back({1, 4});
    graph[2].push_back({3, 5});
    graph[3].push_back({2, 5});
    graph[4].push_back({1, 4});
    graph[5].push_back({2, 5});

    vector<Edge> result = prim(graph, V, memory_limit);
    
    cout << "Minimum Spanning Tree Edges:" << endl;
    for (const Edge& edge : result) {
        cout << edge.u << " - " << edge.v << " : " << edge.weight << endl;
    }

    return 0;
}