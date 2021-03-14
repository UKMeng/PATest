#include <iostream>
#include <vector>
using namespace std;
int min_flag = 1;
int max_flag = 1;
int n;
vector<vector<int> > ans;
vector<int> num;
vector<int> path;
void compare(int a, int b){
    if (a > b) min_flag = 0;
    else if(a < b) max_flag = 0;
}

void dfs(int index){
    if(index * 2 + 2 < n) {
        int next_index = index * 2 + 2;
        path.push_back(num[next_index]);
        compare(num[index], num[next_index]);
        dfs(next_index);
        //path.pop_back();
    }
    if(index * 2 + 1 < n) {
        int next_index = index * 2 + 1;
        path.push_back(num[next_index]);
        compare(num[index], num[next_index]);
        dfs(next_index);
        path.pop_back();
    } else {
        ans.push_back(path);
        path.pop_back();
    }
}

int main(){
    cin >> n;
    num.resize(n);
    for(int i = 0; i < n; i++){
        cin >> num[i];
    }
    path.push_back(num[0]);
    dfs(0);
    for(int i = 0; i < ans.size(); i++){
        for(int j = 0; j < ans[i].size(); j++){
            if(j != 0) cout << " " << ans[i][j];
            else cout << ans[i][j];
        }
        cout << endl;
    }
    if(min_flag == 1) cout << "Min Heap" << endl;
    else if(max_flag == 1) cout << "Max Heap" << endl;
    else cout << "Not Heap" << endl;
    return 0;
}