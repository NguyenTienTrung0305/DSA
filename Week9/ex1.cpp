#include <bits/stdc++.h>
using namespace std;

struct Items{
    int costItems;
    int weightItems;
};

bool cmp(Items i1 , Items i2){
    return ((i1.costItems*1.0)/i1.weightItems) > ((i2.costItems*1.0)/i2.weightItems);
}

int main(){
    int n; cin >> n;
    vector<Items> items;
    for (int i = 0 ; i < n ; i++){
        int costItems , weightItems;
        cin >> costItems >> weightItems;
        Items item{costItems , weightItems};
        items.push_back(item);
    }

    sort(items.begin() , items.end() , cmp);
    int weightBag; cin >> weightBag;

    int index = 0;
    int totalCost = 0;
    while(weightBag > 0){
        int cost = items[index].costItems;
        int weight = items[index].weightItems;

        if (weightBag < weight) break;

        int coefficient = weightBag / weight;

        totalCost += cost * coefficient;
        weightBag -= weight * coefficient;
        ++index;
    }

    cout << totalCost;

}