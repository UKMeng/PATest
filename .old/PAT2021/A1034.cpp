#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

unordered_map<string, int> id;
unordered_map<int, string> name;
int in[2010], out[2010];
vector<int> f, r;

int find(int x){
    return f[x] == x? x : f[x] = find(f[x]);
}

void union_set(int x, int y){
    int fx = find(x), fy = find(y);
    if(fx == fy) return;
    if(r[fx] < r[fy]){
        swap(fx, fy);
    }
    r[fx] += r[fy];
    f[fy] = fx;
}

bool cmp(pair<int, int> a, pair<int, int> b){
    return name[a.first] < name[b.first];
}

int main(){
    int n, k;
    cin >> n >> k;
    int id_count = 1;
    r.resize(9999, 1);
    f.resize(9999);
    for(int i = 0; i < 9999; i++){
        f[i] = i;
    }
    for(int i = 0 ; i < n; i++){
        string a, b;
        int w;
        int ida, idb;
        cin >> a >> b >> w;
        if(id[a] == 0) {
            id[a] = id_count;
            name[id_count] = a;
            id_count += 1;
        }
        if(id[b] == 0){
            id[b] = id_count;
            name[id_count] = b;
            id_count += 1;
        }
        ida = id[a];
        idb = id[b];
        in[ida] += w;
        out[idb] += w;
        union_set(ida, idb);
    }
    unordered_set<int> fa;
    for(int i = 1; i < id_count; i++){
        fa.insert(find(i));
    }
    vector<pair<int, int>> ans;
    for(int fi: fa){
        int maxid = fi;
        int maxtime = 0;
        int num = 0;
        int time = 0;
        for(int i = 1; i < id_count; i++){
            if(find(i) == fi){
                //cout << i << endl;
                //cout << name[i] << " " << in[i] << endl;
                num++;
                time += in[i];
                if(maxtime < in[i] + out[i]){
                    maxid = i;
                    maxtime = in[i] + out[i];
                }
            }
        }
        //cout << fi << " " << maxid << " " << maxtime << endl;
        if(num > 2 && time > k){
            ans.push_back(make_pair(maxid, num));
        }
    }
    cout << ans.size() << endl;
    if(ans.size() != 0){
        sort(ans.begin(), ans.end(), cmp);
        for(int i = 0; i < ans.size(); i++){
            cout << name[ans[i].first] << " " << ans[i].second << endl;
        }
    }
    return 0;
}