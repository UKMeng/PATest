#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main(){
    unordered_map<int, float> mapp;
    int count = 0;
    int high = -1;
    for(int i = 0; i < 2; i++){
        int n;
        cin >> n;
        for(int i = 0; i < n; i++){
            int k;
            float v;
            cin >> k >> v;
            if(i == 0 && high < k) high = k;
            mapp[k] += v;
        }
    }
    vector<pair<int, float>> ans;
    for(int i = high; i >= 0; i--){
        if(mapp[i] != 0.0){
            ans.push_back({i, mapp[i]});
        }
    }
    printf("%d", ans.size());
    for(int i = 0; i < ans.size(); i++){
        printf(" %d %.1f", ans[i].first, ans[i].second);
    }
    return 0;
}