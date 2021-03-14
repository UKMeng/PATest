#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
map<string, int> m;
map<int, int> happy;
map<int, string> id;
int num_city, num_road;
const int maxn = 210;
const int INF = 0x7fffffff;
int citycount = 0, G[maxn][maxn];
void getid(string city){
    m[city] = citycount;
    id[citycount] = city;
    citycount += 1;
}
int max_h = 0, min_cost = INF, ans_num = 0;
bool vis[maxn];
vector<int> ans;
vector<int> temp_road;
void dfs(int s, int temp_cost, int temp_h){
    if(s == m["ROM"]) {        
        if(temp_cost < min_cost){
            min_cost = temp_cost;
            ans_num = 1;
            max_h = temp_h;
            ans = temp_road;
        } else if(temp_cost == min_cost){
            ans_num += 1;
            if(temp_h > max_h){
                max_h = temp_h;
                ans = temp_road;
            } else if(temp_h == max_h && ans.size() > temp_road.size()){
                max_h = temp_h;
                ans = temp_road;
            }
        } 
        return;
    }
    for(int i = 0; i < num_city; i++){
        if(vis[i] == false && G[s][i] != INF){
            vis[i] = true;
            temp_road.push_back(i);
            dfs(i, temp_cost +G[s][i], temp_h + happy[i]);
            temp_road.pop_back();
            vis[i] = false;
        }
    }
}
int main(){
    string start;
    cin >> num_city >> num_road >> start;
    getid(start);
    for(int i = 0; i < num_city - 1; i++){
        string tempcity;
        int temph;
        cin >> tempcity >> temph;
        getid(tempcity);
        happy[m[tempcity]] = temph; 
    }
    for(int i = 0; i < maxn; i++){
        for(int j = 0; j < maxn; j++){
            G[i][j] = INF;
        }
    }
    for(int i = 0; i < maxn; i++){
        vis[i] = false;
    }
    vis[0] = true;
    for(int i = 0; i < num_road; i++){
        string a, b;
        int cost;
        cin >> a >> b >> cost;
        G[m[a]][m[b]] = cost;
        G[m[b]][m[a]] = cost;
    }
    dfs(m[start], 0, 0);
    cout << ans_num << " " << min_cost << " " << max_h << " " << max_h / ans.size() << endl;
    cout << start;
    for(int i = 0; i < ans.size(); i++){
        cout << "->" << id[ans[i]];
    }
    return 0;
}