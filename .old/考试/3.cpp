#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <cstring>
using namespace std;
void down_ad(vector<int>& nums, int low, int high){
    int i = low, j = i * 2 + 1;
    while(j <= high){
        if(j+1 <= high && nums[j+1] > nums[j]) j = j+1;
        if(nums[i] > nums[j]) return;
        swap(nums[i], nums[j]);
        i = j;
        j = i * 2 + 1;
    }
}

void build(vector<int>& nums, int len){
    for(int i = len / 2; i >= 0; i--){
        down_ad(nums, i, len);
    }
}

void heapsort(vector<int>& nums){
    int len = nums.size() -1;
    build(nums, len);
    /*
    for(int i = len; i >= 1; i--){
        swap(nums[len], nums[0]);
        len--;
        down_ad(nums, 0, len);
    }
    */
}
unordered_map<int, int> pos;
unordered_map<int, bool> exist;
int main(){
    int n, m;
    cin >> n >> m;
    vector<int> nums;
    for(int i = 0; i < n; i++){
        int t;
        cin >> t;
        nums.push_back(t);
        heapsort(nums);
        exist[t] = true;
    }
    //heapsort(nums);
    for(int i = 0; i < n; i++){
        //cout << nums[i] << " ";
        pos[nums[i]] = i;
    }
    getchar();
    string ans;
    for(int i = 0; i < m; i++){
        string s;
        getline(cin, s);
        vector<string> t;
        int count = 0;
        for(int j = 0; j < s.size(); j++){
            //cout << s[j] << endl;
            if(s[j] == ' '){
                //cout << s.substr(j-count, count) << endl;
                t.push_back(s.substr(j-count, count));
                count = 0;
            } else{
                count++;
            }
        }
        t.push_back(s.substr(s.size()-count, count));
        if(t[3] == "root"){
            int test = stoi(t[0]);
            if(!exist[test]){
                ans.push_back('0');
            } else{
                if(pos[test] == 0){
                    ans.push_back('1');
                } else{
                    ans.push_back('0');
                }
            }
        } else if(t[4] == "siblings"){
            int a = stoi(t[0]);
            int b = stoi(t[2]);
            if(!exist[a] || !exist[b]){
                ans.push_back('0');
                continue;
            }
            int t1 = pos[a];
            int t2 = pos[b];
            if(t1 > t2) swap(t1, t2);
            if(t1 % 2 != 0 && t2 - t1 == 1) {
                ans.push_back('1');
            } else{
                ans.push_back('0');
            }
        } else if(t[3] == "parent"){
            int a = stoi(t[0]);
            int b = stoi(t[5]);
            if(!exist[a] || !exist[b]){
                ans.push_back('0');
                continue;
            }
            int t1 = pos[a];
            int t2 = pos[b];
            if(t1 * 2 + 1 == t2 || t1 * 2 + 2 == t2){
                ans.push_back('1');
            } else{
                ans.push_back('0');
            }
        } else if(t[3] == "left"){
            int a = stoi(t[0]);
            int b = stoi(t[6]);
            if(!exist[a] || !exist[b]){
                ans.push_back('0');
                continue;
            }
            int t1 = pos[a];
            int t2 = pos[b];
            if(t2 * 2 + 1 == t1){
                ans.push_back('1');
            } else{
                ans.push_back('0');
            }
        } else if(t[3] == "right"){
            int a = stoi(t[0]);
            int b = stoi(t[6]);
            if(!exist[a] || !exist[b]){
                ans.push_back('0');
                continue;
            }
            int t1 = pos[a];
            int t2 = pos[b];
            if(t2 * 2 + 2 == t1){
                ans.push_back('1');
            } else{
                ans.push_back('0');
            }
        }
    }
    cout << ans << endl;
    return 0;
}