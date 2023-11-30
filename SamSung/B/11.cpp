// duong di hamilton
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void addEdge(vector<vector<int>> &adj, int u, int v) {
    adj[u][v] = 1;
}

// Kiểm tra xem việc thêm đỉnh v vào đường đi path ở vị trí pos có an toàn hay không.
// Đảm bảo rằng có cạnh từ đỉnh trước đến đỉnh mới và đỉnh mới chưa xuất hiện trong đường đi.
bool isSafe(int v, vector<int> &path, vector<vector<int>> &adj, int pos) {
    if (adj[path[pos - 1]][v] == 0)
        return false;

    for (int i = 0; i < pos; i++)
        if (path[i] == v)
            return false;

    return true;
}

// Sử dụng phương pháp quay lui để thử tất cả các đỉnh có thể kết nối với đỉnh hiện tại , trừ đỉnh ban đầu
// Nếu một đỉnh có thể được thêm vào đường đi, thì tiếp tục đệ quy để thử đỉnh tiếp theo.
// Nếu tất cả các đỉnh đã được thử và không có đường đi Hamilton, trả về false.
bool hamiltonianCycleUtil(vector<int> &path, vector<vector<int>> &adj, int pos) {
    // kiểm tra xem đỉnh cuối cùng có đường đi đến đỉnh đầu tiên không
    if (pos == path.size()) {
        if (adj[path[pos - 1]][path[0]] == 1)
            return true;
        else
            return false;
    }

    // v đại diện cho đỉnh chúng ta xem xét để thêm vào đường đi hamilton
    // pos vị trí hiện tại trong đường đi trong đường đi hamilton
    for (int v = 1; v < path.size(); v++) {
        if (isSafe(v, path, adj, pos)) {
            path[pos] = v;

            if (hamiltonianCycleUtil(path, adj, pos + 1))
                return true;

            path[pos] = -1;
        }
    }

    return false;
}

bool hamiltonianCycle(vector<vector<int>> &adj) {
    vector<int> path(adj.size(), -1);
    path[0] = 0;

    if (!hamiltonianCycleUtil(path, adj, 1)) {
        cout << "Khong ton tai duong di Hamilton." << endl;
        return false;
    }

    cout << "Duong di Hamilton: ";
    for (int i : path)
        cout << i << " ";
    cout << path[0] << endl;

    return true;
}

int main() {
    int vertices = 5;
    vector<vector<int>> adj(vertices, vector<int>(vertices, 0));

    addEdge(adj, 0, 1);
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 0);
    addEdge(adj, 0, 4);
    addEdge(adj, 4, 1);
    // addEdge(adj, 4, 0);

    hamiltonianCycle(adj);

    return 0;
}

