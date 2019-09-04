#include <iostream>
#include <vector>
using namespace std;
int flag, n;
vector<int> v, ans;
void show(vector<int> ans) {
    for(int i = 0; i < ans.size(); i++) {
        printf("%d%s", ans[i], i == ans.size() - 1 ? "\n" : " ");
    }
}
void dfs(int index) {
    ans.push_back(v[index]);
    if(index * 2 + 2 < n) {
        dfs(index * 2 + 2);
        if(flag == 1 && v[index] < v[index * 2 + 2]) flag = 0;
        if(flag == -1 && v[index] > v[index * 2 + 2]) flag = 0;
        dfs(index * 2 + 1);
        if(flag == 1 && v[index] < v[index * 2 + 1]) flag = 0;
        if(flag == -1 && v[index] > v[index * 2 + 1]) flag = 0;
    } else if(index * 2 + 1 < n) {
        dfs(index * 2 + 1);
        if(flag == 1 && v[index] < v[index * 2 + 1]) flag = 0;
        if(flag == -1 && v[index] > v[index * 2 + 1]) flag = 0;
    } else {
        show(ans);
        ans.pop_back();
        return;
    }
    ans.pop_back();
}
int main() {
    scanf("%d", &n);
    v.resize(n);
    for(int i = 0; i < n; i++) scanf("%d", &v[i]);
    for(int i = 0; i < n; i++) {
        if(v[0] != v[i]) {
            flag = v[0] > v[i] ? 1 : -1;
            break;
        }
    }
    dfs(0);
    if(flag == 0) printf("Not Heap\n");
    else printf("%s Heap\n", flag == 1? "Max" : "Min");
    return 0;
}