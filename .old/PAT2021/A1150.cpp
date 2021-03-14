#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int G[210][210];

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++){
        int a, b, d;
        scanf("%d %d %d", &a, &b, &d);
        G[a][b] = d;
        G[b][a] = d;
    }
    int k;
    scanf("%d", &k);
    int ansid = 0;
    int min_dis = 0x3f3f3f3f;
    for(int i = 1; i <= k; i++){
        
        int l;
        scanf("%d", &l);
        
        vector<int> path(l);
        unordered_map<int, bool> visit;
        int visited = 1;
        bool flag = true;
        bool tong = true;
        for(int j = 0; j < l; j++){
            scanf("%d", &path[j]);
        }
        cout << "Path " << i << ": ";
        if(l == 0) {
            cout << "NA (Not a TS cycle)" << endl; 
            continue;
        }
        visit[path[0]] = true;
        int dis = 0;
        for(int j = 1; j < l; j++){
            // if(path[j] == path[j-1]) 暂时先不考虑这个
            int a = path[j-1], b = path[j];
            if(!visit[b]){
                visited += 1;
                visit[b] = true;
            } else{
                if(b == path[0] && j == l-1) flag = flag && true;
                else flag = false;
            }
            if(G[a][b] == 0){
                tong = false;
                break;
            } else{
                dis += G[a][b];
            }
        }
        if(!tong){
            cout << "NA (Not a TS cycle)" << endl; 
            continue;
        } else{
            if(dis < min_dis && visited == n && path[0] == path[l-1]){
                min_dis = dis;
                ansid = i;
            }
            cout << dis;
            if(flag && path[0] == path[l-1] && visited == n){
                cout << " (TS simple cycle)" << endl;
            } else if(!flag && path[0] == path[l-1] && visited == n){
                cout << " (TS cycle)" << endl;
            } else if(path[0] != path[l-1] || visited != n){
                cout << " (Not a TS cycle)" << endl; 
            }
        }
    }
    cout << "Shortest Dist(" << ansid << ") = " << min_dis << endl;
    return 0;
}