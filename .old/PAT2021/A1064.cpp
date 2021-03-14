#include <queue>
#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<int> two(11);

int get_pos(int n){
    int left = 0, right = 0;
    for(int i = 0; i < 11; i++){
        // left
        if(n > two[i] + right) {
            left = two[i];
        } else if(n == two[i] + right){
            left = two[i];
            break;
        } else{
            left = n - right;
            break;
        }
        // right
        if(n > left + two[i]){
            right = two[i];
        } else {
            break;
        }
    }
    //cout << left << endl;
    return left;
}

int main(){
    int n;
    cin >> n;
    two[0] = 1;
    for(int i = 1; i < two.size(); i++) {
        two[i] = two[i-1] + pow(2, i);
    }
    vector<int> ans;
    vector<int> num(n);
    for(int i = 0; i < n; i++) {cin >> num[i];}
    sort(num.begin(), num.end());
    queue<vector<int>> q;
    q.push(num);
    while(!q.empty()){
        vector<int> temp = q.front();
        q.pop();
        if(temp.size() == 1) ans.push_back(temp[0]);
        else{
            int pos = get_pos(temp.size()-1);
            vector<int> left, right;
            ans.push_back(temp[pos]);
            for(int i = 0; i < pos; i++) left.push_back(temp[i]);
            q.push(left);
            if(pos+1 < temp.size()){
                for(int i = pos + 1; i < temp.size(); i++) right.push_back(temp[i]);
                q.push(right);
            }            
        }
    }
    for(int i = 0; i < n; i++){
        if(i != 0) cout << " " << ans[i];
        else cout << ans[i];
    }
    return 0;
}