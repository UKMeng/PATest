#include <iostream>
#include <vector>
using namespace std;
vector<int> ans;
vector<int> a;
int min_flag, max_flag, n;

void dfs(int index){
    if(index * 2 + 1 >= n){
        ans.push_back(a[index]);
        return;
    }
    if(index * 2 + 1 < n){
        if(a[index] < a[index * 2 + 1]) max_flag = 0;
        if(a[index] > a[index * 2 + 1]) min_flag = 0;
        dfs(index * 2 + 1);
    }
    if(index * 2 + 2 < n){
        if(a[index] < a[index * 2 + 2]) max_flag = 0;
        if(a[index] > a[index * 2 + 2]) min_flag = 0;
        dfs(index * 2 + 2);
    }
    ans.push_back(a[index]);
}

int main(){
    int query;
    cin >> query >> n;
    for(int i = 0; i < query; i++){
        a.clear();
        for(int j = 0; j < n; j++){
            int temp;
            cin >> temp;
            a.push_back(temp);
        }
        min_flag = 1;
        max_flag = 1;
        ans.clear();
        dfs(0);
        if(min_flag == 1) cout << "Min Heap" << endl;
        else if(max_flag == 1) cout << "Max Heap" << endl;
        else cout << "Not Heap" << endl;
        for(int j = 0; j < n; j++){
            if(j != 0) cout << " " << ans[j];
            else cout << ans[j];
        }
        cout << endl;
    }
    return 0;
}