#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n;
    float demand;
    cin >> n >> demand;
    vector<float> inventory;
    vector<pair<float, float> > price;
    for(int i = 0; i < n; i++){
        float temp;
        cin >> temp;
        inventory.push_back(temp);
    }
    for(int i = 0; i < n; i++){
        float temp;
        cin >> temp;
        price.push_back({inventory[i], temp/inventory[i]});
    }
    sort(price.begin(), price.end(), [](pair<float, float> a, pair<float, float> b){
        if(a.second != b.second) return a.second > b.second;
        else return a.first > b.first;
    });
    int cnt = 0;
    float profit = 0.0;
    while(demand != 0 && cnt < n){
        if(price[cnt].first <= demand){
            profit += price[cnt].first * price[cnt].second;
            demand -= price[cnt].first;
        } else{
            profit += demand * price[cnt].second;
            demand = 0;
        }
        cnt++;
    }
    printf("%.2f", profit);
    return 0;
}