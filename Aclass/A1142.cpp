#include <iostream>
#include <vector>
using namespace std;
int e[210][210];
int main() {
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        e[a][b] = e[b][a] = 1;
    }
    int k;
    cin >> k;
    for(int i = 0; i < k; i++) {
        int nn;
        cin >> nn;
        vector<int> v(nn);
        int isClique = 1, isMax = 1, Hash[210] = {0};
        for(int j = 0; j < nn; j++) {
            cin >> v[j];
            Hash[v[j]] = 1;
        }
        for(int j = 0; j < nn; j++) {
            if(isClique == 0) break;
            for(int l = j + 1; l < nn; l++) {
                if(e[v[j]][v[l]] == 0) {
                    cout << "Not a Clique" << endl;
                    isClique = 0;
                    break;
                }
            }
        }
        if(isClique == 0) continue;
        for(int j = 1; j <= n; j++) {
            if(Hash[j] == 0) {
                for(int l = 0; l < nn; l++) {
                    if(e[j][v[l]] == 0) break;
                    if(l == nn - 1) isMax = 0;
                }
            }
            if(isMax == 0){
                cout << "Not Maximal" << endl;
                break;
            }
        }
        if(isMax == 1) cout << "Yes" << endl;
    }
    return 0;
}