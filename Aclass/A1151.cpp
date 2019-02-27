#include <iostream> 
#include <vector>
#include <map>
using namespace std;
map<int, int> mp;
vector<int> pre, in;
int main() {
    int m, n;
    cin >> m >> n;
    pre.resize(n);
    in.resize(n);
    for(int i = 0; i < n; i++) {
        cin >> in[i];
        mp[in[i]] = i;
    }
    for(int i = 0; i < n; i++) cin >> pre[i];
    for(int i = 0; i < m; i++) {
        int u, v;
        bool f1 = true, f2 = true;
        cin >> u >> v;
        if(mp.find(u) == mp.end()) f1 = false;
        if(mp.find(v) == mp.end()) f2 = false;
        if(!f1 || !f2) {
            if(!f1 && f2) cout << "ERROR: " << u << " is not found." << endl;
            if(!f2 && f1) cout << "ERROR: " << v << " is not found." << endl;
            if(!f1 && !f2) cout << "ERROR: " << u << " and " << v << " are not found." << endl;
            continue;
        }
        int fa = mp[u], fb = mp[v];
        for(int i = 0; i < n; i++) {
            int fc = mp[pre[i]];
            if((fa < fc && fb > fc) || (fa > fc && fb < fc)) {
                cout << "LCA of " << u << " and " << v << " is " << pre[i] << "." << endl; break;
            } else if(fa == fc) {
                cout << u << " is an ancestor of " << v << "." << endl;
                break;
            } else if(fb == fc) {
                cout << v << " is an ancestor of " << u << "." << endl;
                break;
            }
        }
    }
    return 0;
}