// Cho một ma trận NxN gồm các số nguyên dương, hãy tìm đường đi ngắn nhất từ ô (0,0)
// đến ô (N-1, N-1), trong đó độ dài đường đi là tổng các số nguyên trên đường đi.
// Hãy làm lại bài toán với giả thiết bổ sung là bạn chỉ có thể đi sang phải hoặc đi xuống.
#include <bits/stdc++.h>
using namespace std;
int n;
int arr[1001][1001];
void init(){
    cin >> n;
    for (int i = 0 ; i < n ;i++){
        for (int j = 0 ; j < n ; j++){
            cin >> arr[i][j];
        }
    }
}

int solve(){
    for (int i = 0; i < n ; i++){
        for (int j = 0 ; j < n ; j++){
            if (i == 0 && j != 0){
                arr[i][j] += arr[i][j-1];
            }
            if ( j == 0 && i != 0){
                arr[i][j] += arr[i-1][j];
            }
            if ( i-1 >= 0 && j -1 >= 0){
                arr[i][j] += min(arr[i-1][j] , arr[i][j-1]);
            }
        }
    }
    return arr[n-1][n-1];
}

int main(){
    init();
    cout << solve();
    return 0;
}
