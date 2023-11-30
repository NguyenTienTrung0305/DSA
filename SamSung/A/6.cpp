#include <bits/stdc++.h>
using namespace std;

bool is_edge_connected(vector<vector<int>> &G)
{
    // mảng check xem đỉnh đã được thăm chưa
    vector<bool> visited(G.size(), false);
    for (int u = 0; u < G.size(); u++)
    {
        if (!visited[u])
        {
            DFS(G, u, visited);
        }
    }

    // Kiểm tra xem có cầu nào không
    for (int u = 0; u < G.size(); u++)
    {
        for (int v : G[u])
        {
            if (visited[u] != visited[v])
            {
                return false;
            }
        }
    }

    return true;
}

void DFS(vector<vector<int>> &G, int u, vector<bool> &visited)
{
    // Đánh dấu đỉnh u là đã duyệt
    visited[u] = true;

    // Duyệt các đỉnh kề với u
    for (int v : G[u])
    {
        if (!visited[v])
        {
            DFS(G, v, visited);
        }
    }
}

int main()
{
    return 0;
}