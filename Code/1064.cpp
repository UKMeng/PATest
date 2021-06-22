#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;

int findMid(int l, int r){
    if(l > r) return -1;
    int length = r - l;
    if(length == 0) return l;
    else{
        int i = 1;
        for(; i < length; i++){
            if(length <= 2 * (pow(2, i)-1)) break;
        }
        if(length >= pow(2, i-1) - 1 + pow(2, i) - 1) return l + pow(2, i) - 1;
        else return l + length - pow(2, i-1) + 1;
    }
}

int main(){
    int n;
    scanf("%d", &n);
    vector<int> num(n);
    vector<int> ans;
    for(int i = 0; i < n; i++) scanf("%d", &num[i]);
    sort(num.begin(), num.end());
    queue<pair<int, int>> q;
    q.push({0, n-1});
    while(!q.empty()){
        pair<int, int> tmp = q.front();
        q.pop();
        int mid = findMid(tmp.first, tmp.second);
        if(mid != -1){
            ans.push_back(num[mid]);
            q.push({tmp.first, mid-1});
            q.push({mid+1, tmp.second});
        }        
    }
    for(int i = 0; i < n; i++){
        if(i != 0) cout << " " << ans[i];
        else cout << ans[i];
    }
    return 0;
}