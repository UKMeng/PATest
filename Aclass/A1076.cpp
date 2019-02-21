#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int maxn = 1010;
int n, maxl;
struct node{
    int id, l;
};
vector<node> AVG[maxn];
int bfs(int sid) {
    int ans = 0;
    bool inq[maxn] = {false};
    node start;
    start.id = sid;
    start.l = 0;
    queue<node> q;
    q.push(start);
    inq[start.id] = true;
    while(!q.empty()) {
        node now = q.front();
        q.pop();
        cout << now.id << " " << now.l << endl;
        for(int i = 0; i < AVG[now.id].size(); i++) {
            node temp = AVG[now.id][i];
            temp.l = now.l + 1;
            if(temp.l > maxl) break;
            if(inq[temp.id] == false) {
                inq[temp.id] = true;
                ans++;
                q.push(temp);
            }
        }
    }
    return ans;
}
int main() {
    cin >> n >> maxl;
    for(int i = 1; i <= n; i++) {
        int fn;
        node user;
        user.id = i;
        cin >> fn;
        for(int j = 0; j < fn; j++) {
            int temp;
            cin >> temp;
            AVG[temp].push_back(user);
        }
    }
    int query;
    cin >> query;
    for(int i = 0; i < query; i++) {
        int qid, ans;
        cin >> qid;
        ans = bfs(qid);
        cout << ans << endl;
    }
    return 0;
}