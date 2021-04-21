#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;

void get_num(unordered_map<int, float> &a, vector<int> &va){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int ex;
        float co;
        cin >> ex >> co;
        a[ex] = co;
        va.push_back(ex);
    }
}

int main(){
    unordered_map<int, float> a, b, ans;
    vector<int> va, vb, vans;
    unordered_set<int> exSum;
    get_num(a, va);
    get_num(b, vb);
    for(int i = 0; i < va.size(); i++){
        for(int j = 0; j < vb.size(); j++){
            int ex = va[i] + vb[j];
            exSum.insert(ex);
            float co = a[va[i]] * b[vb[j]];
            ans[ex] += co;
        }
    }
    for(auto it = exSum.begin(); it != exSum.end(); it++){
        if(ans[*it] != 0) vans.push_back(*it);
    }
    printf("%d", vans.size());
    sort(vans.begin(), vans.end(), greater<int>());
    for(int i = 0; i < vans.size(); i++){
        printf(" %d %.1f", vans[i], ans[vans[i]]);
    }
    return 0;
}