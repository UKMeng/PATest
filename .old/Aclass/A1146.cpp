#include <iostream>
#include <vector>
using namespace std;
vector<int> graph[1010], degree(1010);
int main() {
    int nv, ne, u, v, query, flag = 0;
    scanf("%d %d", &nv, &ne);
    for(int i = 0; i < ne; i++) {
        scanf("%d %d", &u, &v);
        graph[u].push_back(v);
        degree[v]++;
    }
    scanf("%d", &query);
    for(int i = 0; i < query; i++) {
        int temp, isTopo = 1;
        vector<int> tde = degree;
        for(int j = 0; j < nv; j++) {
            scanf("%d", &temp);
            if(tde[temp] != 0) {
                isTopo = 0;
            } else {
                for(int l = 0; l < graph[temp].size(); l++) {
                    tde[graph[temp][l]]--; 
                }
            }
        }
        if(isTopo == 0) {
            if(flag == 0) {
                flag = 1;
                cout << i;
            } else {cout << " " << i;}
        }
    }
    return 0;
}