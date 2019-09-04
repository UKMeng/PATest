#include <iostream> 
#include <vector>
#include <map>
using namespace std;
vector<vector<int> > v(10010);
vector<int> path, tempPath;
map<int, int> line;
int start, endd, minCnt, minTrancnt, visit[10000];
int getTcnt(vector<int> a) {
    int cnt = -1, preLine = 0;
    for(int i = 1; i < a.size(); i++) {
        if(line[a[i - 1] * 10000 + a[i]] != preLine) {
            cnt++;
            preLine = line[a[i - 1] * 10000 + a[i]];
        }
    }
    return cnt;
}
void dfs(int node, int cnt) {
    if(node == endd && (cnt < minCnt || (cnt == minCnt && getTcnt(tempPath) < minTrancnt))) {
        minCnt = cnt;
        minTrancnt = getTcnt(tempPath);
        path = tempPath;
    }
    if(node == endd) return;
    for(int i = 0; i < v[node].size(); i++) {
        if(visit[v[node][i]] == 0) {
            visit[v[node][i]] = 1;
            tempPath.push_back(v[node][i]);
            // cout << node <<  " " << v[node][i] << endl;
            dfs(v[node][i], cnt + 1);
            visit[v[node][i]] = 0;
            tempPath.pop_back();
        } 
    }
}
int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        int nst, pre;
        scanf("%d%d", &nst, &pre);
        for(int j = 1; j < nst; j++) {
            int temp;
            scanf("%d", &temp);
            v[pre].push_back(temp);
            v[temp].push_back(pre);
            line[pre * 10000 + temp] = line[temp * 10000 + pre] = i + 1;
            pre = temp;
        }
    }
    int k;
    scanf("%d", &k);
    for(int i = 0; i < k; i++) {
        scanf("%d%d", &start, &endd);
        tempPath.clear();
        tempPath.push_back(start);
        minCnt = 99999, minTrancnt = 99999;
        visit[start] = 1;
        dfs(start, 0);
        visit[start] = 0;
        printf("%d\n", minCnt);
        int preline = 0, pretranst = start;
        for(int j = 1; j < path.size(); j++) {
            if(line[path[j - 1] * 10000 + path[j]] != preline) {
                if(preline != 0) printf("Take Line#%d from %04d to %04d.\n", preline, pretranst, path[j - 1]);
                preline = line[path[j - 1] * 10000 + path[j]];
                pretranst = path[j - 1];
            }
        }
        printf("Take Line#%d from %04d to %04d.\n", preline, pretranst, endd);
    }
    return 0;
}