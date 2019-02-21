#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
const int maxn = 2010;
struct node {
    int numMember;
    string head;
    node(string _head, int _numMember) : head(_head), numMember(_numMember) {}
};
int G[maxn][maxn], w[maxn], n, k, nm = 0;
bool ist[maxn];
map<string, int> nameid;
map<int, string> idname;
vector<node> ans;
int get_id(string s) {
    int temp;
    if(nameid.find(s) == nameid.end()) {
        nameid[s] = nm;
        temp = nm;
        idname[nm++] = s;
    }
    else temp = nameid[s];
    return temp;
}
void dfs(int nowid, int &head, int &numMember, int &totalw) {
    numMember++;
    ist[nowid] = true;
    if(w[nowid] > w[head]) head = nowid;
    for(auto it = idname.begin(); it != idname.end(); it++) {
        int cid = it -> first;
        if(G[nowid][cid] > 0) {
            totalw += G[nowid][cid];
            G[nowid][cid] = G[cid][nowid] = 0;
            if(ist[cid] == false) dfs(cid, head, numMember, totalw);
        }
    }
}
void dfstravel() {
    for(auto it = idname.begin(); it != idname.end(); it++) {
        int id = it -> first;
        if(ist[id] == false) {
            int head = id, numMember = 0, totalw = 0;
            dfs(id, head, numMember, totalw);
            if(numMember > 2 && totalw > k) ans.push_back(node(idname[head], numMember));
        }
    }
}
bool cmp(node a, node b) {return a.head < b.head;}
int main() {
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        string name1, name2;
        int ti, id1, id2;
        cin >> name1 >> name2 >> ti;
        id1 = get_id(name1);
        id2 = get_id(name2);
        G[id1][id2] += ti;
        G[id2][id1] += ti;
        w[id1] += ti;
        w[id2] += ti;
    }
    dfstravel();
    cout << ans.size() << endl;
    sort(ans.begin(), ans.end(), cmp);
    for(int i = 0; i < ans.size(); i++) cout << ans[i].head << " " << ans[i].numMember << endl;
    return 0;
}