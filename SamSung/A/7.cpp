#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> floodfill(vector<vector<int>> &image, int x, int y)
{
    // Khởi tạo
    bool visited[image.size()][10001];
    memset(visited , false , sizeof(visited));

    vector<pair<int , int>> colorSideBySide;

    // Thêm điểm ảnh bắt đầu vào hàng đợi
    queue<pair<int, int>> queue;
    queue.push({x, y});

    // Duyệt hàng đợi
    while (!queue.empty())
    {
        // Lấy điểm ảnh hiện tại ra khỏi hàng đợi
        int current_x = queue.front().first;
        int current_y = queue.front().second;
        colorSideBySide.push_back({current_x , current_y});
        queue.pop();

        // Nếu điểm ảnh đã được thăm dò thì bỏ qua
        if (visited[current_x][current_y])
        {
            continue;
        }

        // Đánh dấu điểm ảnh hiện tại là đã được thăm dò
        visited[current_x][current_y] = true;

        // Thêm các điểm ảnh kề nhau vào hàng đợi
        for (int dx = -1; dx <= 1; dx++)
        {
            for (int dy = -1; dy <= 1; dy++)
            {
                int new_x = current_x + dx;
                int new_y = current_y + dy;

                if (0 <= new_x && new_x < image.size() && 0 <= new_y && new_y < image[new_x].size() &&
                    image[current_x][current_y] == image[new_x][new_y] && !visited[new_x][new_y])
                {
                    queue.push({new_x, new_y});
                }
            }
        }
    }

    // Trả về các điểm ảnh kề nhau có cùng màu
    return colorSideBySide;
}

int main()
{
    return 0;
}