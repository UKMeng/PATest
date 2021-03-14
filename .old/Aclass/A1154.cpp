#include <iostream>
#include <vector>
#include <set>
using namespace std;
struct node {
    int v1, v2;
};
int main() {
    int n, m, k;
    cin >> n >> m;
    vector<node> edge(m);
    for(int i = 0; i < m; i++) {
        cin >> edge[i].v1 >> edge[i].v2;
    }
    cin >> k;
    for(int i = 0; i < k; i++) {
        int temp[100010];
        set<int> cnt;
        bool flag = true;
        for(int j = 0; j < n; j++) {
            int t;
            cin >> t;
            cnt.insert(t);
            temp[j] = t;
        }
        for(int j = 0; j < m; j++) {
            if(temp[edge[j].v1] == temp[edge[j].v2]) {
                cout << "No" << endl;
                flag = false;
                break;
            } 
        } if(flag) cout << cnt.size() << "-coloring" << endl;
    }
    return 0;
}