#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

unordered_map<int, int> mapp;
unordered_map<int, int> next_map;
int main(){
    int s1, s2, n;
    scanf("%d%d%d", &s1, &s2, &n);
    for(int i = 0; i < n; i++){
        int t1, val, t2;
        scanf("%d%d%d", &t1, &val, &t2);
        mapp[t1] = val;
        next_map[t1] = t2;
    }
    vector<int> l1, l2;
    while(s1 != -1){
        l1.push_back(s1);
        s1 = next_map[s1];
    }
    while(s2 != -1){
        l2.push_back(s2);
        s2 = next_map[s2];
    }
    if(l1.size() < l2.size()) swap(l1, l2);
    vector<int> ans;
    reverse(l2.begin(), l2.end());
    for(int i = 0; i < l1.size(); i++){
        ans.push_back(l1[i]);
        if(i % 2 == 1 && (i-1)/2 < l2.size()) ans.push_back(l2[(i-1)/2]);
    }
    for(int i = 0; i < ans.size(); i++){
        if(i != ans.size()-1){
            printf("%05d %d %05d\n", ans[i], mapp[ans[i]], ans[i+1]);
        } else{
            printf("%05d %d -1\n", ans[i], mapp[ans[i]]);
        }
    }
    return 0;
}