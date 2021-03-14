#include <iostream>
#include <vector>
#include <unordered_map>
#include <cstring>
#include <set>
#include <algorithm>
using namespace std;

unordered_map<int, bool> rea;
unordered_map<int, vector<set<int>>> equation;
vector<set<int>> ans, final_ans;
vector<int> query;
int k;

void DFS(int index){
    if(final_ans.size() != 0){
        return;
    }
    /*
    if(index == k){
        if(final_ans.size() == 0){
            final_ans = ans;
        } else{
            for(int i = 0; i < final_ans.size(); i++){
                if(final_ans[i] > ans[i]){
                    final_ans = ans;
                }
            }
        }
        return;
    }
    */
    if(index == k){
        final_ans = ans;
        return;
    }
    int elem = query[index];
    vector<set<int>> v = equation[elem];
    for(int i = 0; i < v.size(); i++){
        set<int> s = v[i];
        set<int> out;
        bool flag = true;
        for(int num: s){
            if(rea[num]){
                rea[num] = false;
                out.insert(num);
            } else{
                flag = false;
                break;
            }
        }
        if(flag){
            ans.push_back(s);
            DFS(index + 1);
            ans.pop_back();
        }
        for(int num: out){
            rea[num] = true;
        }
    }
}

bool cmp(set<int> a, set<int> b){
    return a < b;
}

int main(){
    // input
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        rea[temp] = true;
    }
    cin >> k;
    query.resize(k);
    for(int i = 0; i < k; i++){
        cin >> query[i];
        set<int> tempset;
        tempset.insert(query[i]);
        equation[query[i]].push_back(tempset);
    }
    int m;
    cin >> m;
    string space;
    for(int i = 0; i < m; i++){        
        set<int> tempset;
        bool flag = true;
        for(int j = 0; j < 100; j++){
            string temp;
            cin >> temp;
            if(temp == "->") break;
            if(temp != "+"){
                if(!rea[stoi(temp)]){
                    flag = false;
                }
                tempset.insert(stoi(temp));
            }
        }
        int res;
        cin >> res;
        if(flag){            
            equation[res].push_back(tempset);
        }
        
    }
    for(int i = 0; i < k; i++){
        sort(equation[query[i]].begin(), equation[query[i]].end(), cmp);
    }
    DFS(0);

    for(int i = 0; i < final_ans.size(); i++){
        set<int> tempset = final_ans[i];
        int count = 0;
        for(int num: tempset){
            if(count != 0) printf(" + %02d", num);
            else printf("%02d", num);
            count++;
        }
        printf(" -> %02d\n", query[i]);
    }
    return 0;
}