#include <iostream> // LCA
#include <vector>
#include <map>
using namespace std;
map<int, int> mapp;
vector<int> pre, in;
int main() {
    int k, n;
    cin >> k >> n;
    pre.resize(n);
    in.resize(n);
    for(int i = 0; i < n; i++) {
        cin >> in[i];
        mapp[in[i]] = i;
    } for(int i = 0; i < n; i++) cin >> pre[i];
    while(k--) {
        int u, v;
        bool f1 = true, f2 = true;
        cin >> u >> v;
        if(mapp[u] == 0 && u != in[0]) f1 = false;
        if(mapp[v] == 0 && v != in[0]) f2 = false;
        if(!f1 || !f2) {
            if(!f1 && f2) cout << "ERROR: " << u << " is not found." << endl;
            if(!f2 && f1) cout << "ERROR: " << v << " is not found." << endl;
            if(!f1 && !f2) cout << "ERROR: " << u << " and " << v << " are not found." << endl;
            continue;
        }
        int uu = mapp[u], vv = mapp[v];
        for(int i = 0; i < n; i++) {
            int a = mapp[pre[i]];
            if((a > uu && a < vv) || (a < uu && a > vv)) {
                 cout << "LCA of " << u << " and " << v << " is " << pre[i] << "." << endl; break;
            } else if(a == uu) {
                cout << u << " is an ancestor of " << v << "." << endl;
                break;
            } else if(a == vv) {
                cout << v << " is an ancestor of " << u << "." << endl;
                break;
            }
        }
    }
    return 0;
}