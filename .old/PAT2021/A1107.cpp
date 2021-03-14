#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

vector<int> f, r;
unordered_map<int, int> hobby;

int find(int x){
    return f[x] == x ? x : f[x] = find(f[x]);
}

void union_set(int x, int y){
    int fx = find(x), fy = find(y);
    if(fx == fy) {
        return;
    }
    if(r[fx] < r[fy]){
        swap(fx, fy);
    }
    r[fx] += r[fy];
    f[fy] = fx;
}

int main(){
    int n;
    cin >> n;
    r.resize(n+1, 1);
    f.resize(n+1);
    for(int i = 1; i <= n; i++) f[i] = i;
    for(int i = 1; i <= n; i++){
        int m;
        scanf("%d:", &m);
        for(int j = 0; j < m; j++){
            int h;
            scanf("%d", &h);
            if(hobby[h] == 0) {
                hobby[h] = i;
            } else{
                union_set(hobby[h], i);
            }
        }
    }
    unordered_map<int, int> count;
    vector<int> ans;
    for(int i = 1; i <= n; i++){
        count[find(i)]++;  // 注意是find，因为不能保证所有的点都归到了father那里
    }
    for(int i = 1; i <= n; i++){
        if(count[i] != 0){
            ans.push_back(count[i]);
        }
    }
    sort(ans.begin(), ans.end(), greater<int>());
    printf("%d\n", ans.size());
    for(int i = 0; i < ans.size(); i++){
        if(i != 0) printf(" %d", ans[i]);
        else printf("%d", ans[i]);
    }
    printf("\n");
    return 0;
}