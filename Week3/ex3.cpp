#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int arr[n];
    int count =0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    if ( n < 3){
        cout << 0;
        return 0;
    }
    int total = arr[0] + arr[1] + arr[2];
    if (total == 0) ++count;
    for ( int i = 3 ; i < n ; i++){
        total = total + arr[i] - arr[i-3];
        if (total == 0) ++count;
    }
    cout << count;
    return 0;
}