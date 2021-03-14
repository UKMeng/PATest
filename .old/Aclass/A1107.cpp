#include <iostream> // 并查集
#include <algorithm>
#include <vector>
using namespace std;
const int maxn = 1010;
int father[maxn], hoppy[maxn], isRoot[maxn];
bool cmp(int a, int b) {return a > b;}
void init(int n) {
    for(int i = 0; i <= n; i++) father[i] = i;
}
int find(int x) {
    int a = x;
    while(x != father[x]) {
        x = father[x];
    }
    while(a != father[a]) {// 路径压缩
        int z = a;
        a = father[a];
        father[z] = x;
    }   
    return x;
}
void Union(int a, int b){
    int fa = find(a);
    int fb = find(b);
    if(fa != fb) father[fa] = fb;
}
int main() {
    int n;
    scanf("%d", &n);
    init(n);
    for(int i = 1; i <= n; i++) {
        int k; 
        scanf("%d: ", &k);
        for(int j = 0; j < k; j++) {
            int temp;
            cin >> temp;
            if(hoppy[temp] == 0) hoppy[temp] = i;
            Union(i, find(hoppy[temp]));
        }
    }
    int cnt = 0;
    for(int i = 1; i <= n; i++) isRoot[find(i)]++;
    for(int i = 1; i <= n; i++) {
        if(isRoot[i] != 0) cnt++;
    }
    sort(isRoot, isRoot + n + 1, cmp);
    cout << cnt << endl;
    for(int i = 0; i < cnt; i++) {
        if(i != 0) cout << " ";
        cout << isRoot[i];
    }
    return 0;
}