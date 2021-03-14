#include <iostream>
#include <vector>
using namespace std;

vector<int> num;
// DFS

vector<vector<int>> path;
vector<int> temp;
void DFS(int start, int n){
    temp.push_back(num[start]);
    int flag = 0;
    if(start * 2 + 2 < n) {
        DFS(start*2+2, n);
    }
    if(start * 2 + 1< n) {
        DFS(start*2+1, n);
        flag = 1;
    }
    if(flag == 0) {
        path.push_back(temp);
        temp.pop_back();
        return;
    }
    temp.pop_back();
    return;    
}


int main(){
    // input
    int n;
    cin >> n;
    num.resize(n);
    for(int i = 0; i < n; i++) {cin >> num[i];}

    // DFS
    DFS(0, n);

    // print path and test
    bool flag1 = true, flag2 = true;
    for(int i = 0; i < path.size(); i++){
        for(int j = 0; j < path[i].size(); j++){
            if(j != 0) {
                cout << " " << path[i][j];
                if(path[i][j] > path[i][j-1]) flag2 = false;
                if(path[i][j] < path[i][j-1]) flag1 = false;
            }
            else cout << path[i][j];
        }
        cout << endl;
    }
    if(flag1) {
        cout << "Min Heap" << endl;
    } else if(flag2) {
        cout << "Max Heap" << endl;
    } else {cout << "Not Heap" << endl;}
    return 0;
}