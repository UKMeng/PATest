#include <vector>
#include <iostream>
#include <unordered_map>
#include <cstring>
#include <algorithm>
#include <unordered_set>
using namespace std;

unordered_map<int, bool> m;
unordered_map<int, unordered_set<int>> v;

bool test(){
    int n;
    scanf("%d", &n);
    vector<int> num;
    for(int i = 0; i < n; i++){
        int a;
        scanf("%d", &a);
        if(m[a]) num.push_back(a);
    }
    int m = num.size();
    if(m == 0) return true;
    for(int i = 0; i < m - 1; i++){
        unordered_set<int> temp = v[num[i]];
        for(int j = i+1; j < m; j++){
            if(temp.find(num[j]) != temp.end()){
                return false;
            }   
        }
    }
    return true;
}

int main(){
    int n, k;
    scanf("%d%d", &n, &k);
    for(int i = 0; i < n; i++){
        int a;
        int b;
        scanf("%d%d", &a, &b);
        v[a].insert(b);
        v[b].insert(a);
        m[a] = true;
        m[b] = true;
    }
    for(int i = 0; i < k; i++){
        bool flag = test();
        if(flag) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}