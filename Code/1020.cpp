#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> in(n), post(n);
    unordered_map<int, int> mapp;
    for(int i = 0; i < n; i++){
        cin >> post[i];
    }
    for(int i = 0; i < n; i++){
        cin >> in[i];
        mapp[in[i]] = i;
    }
    vector<int> temp = {0, n-1, 0, n-1}; // il, ir, pl, pr
    queue<vector<int>> q;
    q.push(temp);
    vector<int> ans;
    while(!q.empty()){
        vector<int> t = q.front();
        q.pop();
        if(t[0] > t[1]) continue;
        ans.push_back(post[t[3]]);
        int pos = mapp[post[t[3]]];
        int leftL = pos - t[0];
        vector<int> left = {t[0], pos-1, t[2], t[2]+leftL-1};
        vector<int> right = {pos+1, t[1], t[2]+leftL, t[3]-1};
        q.push(left);
        q.push(right);
    }
    for(int i = 0; i < n; i++){
        if(i != 0) cout << " " << ans[i];
        else cout << ans[i];
    }
    return 0;
}