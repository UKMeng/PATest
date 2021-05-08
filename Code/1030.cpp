#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> road;
int n, m, s, d;
int Dis[510][510], Cost[510][510];
int visit[510];
vector<int> tempPath, path;
int tempDis = 0, ansDis = 0x3f3f3f3f, tempCost = 0, ansCost = 0x3f3f3f3f;

void dfs(int node){
    if(node == d){
        if(tempDis < ansDis){
            ansDis = tempDis;
            ansCost = tempCost;
            path = tempPath;
        } else if(tempDis == ansDis && tempCost < ansCost){
            ansCost = tempCost;
            path = tempPath;
        }
        return;
    }
    for(int i = 0; i < road[node].size(); i++){
        int next = road[node][i];
        if(visit[next] == 0){
            visit[next] = 1;
            tempPath.push_back(next);
            tempDis += Dis[node][next];
            tempCost += Cost[node][next];
            dfs(next);
            visit[next] = 0;
            tempPath.pop_back();
            tempDis -= Dis[node][next];
            tempCost -= Cost[node][next];
        }
    }
}

int main(){   
    cin >> n >> m >> s >> d;
    road.resize(n);
    for(int i = 0; i < m; i++){
        int c1, c2, dis, cost;
        cin >> c1 >> c2 >> dis >> cost;
        road[c1].push_back(c2);
        road[c2].push_back(c1);
        Dis[c1][c2] = Dis[c2][c1] = dis;
        Cost[c1][c2] = Cost[c2][c1] = cost;
    }
    visit[s] = 1;
    tempPath.push_back(s);
    dfs(s);
    for(int i = 0; i < path.size(); i++){
        cout << path[i] << " ";
    }
    cout << ansDis << " " << ansCost << endl;
    return 0;
}