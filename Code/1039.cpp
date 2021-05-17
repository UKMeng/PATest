#include <iostream>
#include <unordered_map>
#include <set>
using namespace std;
int main(){
    unordered_map<string, set<int>> mapp;
    int k, n;
    scanf("%d %d", &k, &n);
    while(n--){
        int id, m;
        scanf("%d %d", &id, &m);
        char tname[5];
        for(int i = 0; i < m; i++){
            scanf("%s", tname);         // 用cin超时
            string temp = tname;
            mapp[tname].insert(id);
        }
    }
    for(int i = 0; i < k; i++){
        string tname;
        cin >> tname;
        cout << tname << " " << mapp[tname].size();
        for(auto cid : mapp[tname]){
            cout << " " << cid;
        }
        cout << endl;
    }
    return 0;
}