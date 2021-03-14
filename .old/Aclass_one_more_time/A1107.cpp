#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int father[1010];
int isRoot[1010];
int hobby[1010];

int find_father(int son){
    if(father[son] != son){
        father[son] = find_father(father[son]);
    }
    return father[son];
}

int main(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        father[i] = i;
    }
    for(int i = 1; i <= n; i++){
        int temp_num;
        scanf("%d: ", &temp_num);
        for(int j = 0; j < temp_num; j++){
            int temp;
            cin >> temp;
            if(hobby[temp] == 0) hobby[temp] = i;
            else{
                father[find_father(i)] = find_father(hobby[temp]);
            }
        }
    }
    for(int i = 1; i <= n; i++){
        isRoot[find_father(i)] += 1;
    }
    vector<int> ans;
    for(int i = 1; i <= n; i++){
        if(isRoot[i] != 0) ans.push_back(isRoot[i]);
    }
    sort(ans.begin(), ans.end());
    reverse(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for(int i = 0; i < ans.size(); i++){
        if(i != 0) cout << " " << ans[i];
        else cout << ans[i];
    }
    cout << endl;
    return 0;
}