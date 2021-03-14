#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for(int i = 0; i < n; i++) cin >> nums[i];
    vector<vector<int> > output;
    while(nums.size() != 0){
        vector<int> next;
        multiset<int> ext;
        vector<int> turn;
        int now;
        int flag = 0;
        if(k >= nums.size()){
            output.push_back(nums);
            break;
        }
        for(int i = 0; i < k; i++) ext.insert(nums[i]);
        for(int i = k; i < nums.size(); i++){
            if(flag == 0){
                now = *ext.begin();
                ext.erase(ext.begin());
                flag = 1;
                turn.push_back(now);
            }
            if(now > nums[i]){
                next.push_back(nums[i]);
            } else if(now == nums[i]){
                turn.push_back(now);
            } else{
                ext.insert(nums[i]);
                flag = 0;
            }
        }
        if(ext.size() != 0){
            for(auto it = ext.begin(); it != ext.end(); it++){
                turn.push_back(*it);
            }
        }
        output.push_back(turn);
        nums = next;
    }
    for(int i = 0; i < output.size(); i++){
        for(int j = 0; j < output[i].size(); j++){
            if(j == 0) cout << output[i][j];
            else cout << " " << output[i][j];
        }
        cout << endl;
    }
    return 0;
}