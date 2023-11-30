#include <bits/stdc++.h>
using namespace std;
int main(){
    int n ; cin >> n;
    int benefit[n+1];
    int weight[n+1];
    for (int i = 1 ; i <= n ; i++){
        cin >> benefit[i];
        cin >> weight[i];
    }
    int maxWeight ; cin >> maxWeight;

    int maxBenefit[n+1][maxWeight+1];

    // init
    for (int i = 0 ; i <= n ; i++){
        maxBenefit[i][0] = 0;
    }

    for (int i = 0 ; i <= maxWeight ; i++){
        maxBenefit[0][i] = 0;
    }

    // solve
    // gia su ta biet maxBenefit[i-1][L] : gia tri lon nhat mang di duoc voi i-1 do vat khi trong luong trong tui la L
    // muon biet co mang them duoc do vat i khi trong luong la L hay khong ? 
    // => ta xet maxBenefit[i-1][L-weight[i]] + benefit[i] (gia tri lon nhat mang di duoc voi i -1 do vat khi trong luong la L - weight[i] + gia tri cua do vat i) voi maxBenefit[i-1][L]
    for (int i = 1 ; i <= n ; i++){
        for (int L = 1 ; L <= maxWeight ; L++){
            maxBenefit[i][L] = maxBenefit[i-1][L];
            if ( L >= weight[i] && (maxBenefit[i-1][L-weight[i]] + benefit[i] > maxBenefit[i-1][L])){
                maxBenefit[i][L] = maxBenefit[i-1][L-weight[i]] + benefit[i];
            }
        }
    }

    cout << maxBenefit[n][maxWeight];
    return 0;
}